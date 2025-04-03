#include <iostream>
using namespace std;


// Employee Structure.
struct Employee
{
    int id, age;
    string name, department;
    char gender;
    float salary;
    Employee *left;
    Employee *right;
    Employee(int i, string n, int a, char g, string d, float s)
    {
        id = i;
        name = n;
        age = a;
        gender = g;
        department = d;
        salary = s;
        left = right = nullptr;
    }
};

class BSTEmployee
{
public:
    Employee *root;
    BSTEmployee() { root = nullptr; }
    Employee *insert(Employee *node, int id, string name, int age, char gender, string dept, float salary)
    {
        if (!node)
            return new Employee(id, name, age, gender, dept, salary);
        if (id < node->id)
            node->left = insert(node->left, id, name, age, gender, dept, salary);
        else
            node->right = insert(node->right, id, name, age, gender, dept, salary);
        return node;
    }
    Employee *search(Employee *node, int id)
    {
        if (!node || node->id == id)
            return node;
        if (id < node->id)
            return search(node->left, id);
        return search(node->right, id);
    }
    void inorder(Employee *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->id << " " << node->name << " " << node->age << " " << node->gender << " " << node->department << " " << node->salary << endl;
        inorder(node->right);
    }
    float avgSalary(Employee *node, int &count)
    {
        if (!node)
            return 0;
        count++;
        return node->salary + avgSalary(node->left, count) + avgSalary(node->right, count);
    }
    void genderCount(Employee *node, int &m, int &f)
    {
        if (!node)
            return;
        if (node->gender == 'M')
            m++;
        else
            f++;
        genderCount(node->left, m, f);
        genderCount(node->right, m, f);
    }
    int height(Employee *node)
    {
        if (!node)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};

int main()
{
    BSTEmployee bst;
    bst.root = bst.insert(bst.root, 101, "Alice", 30, 'F', "HR", 50000);
    bst.insert(bst.root, 102, "Bob", 28, 'M', "IT", 60000);
    bst.insert(bst.root, 103, "Charlie", 35, 'M', "Finance", 55000);
    bst.insert(bst.root, 104, "Diana", 40, 'F', "Admin", 70000);
    bst.insert(bst.root, 105, "Eve", 25, 'F', "IT", 65000);

    cout << "Inorder Traversal:" << endl;
    bst.inorder(bst.root);

    int count = 0;
    float totalSalary = bst.avgSalary(bst.root, count);
    cout << "Average Salary: " << totalSalary / count << endl;

    int male = 0, female = 0;
    bst.genderCount(bst.root, male, female);
    cout << "Male Employees: " << male << " Female Employees: " << female << endl;

    cout << "Tree Height: " << bst.height(bst.root) << endl;
    return 0;
}
