#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void insertAtEnd(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertAtBeginning(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void traverseList()
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    Node *temp = current->next;
    current->next = NULL;
    delete temp;
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteAtPosition(int position)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (position == 1)
    {
        deleteFromBeginning();
        return;
    }

    Node *current = head;
    for (int i = 1; i < position - 1; i++)
    {
        current = current->next;
    }

    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
}

void search(int data)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *current = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            cout << "Data found at position " << current->data << endl;
            return;
        }
        current = current->next;
    }

    cout << "Data not found" << endl;
}

void displayList()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    cout << "List: ";
    traverseList();
}

int main()
{
    int choice;

    while (true)
    {
        cout << "-------------------------------------------------" << endl;
        cout << "Linked List implementation of LIST ADT" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "1. Insert an element at the end" << endl;
        cout << "2. Insert an element at the beginning" << endl;
        cout << "3. Traverse the Linked list" << endl;
        cout << "4. Delete an element from end" << endl;
        cout << "5. Delete an element at the beginning" << endl;
        cout << "6. Delete an element at any position" << endl;
        cout << "7. Search an element" << endl;
        cout << "8. Display List" << endl;
        cout << "9. Exit" << endl;
        cout << "Please Enter Your Choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the data to insert at the end: ";
            cin >> data;
            insertAtEnd(data);
            break;

        case 2:
            // int data;
            cout << "Enter the data to insert at the beginning: ";
            cin >> data;
            insertAtBeginning(data);
            break;

        case 3:
            traverseList();
            break;

        case 4:
            deleteFromEnd();
            break;

        case 5:
            deleteFromBeginning();
            break;

        case 6:
            int position;
            cout << "Enter the position of the element to delete: ";
            cin >> position;
            deleteAtPosition(position);
            break;

        case 7:
            // int data;
            cout << "Enter the data to search for: ";
            cin >> data;
            search(data);
            break;

        case 8:
            displayList();
            break;

        case 9:
            return 0;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}