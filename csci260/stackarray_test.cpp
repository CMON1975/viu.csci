#include <gtest/gtest.h>
#include "StackArray.h" // Include your stack implementation

// Test case for push and pop functionality
TEST(StackArrayTest, PushPopTest)
{
    StackArray stack(5);
    stack.push(10);
    stack.push(20);
    EXPECT_EQ(stack.pop(), 20); // Assert that popping returns 20
    EXPECT_EQ(stack.pop(), 10); // Assert that the next pop returns 10
}

// Test case for stack overflow
TEST(StackArrayTest, OverflowTest)
{
    StackArray stack(3);
    stack.push(100);
    stack.push(200);
    stack.push(300);
    stack.push(400);             // Should trigger an overflow, but we don't assert it here
    EXPECT_TRUE(stack.isFull()); // Check if stack is full
}

// Test case for stack underflow
TEST(StackArrayTest, UnderflowTest)
{
    StackArray stack(3);
    EXPECT_EQ(stack.pop(), 0); // Pop from an empty stack should return 0
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // Run all tests
}
