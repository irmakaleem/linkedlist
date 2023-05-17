#include <iostream>

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;
};

// Queue implementation using a linked list
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    // Constructor
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return (front == nullptr);
    }

    // Enqueue a new token number
    void enqueue(int token)
    {
        Node *newNode = new Node;
        newNode->data = token;
        newNode->next = nullptr;

        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue the next token number
    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Return a sentinel value indicating an error
        }

        Node *temp = front;
        int token = temp->data;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        return token;
    }
};

int main()
{
    Queue appointmentQueue;

    // Enqueue token numbers
    appointmentQueue.enqueue(1);
    appointmentQueue.enqueue(2);
    appointmentQueue.enqueue(3);
    appointmentQueue.enqueue(4);
    appointmentQueue.enqueue(5);

    // Dequeue and print token numbers until the queue is empty
    while (!appointmentQueue.isEmpty())
    {
        int token = appointmentQueue.dequeue();
        std::cout << "Token Number: " << token << std::endl;
    }

    return 0;
}
