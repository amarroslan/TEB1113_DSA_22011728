/*
id: 22011728
name: Muhammad Amar
group: g1
lab: L5
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

class Stack
{
private:
    Node *top; // Only need top pointer for stack

public:
    Stack(Node *top = nullptr)
    { // Constructor initializes top
        this->top = top;
        if (top)
            top->next_ptr = nullptr;
    }

    void push(Node *node)
    {
        if (!node)
            return; // Check for null pointer

        node->next_ptr = top; // New node points to current top
        top = node;           // Update top to new node
    }

    void pop()
    {
        if (!top)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node *temp = top;
        top = top->next_ptr;
        delete temp;
    }

    string peek() const
    {
        if (!top)
        {
            cout << "Stack is empty" << endl;
            return "";
        }
        return top->name;
    }

    void display_stack()
    {
        Node *current = top;
        if (!current)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack: ";
        while (current != nullptr)
        {
            cout << current->name;
            current = current->next_ptr;
            if (current != nullptr)
                cout << " -> ";
        }
        cout << endl;
    }
};

int main()
{
    // Create nodes dynamically
    Node *node1 = new Node("Ali");
    Node *node2 = new Node("Ahmed");
    Node *node3 = new Node("Alee");

    // Create stack and push nodes
    Stack stack;
    stack.push(node1);
    stack.push(node2);
    stack.push(node3);

    // Display the stack
    stack.display_stack();

    // Example of peek operation
    cout << "Top element: " << stack.peek() << endl;
    cout << "Stack after peek: ";
    stack.display_stack();

    // Example of pop operation
    cout << "After popping top element: ";
    stack.pop();
    stack.display_stack();

    return 0;
}
