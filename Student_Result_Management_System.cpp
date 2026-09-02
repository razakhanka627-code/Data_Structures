#include <iostream>
#define STUDENTS 4
#define SUBJECTS 6
using namespace std;
void addData(int (*p)[STUDENTS][SUBJECTS])
{
    for (int i = 0; i < STUDENTS; i++)
    {
        cout << "  ~~~~~~~~ Student " << i + 1 << " ~~~~~~~ " << endl;
        for (int j = 0; j < SUBJECTS; j++)
        {
            cout << "Subject " << j + 1 << " : ";
            cin >> *(*(*p + i) + j);
        }
    }
}

void display(int (*p)[STUDENTS][SUBJECTS])
{
    cout << "\n\nMarks :" << endl
         << " { ";
    for (int i = 0; i < STUDENTS; i++)
    {
        cout << " { ";
        for (int j = 0; j < SUBJECTS; j++)
        {
            cout << *(*(*p + i) + j) << " ";
        }
        cout << "}" << endl;
    }
    cout << " }" << endl;
}

void status_p_f(int (*p)[STUDENTS][SUBJECTS], char (*ptr)[STUDENTS])
{
    int *average = new int[STUDENTS];

    for (int i = 0; i < STUDENTS; i++)
    {
        int total = 0;
        for (int j = 0; j < SUBJECTS; j++)
        {
            total += *(*(*p + i) + j);
        }
        *(average + i) = total / SUBJECTS;
    }

    for (int i = 0; i < STUDENTS; i++)
    {
        if (*(average + i) >= 50)
        {
            *(*ptr + i) = 'P';
        }
        else
            *(*ptr + i) = 'F';
    }
}

void displayStatus(char (*p)[STUDENTS])
{
    cout << "\n\n\t~~~~~ STATUS ~~~~~~~\n";
    cout << "Stu No.\t\t\tStatus" << endl;
    for (int i = 0; i < STUDENTS; i++)
    {
        cout << i + 1 << "\t\t\t" << *(*p + i) << endl;
    }
}

int *totalmarks(int (*p)[STUDENTS][SUBJECTS])
{
    int *totalMarks = new int[STUDENTS]{0};
    int total = 0;
    for (int i = 0; i < STUDENTS; i++)
    {
        int total = 0;
        for (int j = 0; j < SUBJECTS; j++)
        {
            total += *(*(*p + i) + j);
        }
        *(totalMarks + i) = total;
    }
    return totalMarks;
}
void displayTotal(int *p)
{
    cout << "\n\n\t~~~~~ Total Marks ~~~~~~~\n";
    cout << "Stu No.\t\t\tTotal Marks" << endl;
    for (int i = 0; i < STUDENTS; i++)
    {
        cout << i + 1 << "\t\t\t" << *(p + i) << endl;
    }
}

int highestScore(int *p)
{
    int ind = 0;
    int max = *(p + 0);
    for (int i = 0; i < STUDENTS; i++)
    {
        if (*(p + i) > max)
        {
            max = *(p + i);
            ind = i;
        }
    }
    return ind;
}
int main()
{
    int marks[STUDENTS][SUBJECTS] = {0};
    char status[STUDENTS] = {0};
    addData(&marks);
    display(&marks);
    status_p_f(&marks, &status);
    displayStatus(&status);
    int *ptr_Total = totalmarks(&marks);
    displayTotal(ptr_Total);
    int index = highestScore(ptr_Total);
    cout << "\n\t~~~~~ Highest Score ~~~~~~~~\n";
    cout << "Student " << index + 1 << " take highest marks" << endl;
    cout << "Marks :  " << *(ptr_Total + index) << endl;
}