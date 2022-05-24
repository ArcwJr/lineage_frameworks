/*
 * Copyright (C) 2017 The Android Open Source Project
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

#include "shared.rsh"

int pattern;

rs_allocation aFailed;

// This test checks to see that we only work on the cells specified for the
// input allocation (i.e. don't affect anything between dimX and stride for
// each row). If we don't see the pattern that we wrote, we know that we
// are definitely working outside our proper bounds.
void root(const int *o, uint32_t x, uint32_t y) {
    if (*o != pattern) {
        rsSetElementAt_uchar(aFailed, 1, 0);
    }
}

void check_dims_test() {
    bool failed = rsGetElementAt_uchar(aFailed, 0);
    if (failed) {
        rsSendToClientBlocking(RS_MSG_TEST_FAILED);
    }
    else {
        rsSendToClientBlocking(RS_MSG_TEST_PASSED);
    }
}

