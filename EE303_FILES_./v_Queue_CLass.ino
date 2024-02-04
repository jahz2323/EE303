#include <Energia.h>

template <typename T, int SIZE>
class Queue {
private:
  T elements[SIZE];
  int front, rear;

public:
  Queue() : front(-1), rear(-1) {}

  bool isEmpty() {
    return front == -1;
  }

  bool isFull() {
    return (rear + 1) % SIZE == front;
  }

  void enqueue(const T& item) {
    if (isFull()) {
      Serial.println("Queue is full. Cannot enqueue.");
      return;
    }

    if (isEmpty()) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % SIZE;
    }

    elements[rear] = item;
  }

  T dequeue() {
    if (isEmpty()) {
      Serial.println("Queue is empty. Cannot dequeue.");
      return T(); // Return a default-constructed value for the type T
    }

    T item = elements[front];

    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % SIZE;
    }

    return item;
  }

  T peek() {
    if (isEmpty()) {
      Serial.println("Queue is empty. Cannot peek.");
      return T(); // Return a default-constructed value for the type T
    }

    return elements[front];
  }
};

void setup() {
  Serial.begin(9600);

//  Queue<int, 5> myQueue;

//  // Enqueue elements
//  myQueue.enqueue(1);
//  myQueue.enqueue(2);
//  myQueue.enqueue(3);
//
//  // Dequeue and print elements
//  Serial.println(myQueue.dequeue()); // Should print 1
//  Serial.println(myQueue.dequeue()); // Should print 2
//
//  // Enqueue more elements
//  myQueue.enqueue(4);
//  myQueue.enqueue(5);
//
//  // Peek at the front element
//  Serial.println(myQueue.peek()); // Should print 3
}

void loop() {
  // Your main code here
}
