#include <iostream>
#define CAP 10			//macros for fixed size 
using namespace std;

void addId_end(int *p, int capa, int &size)    //function for inserting data at the end of the list
{
    if (capa - 1 == size)
    {
        cout << "No space avaliable" << endl;
        return;
    }
    int id;
    cout << "Enter Id :";
    cin >> id;
    *(p + (size + 1)) = id;
    size++;
}

void addId_position(int *p, int capa, int &size)  //function for inserting data at any position
{
    if (capa - 1 == size)
    {
        cout << "No space avaliable" << endl;
        return;
    }
    int position;
    int id;
    cout << "Enter Position :";
    cin >> position;
    cout << "Enter Id :";
    cin >> id;
    for (int i = size; i >= position - 1; i--)
    {
        *(p + (i + 1)) = *(p + i);
    }
    *(p + (position - 1)) = id;
    size++;
}

void deleteId(int *p, int capa, int &size)//function for delation
{
    int position;
    cout << "Enter Position :";
    cin >> position;
    if (position < 0 || position > capa)
    {
        cout << "Invalid position" << endl;
        return;
    }

    // int id;

    // cout << "Enter Id :";
    // cin >> id;
    for (int i = position - 1; i < size; i++)
    {
        *(p + i) = *(p + (i + 1));
    }
    size--;
}

void searchId(int *p, int size)// searching
{
    int id;
    cout << "Enter id that u want to search :";
    cin >> id;
    int index;
    for (int i = 0; i < size; i++)
    {
        if (*(p + i) == id)
        {
            cout << "Id : " << id << " found at position " << i + 1 << " " << endl;
        }
    }
    cout << "Id Not found " << endl;
}

void displayId(int *p, int size)
{
    cout << "No. \t\tID" << endl;
    for (int i = 0; i <= size; i++)
    {
        cout << i + 1 << " \t\t" << *(p + i) << endl;
    }
}

void listReport(int *p, int capa, int size)
{
    int space = 0;
    if (size == capa - 1)
    {
        cout << "List is full (no space avaliable)" << endl;
    }
    else if (size < capa)
    {
        space = (capa - 1) - size;
        cout << space + 1 << " empty spaces are avaliable in out list" << endl;
    }
}

void deleteFirstOccurence(int *p,int &size){
    int id;
    cout << "Enter id that u want to delete :";
    cin >> id;
    int index=-1;
    for (int i = 0; i < size; i++)
    {
        if (*(p + i) == id)
        {
            index=i;
            return;
        }
    }
    if(index==-1){
        cout<<"Id Not found"<<endl;
    }
    for(int i=index;i<size;i++){
        *(p+i)=*(p+(i+1));
    }
    size--;
}

void displayFirst_Last(int *p,int size){
    cout<<"First patient ID : "<<*(p+0)<<endl;
    cout<<"Last patient ID : "<<*(p+size)<<endl;
}

void currentNoofPatients(int *p,int capa,int size){
    cout<<"List Capacity : "<<capa<<endl;
    cout<<"Current No of Patients : "<<size+1<<endl;
}

    int
    main()
{
    int array[CAP] = {1, 4, 5, 6, 15};
    int size = 5;
    int choice;
    do
    {
        cout << "\n\t1. Insert a patient ID at the end." << endl;
        cout << "\t2. Insert a patient ID at a specified position." << endl;
        cout << "\t3. Delete a patient ID by its position." << endl;
        cout << "\t4. Delete the first occurrence of a patient ID." << endl;
        cout << "\t5. Search for a patient ID." << endl;
        cout << "\t6.Display the current appointment list." << endl;
        cout << "\t7. Display the first and last patient IDs." << endl;
        cout << "\t8. Show the current number of patients." << endl;
        cout << "\t9. Exit" << endl;
        // cout << "8." << endl;

        cout << "Enter your choice :";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addId_end(array, CAP, size);
            break;
        case 2:
            addId_position(array, CAP, size);
            break;
        case 3:
            deleteId(array, CAP, size);
            break;
        case 4:
            deleteFirstOccurence(array, size);
            break;

        case 5:
            searchId(array, size);
            break;
        case 6:
            displayId(array, size);
            break;
        case 7:
            displayFirst_Last(array, size);
            break;
        case 8:
            currentNoofPatients(array,CAP,size);
            break;
        case 9:
            return 0;
            break;
        }
    } while (choice != 7);
}
