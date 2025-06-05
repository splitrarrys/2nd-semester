#include <gtest/gtest.h>
#include "DynamicArray.h"

TEST(DynamicArrayTest, DefaultConstructor) {
    DynamicArray arr;
    EXPECT_TRUE(arr.is_empty());
    EXPECT_EQ(arr.get_size(), 0);
}

TEST(DynamicArrayTest, InitializerListConstructor) {
    DynamicArray arr{1, 2, 3, 4, 5};
    EXPECT_FALSE(arr.is_empty());
    EXPECT_EQ(arr.get_size(), 5);
    EXPECT_EQ(arr.at(0), 1);
    EXPECT_EQ(arr.at(4), 5);
}

TEST(DynamicArrayTest, CopyConstructor) {
    DynamicArray arr1{1, 2, 3};
    DynamicArray arr2(arr1);
    EXPECT_EQ(arr1.get_size(), arr2.get_size());
    EXPECT_EQ(arr1.at(1), arr2.at(1));
}

TEST(DynamicArrayTest, MoveConstructor) {
    DynamicArray arr1{1, 2, 3};
    DynamicArray arr2(std::move(arr1));
    EXPECT_EQ(arr2.get_size(), 3);
    EXPECT_TRUE(arr1.is_empty());
}

TEST(DynamicArrayTest, PushBack) {
    DynamicArray arr;
    arr.push_back(10);
    arr.push_back(20);
    EXPECT_EQ(arr.get_size(), 2);
    EXPECT_EQ(arr.at(1), 20);
}

TEST(DynamicArrayTest, ShiftOperators) {
    DynamicArray arr{1, 2, 3, 4, 5};
    DynamicArray left = arr << 2;
    EXPECT_EQ(left.at(0), 3);
    
    DynamicArray right = arr >> 1;
    EXPECT_EQ(right.at(0), 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}