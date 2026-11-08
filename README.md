🎓 Student Record Management System using AVL Tree

<p align="center">  <img src="https://img.shields.io/badge/Language-C++-blue?style=for-the-badge&logo=cplusplus" />
  <img src="https://img.shields.io/badge/Data%20Structure-AVL%20Tree-green?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Project-Student%20Management-orange?style=for-the-badge" /></p>📌 About The Project

The Student Record Management System using AVL Tree is a C++ based application designed to manage student information efficiently.

This project uses an AVL Tree, which is a self-balancing Binary Search Tree (BST), to store and organize student records.

It helps users add, search, and display student information while maintaining balanced tree structure.

🎯 Objectives

- To manage student records digitally.
- To understand AVL Tree data structures.
- To perform efficient searching and insertion.
- To maintain tree balance automatically.
- To reduce the time required for managing student information.

✨ Features

S.No| Feature| Description
1| Add Student| Add new student details
2| Search Student| Search using Roll Number
3| Display Students| Display all records
4| AVL Balancing| Automatically balance the tree
5| Duplicate Check| Prevent duplicate Roll Numbers

🛠️ Technologies Used

- Programming Language: C++
- Data Structure: AVL Tree
- Concepts: Binary Search Tree, Recursion, Tree Rotations
- Compiler: GCC / G++

📂 Project Structure

student-record-management-avl-tree/
│
├── README.md
│
└── main.cpp

🌳 What is an AVL Tree?

An AVL Tree is a self-balancing Binary Search Tree.

In an AVL Tree, the difference between the heights of the left and right subtrees is called the Balance Factor.

Balance Factor = Height(Left) - Height(Right)

The balance factor must be -1, 0, or +1 for every node.

🔄 AVL Tree Rotations

AVL Tree uses four rotations to maintain balance:

1. LL Rotation – Right Rotation
2. RR Rotation – Left Rotation
3. LR Rotation – Left-Right Rotation
4. RL Rotation – Right-Left Rotation

⚙️ How It Works

1. Start the application.
2. Select an operation from the menu.
3. Enter student details.
4. Insert the student record into the AVL Tree.
5. Search records using Roll Number.
6. Display all student records in sorted order.
7. Exit the application.

📊 Time Complexity

Operation| Average / Worst Case
Search| O(log n)
Insertion| O(log n)
Display| O(n)

💻 How to Run the Project

Step 1: Clone the repository.

git clone https://github.com/25A31A05EU/student-record-management-avl-tree.git

Step 2: Open the project folder.

cd student-record-management-avl-tree

Step 3: Compile the program.

g++ main.cpp -o student

Step 4: Run the program.

./student

📸 Sample Output

--- Student Management System ---

1. Add Student
2. Search Student
3. Display Students
4. Exit

Enter choice: 1

Enter Roll Number: 101
Enter Name: Ram
Enter Marks: 90

Enter choice: 3

Roll No: 101 | Name: Ram | Marks: 90

🚀 Future Enhancements

- Update student records.
- Delete student records.
- Store records permanently using file handling.
- Add a graphical user interface.
- Generate student performance reports.

👩‍💻 Developed By

Vasamsetti Ramalakshmi

- 🎓 Department: Computer Science and Engineering
- 🏫 College: Pragati Engineering College
- 💻 Programming Language: C++

⭐ Conclusion

This project demonstrates the practical implementation of AVL Trees in student record management. It improves understanding of tree operations, balancing techniques, and efficient searching.

---

<p align="center">Thank You for Visiting My Project! ❤️

⭐ If you like this project, give it a Star!

</p>
