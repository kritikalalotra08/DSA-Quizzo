# DSA Quizzo

DSA Quizzo is a simple and interactive terminal-based quiz application developed in C++. It is designed to help users test and improve their knowledge of Data Structures and Algorithms (DSA) through multiple-choice questions loaded dynamically from an external file. This project demonstrates key programming concepts such as file handling, object-oriented design, and basic data structures in a clean, user-friendly terminal interface.

---

## FEATURES

1. Dynamic Question Loading 
   Questions and answers are read from a formatted text file (`questions.txt`), making it easy to add or update quiz content without changing the source code.

2. Interactive Quiz Flow 
   The app displays one question at a time with four options and accepts user input to select an answer.

3. User Control 
   After answering each question, users can choose to continue to the next question or end the quiz early.

4. Score Tracking 
   The app keeps track of correct answers and displays the final score once the quiz is completed or exited.

5. Robust Input Handling 
   Validates user inputs and skips any malformed questions in the input file.

---

TECH STACK

- C++ Programming Language 
  The core logic of the application is implemented in modern C++, using standard libraries for file input/output, string manipulation, and data handling.

- File I/O 
  Utilizes file streams (`ifstream`) to read quiz questions from a text file in a structured format.

- Object-Oriented Programming (OOP) 
  The `Question` struct encapsulates the properties of each quiz question, demonstrating basic OOP principles.

- Data Structures 
  Uses:
  - **Vectors** to store a dynamic list of questions and options.
  - **Strings** for managing question text and answers.

- Algorithms 
  Basic algorithms are used for:
  - Parsing and processing input strings.
  - Validating user responses.
  - Managing quiz control flow.

- Terminal-Based User Interface  
  Provides a simple command-line interface that works across platforms without dependencies on GUI frameworks.

---

DSA TOPICS COVERED (via quiz content)

The quiz questions are focused on fundamental Data Structures and Algorithms topics, including but not limited to:

- Arrays and Strings  
- Stacks and Queues  
- Trees and Graphs  
- Sorting Algorithms (Quick Sort, Merge Sort, Bubble Sort, etc.)  
- Searching Algorithms (Binary Search)  
- Complexity Analysis (Time and Space Complexity)  
- Object-Oriented Programming Concepts (Encapsulation, Inheritance, Polymorphism)

These topics help reinforce both theoretical understanding and practical knowledge for computer science students and coding interview preparation.

