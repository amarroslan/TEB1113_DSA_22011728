/*
id: 22011728
name: Muhammad Amar
group: g1
lab: L3
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

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList(Node *head = nullptr)
    { // Constructor takes Node* and initializes tail
        this->head = head;
        this->tail = head;
        if (head)
            head->next_ptr = nullptr;
    }

    void add_element(Node *node)
    {
        if (!node)
            return; // Check for null pointer

        node->next_ptr = nullptr; // Set new node's next to nullptr

        if (!head)
        { // If list is empty
            head = node;
            tail = node;
        }
        else
        {
            tail->next_ptr = node; // Link current tail to new node
            tail = node;           // Update tail to new node
        }
    }

    void display_list()
    {
        Node *current = head;
        if (!current)
        {
            cout << "List is empty" << endl;
            return;
        }
        while (current != nullptr)
        {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "nullptr" << endl;
    }

    void delete_by_value(string val)
    {
        if (!head)
            return; // Empty list

        // Special case: deleting head
        if (head->name == val)
        {
            Node *temp = head;
            head = head->next_ptr;
            delete temp;
            if (!head)
                tail = nullptr; // Update tail if list becomes empty
            return;
        }

        Node *current = head;
        while (current->next_ptr && current->next_ptr->name != val)
        {
            current = current->next_ptr;
        }

        if (current->next_ptr)
        { // If value found
            Node *temp = current->next_ptr;
            current->next_ptr = temp->next_ptr;
            if (temp == tail)
                tail = current; // Update tail if deleting last node
            delete temp;
        }
    }
};

int main()
{
    // Create nodes dynamically
    Node *node1 = new Node("Ali");
    Node *node2 = new Node("Ahmed");
    Node *node3 = new Node("Alee");

    // Create linked list and add nodes
    LinkedList linkedlst(node1);
    linkedlst.add_element(node2);
    linkedlst.add_element(node3);

    // Display the list
    linkedlst.display_list();

    // Example of deletion
    linkedlst.delete_by_value("Ahmed");
    cout << "After deleting Ahmed: ";
    linkedlst.display_list();

    return 0;
}