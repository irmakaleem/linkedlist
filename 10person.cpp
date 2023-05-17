#include <iostream>

using namespace std;

struct Node
{
    string name;
    int age;
    int salary;
    Node *next;
};

Node *head = NULL;

void insert(string name, int age, int salary)
{
    Node *newNode = new Node();
    newNode->name = name;
    newNode->age = age;
    newNode->salary = salary;
    newNode->next = head;
    head = newNode;
}

void printList()
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->name << " " << current->age << " " << current->salary << endl;
        current = current->next;
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        string name;
        int age;
        int salary;
        cout << "Enter name, age, and salary: ";
        cin >> name >> age >> salary;
        insert(name, age, salary);
    }

    printList();

    return 0;
}
