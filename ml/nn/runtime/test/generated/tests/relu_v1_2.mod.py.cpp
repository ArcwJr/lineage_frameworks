// clang-format off
// Generated file (from: relu_v1_2.mod.py). Do not edit
#include "../../TestGenerated.h"

namespace relu_v1_2 {
// Generated relu_v1_2 test
#include "generated/examples/relu_v1_2.example.cpp"
// Generated model constructor
#include "generated/models/relu_v1_2.model.cpp"
} // namespace relu_v1_2

TEST_F(GeneratedTests, relu_v1_2) {
    execute(relu_v1_2::CreateModel,
            relu_v1_2::is_ignored,
            relu_v1_2::get_examples());
}
TEST_AVAILABLE_SINCE(V1_2, relu_v1_2, relu_v1_2::CreateModel)

TEST_F(DynamicOutputShapeTest, relu_v1_2_dynamic_output_shape) {
    execute(relu_v1_2::CreateModel_dynamic_output_shape,
            relu_v1_2::is_ignored_dynamic_output_shape,
            relu_v1_2::get_examples_dynamic_output_shape());
}

TEST_F(GeneratedTests, relu_v1_2_2) {
    execute(relu_v1_2::CreateModel_2,
            relu_v1_2::is_ignored_2,
            relu_v1_2::get_examples_2());
}
TEST_AVAILABLE_SINCE(V1_2, relu_v1_2_2, relu_v1_2::CreateModel_2)

TEST_F(DynamicOutputShapeTest, relu_v1_2_dynamic_output_shape_2) {
    execute(relu_v1_2::CreateModel_dynamic_output_shape_2,
            relu_v1_2::is_ignored_dynamic_output_shape_2,
            relu_v1_2::get_examples_dynamic_output_shape_2());
}

TEST_F(GeneratedTests, relu_v1_2_zero_sized) {
    execute(relu_v1_2::CreateModel_zero_sized,
            relu_v1_2::is_ignored_zero_sized,
            relu_v1_2::get_examples_zero_sized());
}
TEST_AVAILABLE_SINCE(V1_2, relu_v1_2_zero_sized, relu_v1_2::CreateModel_zero_sized)

TEST_F(GeneratedTests, relu_v1_2_zero_sized_relaxed) {
    execute(relu_v1_2::CreateModel_zero_sized_relaxed,
            relu_v1_2::is_ignored_zero_sized_relaxed,
            relu_v1_2::get_examples_zero_sized_relaxed());
}

TEST_F(GeneratedTests, relu_v1_2_zero_sized_quant8) {
    execute(relu_v1_2::CreateModel_zero_sized_quant8,
            relu_v1_2::is_ignored_zero_sized_quant8,
            relu_v1_2::get_examples_zero_sized_quant8());
}
TEST_AVAILABLE_SINCE(V1_2, relu_v1_2_zero_sized_quant8, relu_v1_2::CreateModel_zero_sized_quant8)

TEST_F(GeneratedTests, relu_v1_2_zero_sized_float16) {
    execute(relu_v1_2::CreateModel_zero_sized_float16,
            relu_v1_2::is_ignored_zero_sized_float16,
            relu_v1_2::get_examples_zero_sized_float16());
}
TEST_AVAILABLE_SINCE(V1_2, relu_v1_2_zero_sized_float16, relu_v1_2::CreateModel_zero_sized_float16)

TEST_F(DynamicOutputShapeTest, relu_v1_2_zero_sized_dynamic_output_shape) {
    execute(relu_v1_2::CreateModel_zero_sized_dynamic_output_shape,
            relu_v1_2::is_ignored_zero_sized_dynamic_output_shape,
            relu_v1_2::get_examples_zero_sized_dynamic_output_shape());
}

TEST_F(DynamicOutputShapeTest, relu_v1_2_zero_sized_dynamic_output_shape_relaxed) {
    execute(relu_v1_2::CreateModel_zero_sized_dynamic_output_shape_relaxed,
            relu_v1_2::is_ignored_zero_sized_dynamic_output_shape_relaxed,
            relu_v1_2::get_examples_zero_sized_dynamic_output_shape_relaxed());
}

TEST_F(DynamicOutputShapeTest, relu_v1_2_zero_sized_dynamic_output_shape_quant8) {
    execute(relu_v1_2::CreateModel_zero_sized_dynamic_output_shape_quant8,
            relu_v1_2::is_ignored_zero_sized_dynamic_output_shape_quant8,
            relu_v1_2::get_examples_zero_sized_dynamic_output_shape_quant8());
}

TEST_F(DynamicOutputShapeTest, relu_v1_2_zero_sized_dynamic_output_shape_float16) {
    execute(relu_v1_2::CreateModel_zero_sized_dynamic_output_shape_float16,
            relu_v1_2::is_ignored_zero_sized_dynamic_output_shape_float16,
            relu_v1_2::get_examples_zero_sized_dynamic_output_shape_float16());
}

