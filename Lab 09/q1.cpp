#include <iostream>
using namespace std;

class Stack {
    string books[5];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() { return top == 4; }
    bool isEmpty() { return top == -1; }

    void push(string bookTitle) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
        } else {
            books[++top] = bookTitle;
            cout << "Book added: " << bookTitle << "\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! No books to remove.\n";
        

        } else {
            cout << "Book removed: " << books[top] << "\n";
            top--;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";


        } else {
            cout << "Last purchased book: " << books[top] << "\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No books in purchase history.\n";        

        } else {
            cout << "Purchase history (newest to oldest):\n";
            for (int i = top; i >= 0; i--) {
                cout << books[i] << "\n";
            }
        }
    }
};

int main() {
    Stack s;
    s.push("Book A");
    s.push("Book B");
    s.push("Book C");
    s.push("Book D");
    s.push("Book E");
    s.push("Book F");
    s.display();
    s.pop();
    s.peek();
    s.display();
    return 0;
}
