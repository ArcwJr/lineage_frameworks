/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.systemui.statusbar.notification.row;

import android.app.ActivityManager;
import android.app.Notification;
import android.content.Context;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Bundle;
import android.os.Parcelable;
import android.util.Log;

import com.android.internal.widget.ImageResolver;
import com.android.internal.widget.LocalImageResolver;
import com.android.internal.widget.MessagingMessage;

import java.io.IOException;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Custom resolver with built-in image cache for image messages.
 */
public class NotificationInlineImageResolver implements ImageResolver {
    private static final String TAG = NotificationInlineImageResolver.class.getSimpleName();

    private final Context mContext;
    private final ImageCache mImageCache;
    private Set<Uri> mWantedUriSet;

    /**
     * Constructor.
     * @param context    Context.
     * @param imageCache The implementation of internal cache.
     */
    public NotificationInlineImageResolver(Context context, ImageCache imageCache) {
        mContext = context.getApplicationContext();
        mImageCache = imageCache;

        if (mImageCache != null) {
            mImageCache.setImageResolver(this);
        }
    }

    /**
     * Check if this resolver has its internal cache implementation.
     * @return True if has its internal cache, false otherwise.
     */
    public boolean hasCache() {
        return mImageCache != null && !ActivityManager.isLowRamDeviceStatic();
    }

    /**
     * To resolve image from specified uri directly.
     * @param uri Uri of the image.
     * @return Drawable of the image.
     * @throws IOException Throws if failed at resolving the image.
     */
    Drawable resolveImage(Uri uri) throws IOException {
        return LocalImageResolver.resolveImage(uri, mContext);
    }

    @Override
    public Drawable loadImage(Uri uri) {
        Drawable result = null;
        try {
            result = hasCache() ? mImageCache.get(uri) : resolveImage(uri);
        } catch (IOException | SecurityException ex) {
            Log.d(TAG, "loadImage: Can't load image from " + uri, ex);
        }
        return result;
    }

    /**
     * Resolve the message list from specified notification and
     * refresh internal cache according to the result.
     * @param notification The Notification to be resolved.
     */
    public void preloadImages(Notification notification) {
        if (!hasCache()) {
            return;
        }

        retrieveWantedUriSet(notification);
        Set<Uri> wantedSet = getWantedUriSet();
        wantedSet.forEach(uri -> {
            if (!mImageCache.hasEntry(uri)) {
                // The uri is not in the cache, we need trigger a loading task for it.
                mImageCache.preload(uri);
            }
        });
    }

    /**
     * Try to purge unnecessary cache entries.
     */
    public void purgeCache() {
        if (!hasCache()) {
            return;
        }
        mImageCache.purge();
    }

    private void retrieveWantedUriSet(Notification notification) {
        Parcelable[] messages;
        Parcelable[] historicMessages;
        List<Notification.MessagingStyle.Message> messageList;
        List<Notification.MessagingStyle.Message> historicList;
        Set<Uri> result = new HashSet<>();

        Bundle extras = notification.extras;
        if (extras == null) {
            return;
        }

        messages = extras.getParcelableArray(Notification.EXTRA_MESSAGES);
        messageList = messages == null ? null :
                Notification.MessagingStyle.Message.getMessagesFromBundleArray(messages);
        if (messageList != null) {
            for (Notification.MessagingStyle.Message message : messageList) {
                if (MessagingMessage.hasImage(message)) {
                    result.add(message.getDataUri());
                }
            }
        }

        historicMessages = extras.getParcelableArray(Notification.EXTRA_HISTORIC_MESSAGES);
        historicList = historicMessages == null ? null :
                Notification.MessagingStyle.Message.getMessagesFromBundleArray(historicMessages);
        if (historicList != null) {
            for (Notification.MessagingStyle.Message historic : historicList) {
                if (MessagingMessage.hasImage(historic)) {
                    result.add(historic.getDataUri());
                }
            }
        }

        mWantedUriSet = result;
    }

    Set<Uri> getWantedUriSet() {
        return mWantedUriSet;
    }

    /**
     * A interface for internal cache implementation of this resolver.
     */
    interface ImageCache {
        /**
         * Load the image from cache first then resolve from uri if missed the cache.
         * @param uri The uri of the image.
         * @return Drawable of the image.
         */
        Drawable get(Uri uri);

        /**
         * Set the image resolver that actually resolves image from specified uri.
         * @param resolver The resolver implementation that resolves image from specified uri.
         */
        void setImageResolver(NotificationInlineImageResolver resolver);

        /**
         * Check if the uri is in the cache no matter it is loading or loaded.
         * @param uri The uri to check.
         * @return True if it is already in the cache; false otherwise.
         */
        boolean hasEntry(Uri uri);

        /**
         * Start a new loading task for the target uri.
         * @param uri The target to load.
         */
        void preload(Uri uri);

        /**
         * Purge unnecessary entries in the cache.
         */
        void purge();
    }

}
