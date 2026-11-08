#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
    int height;
    Student *left, *right;

    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
        height = 1;
        left = right = NULL;
    }
};

int height(Student* node) {
    return node ? node->height : 0;
}

int balanceFactor(Student* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Student* rightRotate(Student* y) {
    Student* x = y->left;
    Student* t = x->right;
    x->right = y;
    y->left = t;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Student* leftRotate(Student* x) {
    Student* y = x->right;
    Student* t = y->left;
    y->left = x;
    x->right = t;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Student* insert(Student* root, int r, string n, float m) {
    if (!root) return new Student(r, n, m);

    if (r < root->rollNo)
        root->left = insert(root->left, r, n, m);
    else if (r > root->rollNo)
        root->right = insert(root->right, r, n, m);
    else {
        cout << "Roll number already exists!\n";
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int b = balanceFactor(root);

    if (b > 1 && r < root->left->rollNo)
        return rightRotate(root);

    if (b < -1 && r > root->right->rollNo)
        return leftRotate(root);

    if (b > 1 && r > root->left->rollNo) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && r < root->right->rollNo) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void display(Student* root) {
    if (!root) return;
    display(root->left);
    cout << "Roll No: " << root->rollNo
         << " | Name: " << root->name
         << " | Marks: " << root->marks << endl;
    display(root->right);
}

Student* search(Student* root, int r) {
    if (!root || root->rollNo == r) return root;
    if (r < root->rollNo) return search(root->left, r);
    return search(root->right, r);
}

int main() {
    Student* root = NULL;
    int choice, roll;
    string name;
    float marks;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display Students\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> roll;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Marks: ";
                cin >> marks;
                root = insert(root, roll, name, marks);
                break;

            case 2:
                cout << "Enter Roll Number: ";
                cin >> roll;
                {
                    Student* s = search(root, roll);
                    if (s)
                        cout << "Found: " << s->name
                             << " Marks: " << s->marks << endl;
                    else
                        cout << "Student not found!\n";
                }
                break;

            case 3:
                display(root);
                break;

            case 4:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
