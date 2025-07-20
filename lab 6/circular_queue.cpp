/*
id: 22011728
name: Muhammad Amar
group: g1
lab: L6
*/

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    Node *next_ptr;

    Node(string name, Node *next_ptr = nullptr)
    { // Constructor with default nullptr
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue(Node *front = nullptr)
    { // Constructor takes Node* and initializes rear
        this->front = front;
        this->rear = front;
        if (front)
        {
            front->next_ptr = front; // Make it circular
        }
    }

    void enqueue(Node *node)
    {
        if (!node)
            return; // Check for null pointer

        node->next_ptr = nullptr; // Set new node's next to nullptr temporarily

        if (!front)
        { // If queue is empty
            front = node;
            rear = node;
            node->next_ptr = front; // Point to itself to form circular structure
        }
        else
        {
            rear->next_ptr = node;  // Link current rear to new node
            rear = node;            // Update rear to new node
            node->next_ptr = front; // Connect new rear to front to maintain circular structure
        }
    }

    void display_queue()
    {
        if (!front)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *current = front;
        do
        {
            cout << current->name << " <- ";
            current = current->next_ptr;
        } while (current != front); // Stop when we loop back to front
        cout << "(circular)" << endl;
    }

    void dequeue()
    {
        if (!front)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;
        if (front == rear)
        { // Only one node
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            front = front->next_ptr; // Move front to next node
            rear->next_ptr = front;  // Update rear's next to new front
        }
        cout << "Removing: " << temp->name << endl;
        delete temp;
    }
};

int main()
{
    // Create nodes dynamically
    Node *node1 = new Node("Ali");
    Node *node2 = new Node("Ahmed");
    Node *node3 = new Node("Alee");
    Node *node4 = new Node("Abu");

    // Create queue and add nodes
    Queue queue(node1);
    queue.enqueue(node2);
    queue.enqueue(node3);
    queue.enqueue(node4);

    // Display the queue
    queue.display_queue();

    // Example of deletion
    queue.dequeue();
    cout << "After Dequeue: ";
    queue.display_queue();

    return 0;
}