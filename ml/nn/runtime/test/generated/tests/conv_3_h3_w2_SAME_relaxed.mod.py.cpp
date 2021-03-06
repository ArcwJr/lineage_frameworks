// clang-format off
// Generated file (from: conv_3_h3_w2_SAME_relaxed.mod.py). Do not edit
#include "../../TestGenerated.h"

namespace conv_3_h3_w2_SAME_relaxed {
// Generated conv_3_h3_w2_SAME_relaxed test
#include "generated/examples/conv_3_h3_w2_SAME_relaxed.example.cpp"
// Generated model constructor
#include "generated/models/conv_3_h3_w2_SAME_relaxed.model.cpp"
} // namespace conv_3_h3_w2_SAME_relaxed

TEST_F(GeneratedTests, conv_3_h3_w2_SAME_relaxed) {
    execute(conv_3_h3_w2_SAME_relaxed::CreateModel,
            conv_3_h3_w2_SAME_relaxed::is_ignored,
            conv_3_h3_w2_SAME_relaxed::get_examples());
}

TEST_F(DynamicOutputShapeTest, conv_3_h3_w2_SAME_relaxed_dynamic_output_shape) {
    execute(conv_3_h3_w2_SAME_relaxed::CreateModel_dynamic_output_shape,
            conv_3_h3_w2_SAME_relaxed::is_ignored_dynamic_output_shape,
            conv_3_h3_w2_SAME_relaxed::get_examples_dynamic_output_shape());
}

TEST_F(GeneratedTests, conv_3_h3_w2_SAME_relaxed_2) {
    execute(conv_3_h3_w2_SAME_relaxed::CreateModel_2,
            conv_3_h3_w2_SAME_relaxed::is_ignored_2,
            conv_3_h3_w2_SAME_relaxed::get_examples_2());
}

TEST_F(DynamicOutputShapeTest, conv_3_h3_w2_SAME_relaxed_dynamic_output_shape_2) {
    execute(conv_3_h3_w2_SAME_relaxed::CreateModel_dynamic_output_shape_2,
            conv_3_h3_w2_SAME_relaxed::is_ignored_dynamic_output_shape_2,
            conv_3_h3_w2_SAME_relaxed::get_examples_dynamic_output_shape_2());
}

