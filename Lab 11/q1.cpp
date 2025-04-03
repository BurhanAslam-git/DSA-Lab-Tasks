#include <iostream>
using namespace std;

// Book Structure.
struct Book
{
    int isbn;
    string title, author;
    Book *left;
    Book *right;
    Book(int i, string t, string a)
    {
        isbn = i;
        title = t;
        author = a;
        left = right = nullptr;
    }
};

class BSTLibrary
{
public:
    Book *root;
    BSTLibrary() { root = nullptr; }
    Book *insert(Book *node, int isbn, string title, string author)
    {
        if (!node)
            return new Book(isbn, title, author);
        if (isbn < node->isbn)
            node->left = insert(node->left, isbn, title, author);
        else
            node->right = insert(node->right, isbn, title, author);
        return node;
    }
    void inorder(Book *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->isbn << ": " << node->title << " by " << node->author << endl;
        inorder(node->right);
    }
    void preorder(Book *node)
    {
        if (!node)
            return;
        cout << node->isbn << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Book *node)
    {
        if (!node)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->isbn << " ";
    }
};

int main()
{
    BSTLibrary bst;
    bst.root = bst.insert(bst.root, 123, "The Great Gatsby", "F. Scott Fitzgerald");
    bst.insert(bst.root, 456, "1984", "George Orwell");
    bst.insert(bst.root, 789, "To Kill a Mockingbird", "Harper Lee");
    bst.insert(bst.root, 321, "Pride and Prejudice", "Jane Austen");
    bst.insert(bst.root, 654, "The Catcher in the Rye", "J.D. Salinger");

    cout << "Inorder Traversal:" << endl;
    bst.inorder(bst.root);
    cout << "\nPreorder Traversal:" << endl;
    bst.preorder(bst.root);
    cout << "\nPostorder Traversal:" << endl;
    bst.postorder(bst.root);
    return 0;
}