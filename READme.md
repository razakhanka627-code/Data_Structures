# Student Result Management System

A C++ project I built while learning **Data Structures**, with a focus on implementing a **Linear List** using pointer-based access.

## About the Project

This project manages the exam results of a class of students.

For each student, the program:

* Stores marks for multiple subjects
* Calculates the total marks
* Calculates the average
* Determines Pass/Fail status
* Finds the highest-scoring student
* Counts the number of students who passed

The main purpose of this project was to practice **Linear Lists** and understand how a data structure can be applied to a practical problem.

## Concepts Practiced

* Linear List
* 1D and 2D arrays
* Pointers and pointer arithmetic
* Pointer to an entire array
* Dynamic memory allocation
* Functions with pointers
* `new` and `delete[]`

## Data

The project currently uses:

```cpp
#define STUDENTS 4
#define SUBJECTS 3
```

Sample marks:

```text
Student 0: 80 45 60
Student 1: 30 40 35
Student 2: 90 85 95
Student 3: 50 50 45
```

A student passes when their average marks are **50 or above**.

## Expected Results

| Student | Total | Average | Status |
| ------: | ----: | ------: | :----: |
|       0 |   185 |    61.6 |    P   |
|       1 |   105 |    35.0 |    F   |
|       2 |   270 |    90.0 |    P   |
|       3 |   145 |    48.3 |    F   |

**Highest Scorer:** Student 2
**Total Passed:** 2

## What I Learned

This project helped me understand that learning a data structure isn't just about knowing its definition. Implementing it and using it in a practical problem makes the concept much clearer.

I'm continuing my Data Structures journey by building projects and practicing one concept at a time.

## Technologies

* C++
* Data Structures
* Pointers
* Dynamic Memory Allocation

## Status

🚧 Learning Project — more improvements coming as I learn new Data Structures.
