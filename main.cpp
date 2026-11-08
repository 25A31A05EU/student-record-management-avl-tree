
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

int height(Student* n) {
    return n ? n->height : 0;
}

int getBalance(Student* n) {
    return n ? height(n->left) - height(n->right) : 0;
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

Student* balanceTree(Student* root) {
    if (!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int b = getBalance(root);

    if (b > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (b < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (b > 1) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
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

    return balanceTree(root);
}

Student* search(Student* root, int r) {
    if (!root || root->rollNo == r)
        return root;

    if (r < root->rollNo)
        return search(root->left, r);

    return search(root->right, r);
}

Student* minValueNode(Student* root) {
    Student* current = root;

    while (current->left)
        current = current->left;

    return current;
}

Student* deleteStudent(Student* root, int r) {
    if (!root) return root;

    if (r < root->rollNo)
        root->left = deleteStudent(root->left, r);

    else if (r > root->rollNo)
        root->right = deleteStudent(root->right, r);

    else {
        if (!root->left || !root->right) {
            Student* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }

        Student* temp = minValueNode(root->right);

        root->rollNo = temp->rollNo;
        root->name = temp->name;
        root->marks = temp->marks;

        root->right = deleteStudent(root->right, temp->rollNo);
    }

    return balanceTree(root);
}

void updateStudent(Student* root, int r) {
    Student* s = search(root, r);

    if (!s) {
        cout << "Student not found!\n";
        return;
    }

    cout << "Enter new name: ";
    getline(cin >> ws, s->name);

    cout << "Enter new marks: ";
    cin >> s->marks;

    cout << "Student updated successfully!\n";
}

void display(Student* root) {
    if (!root) return;

    display(root->left);

    cout << "Roll No: " << root->rollNo
         << " | Name: " << root->name
         << " | Marks: " << root->marks << endl;

    display(root->right);
}

void freeTree(Student* root) {
    if (!root) return;

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Student* root = NULL;
    int choice, roll;
    string name;
    float marks;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> roll;

                cout << "Enter Name: ";
                getline(cin >> ws, name);

                cout << "Enter Marks: ";
                cin >> marks;

                root = insert(root, roll, name, marks);
                break;

            case 2: {
                cout << "Enter Roll Number: ";
                cin >> roll;

                Student* s = search(root, roll);

                if (s)
                    cout << "Found: " << s->name
                         << " | Marks: " << s->marks << endl;
                else
                    cout << "Student not found!\n";

                break;
            }

            case 3:
                cout << "Enter Roll Number: ";
                cin >> roll;
                updateStudent(root, roll);
                break;

            case 4:
                cout << "Enter Roll Number: ";
                cin >> roll;

                if (search(root, roll)) {
                    root = deleteStudent(root, roll);
                    cout << "Student deleted successfully!\n";
                } else {
                    cout << "Student not found!\n";
                }
                break;

            case 5:
                if (!root)
                    cout << "No student records available!\n";
                else
                    display(root);
                break;

            case 6:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    freeTree(root);
    return 0;
}
