#include <gtest/gtest.h>
#include "Queue.h" // Include your Queue class

// Test case for enqueuing elements to the queue
TEST(QueueTest, EnqueueTest)
{
    Queue q(5); // Create a queue with capacity 5

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Check if the front element is 10 (the first enqueued element)
    EXPECT_EQ(q.peek(), 10);
}

// Test case for dequeuing elements from the queue
TEST(QueueTest, DequeueTest)
{
    Queue q(5);

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Dequeue elements
    q.dequeue();
    q.dequeue();

    // After dequeuing two elements, the front should be 30
    EXPECT_EQ(q.peek(), 30);

    // Dequeue the last element
    q.dequeue();

    // Now the queue should be empty
    EXPECT_ANY_THROW(q.peek()); // Assuming your Queue throws an exception when peeking at an empty queue
}

// Test case for queue overflow and underflow
TEST(QueueTest, OverflowUnderflowTest)
{
    Queue q(3); // Create a queue with capacity 3

    // Enqueue elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    // Try to enqueue one more element (should fail)
    EXPECT_ANY_THROW(q.enqueue(4)); // Assuming your Queue throws an exception when overflowing

    // Dequeue all elements
    q.dequeue();
    q.dequeue();
    q.dequeue();

    // Try to dequeue from an empty queue (should fail)
    EXPECT_ANY_THROW(q.dequeue()); // Assuming your Queue throws an exception when underflowing
}

// Test case for queue wrapping (circular behavior)
TEST(QueueTest, CircularEnqueueDequeueTest)
{
    Queue q(5);

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Dequeue elements to create space
    q.dequeue();
    q.dequeue();

    // Enqueue more elements to test wrapping behavior
    q.enqueue(40);
    q.enqueue(50);

    // The front element should be 30 now
    EXPECT_EQ(q.peek(), 30);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
