#include "StackList.h"
#include <gtest/gtest.h>
#include <stdexcept>

// Test to verify that pushing elements works correctly
TEST(StackListTest, PushTest)
{
    StackList stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    EXPECT_EQ(stack.peek(), 30); // The top element should be 30
}

// Test to verify that popping elements works correctly
TEST(StackListTest, PopTest)
{
    StackList stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.pop();
    EXPECT_EQ(stack.peek(), 20); // After one pop, the top element should be 20

    stack.pop();
    EXPECT_EQ(stack.peek(), 10); // After another pop, the top element should be 10
}

// Test to verify popping from an empty stack throws an exception
TEST(StackListTest, PopEmptyStack)
{
    StackList stack;
    EXPECT_THROW(stack.pop(), std::underflow_error); // Popping from an empty stack should throw
}

// Test to verify peeking from an empty stack throws an exception
TEST(StackListTest, PeekEmptyStack)
{
    StackList stack;
    EXPECT_THROW(stack.peek(), std::underflow_error); // Peeking at an empty stack should throw
}

// Test to verify that the stack is empty when initialized
TEST(StackListTest, IsEmptyInitially)
{
    StackList stack;
    EXPECT_TRUE(stack.isEmpty()); // The stack should be empty when initialized
}

// Test to verify that the stack is not empty after pushing an element
TEST(StackListTest, IsNotEmptyAfterPush)
{
    StackList stack;
    stack.push(10);
    EXPECT_FALSE(stack.isEmpty()); // The stack should not be empty after pushing an element
}

// Test to verify that the stack is empty after all elements are popped
TEST(StackListTest, IsEmptyAfterAllPops)
{
    StackList stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.pop();
    stack.pop();
    stack.pop();

    EXPECT_TRUE(stack.isEmpty()); // The stack should be empty after all elements are popped
}

// Test to verify that popping and peeking throw after the stack is empty
TEST(StackListTest, PopAndPeekAfterEmpty)
{
    StackList stack;
    stack.push(10);
    stack.push(20);
    stack.pop();
    stack.pop();

    EXPECT_THROW(stack.pop(), std::underflow_error);  // Popping should throw after the stack is empty
    EXPECT_THROW(stack.peek(), std::underflow_error); // Peeking should throw after the stack is empty
}
