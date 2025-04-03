#include <iostream>
#include <sstream>
using namespace std;

class Node {
public:
    string word;
    Node* next;
    Node(string w) { word = w; next = nullptr; }
};

class Stack {
    Node* top;

public:
    Stack() { top = nullptr; }

    bool isEmpty() { return top == nullptr; }

    void push(string word) {
        Node* newNode = new Node(word);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Stack underflow! No words to remove.\n";
            return "";
        }

        Node* temp = top;
        string poppedWord = temp->word;
        top = top->next;
        delete temp;
        return poppedWord;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Top word: " << top->word << "\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        } else {
            Node* temp = top;
            while (temp) {
                cout << temp->word << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};

int main() {
    Stack s;
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        s.push(word);
    }
    
    cout << "Reversed Sentence: ";
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << "\n";
    return 0;
}
