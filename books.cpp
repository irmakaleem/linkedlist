#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string title;
    string author;
    Book *next;
};

Book *top = NULL;

void push(string title, string author)
{
    Book *newBook = new Book;
    newBook->title = title;
    newBook->author = author;
    newBook->next = top;
    top = newBook;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Library is empty." << endl;
        return;
    }
    Book *temp = top;
    top = top->next;
    cout << "Removed book: " << temp->title << " by " << temp->author << endl;
    delete temp;
}

void display()
{
    if (top == NULL)
    {
        cout << "Library is empty." << endl;
        return;
    }
    cout << "Books in the library: " << endl;
    Book *current = top;
    while (current != NULL)
    {
        cout << current->title << " by " << current->author << endl;
        current = current->next;
    }
}

int main()
{
    push("Book 1", "Author 1");
    push("Book 2", "Author 2");
    push("Book 3", "Author 3");
    push("Book 4", "Author 4");
    push("Book 5", "Author 5");
    push("Book 6", "Author 6");
    push("Book 7", "Author 7");
    push("Book 8", "Author 8");
    push("Book 9", "Author 9");
    push("Book 10", "Author 10");

    display();

    pop();
    pop();
    pop();

    display();

    return 0;
}
