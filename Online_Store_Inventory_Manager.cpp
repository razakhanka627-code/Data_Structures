// Ali Raza
// 25p-0729
#include <iostream>
#define CAP 10
using namespace std;

void addId_end(int *p, int capa, int &size)
{
    if (capa - 1 == size)
    {
        cout << "No space avaliable" << endl;
        return;
    }
    int id;
    cout << "Enter Id :";
    cin >> id;
    for(int i=0;i<size;i++){
        if(*(p+i)==id){
            cout<<"ID already exixt add new"<<endl;
            return;
        }
    }
    *(p + (size + 1)) = id;
    size++;
}

void addId_position(int *p, int capa, int &size)
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
    if(position<0||position>=capa){
        cout<<"INvalid position "<<endl;
        return;
    }
    cout << "Enter Id :";
    cin >> id;
    for (int i =0; i<size; i++)
    {
        if(*(p + i)==id){
            cout<<"ID already avaliable try another";
            return;
        }
        
    }
    for (int i = size; i >= position - 1; i--)
    {
        *(p + (i + 1)) = *(p + i);
    }
    *(p + (position - 1)) = id;
    size++;
}

void removeId(int *p, int capa, int &size)
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
    for (int i = position - 1; i <= size; i++)
    {
        *(p + i) = *(p + (i + 1));
    }
    size--;
}

int searchId(int *p, int size)
{
    int id;
    cout << "Enter id that u want to search :";
    cin >> id;
    int index=-1;
    for (int i = 0; i < size; i++)
    {
        if (*(p + i) == id)
        {
           // cout << "Id : " << id << " found at position " << i + 1 << " " << endl;
           index=i;
        }
    }
    //cout << "Id Not found " << endl;
    return index;
}

void displayId(int *p, int size)
{
    cout << "No. \t\tID" << endl;
    for (int i = 0; i < size; i++)
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

void removeId_position(int *p, int capa, int &size)
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

void productExist(int *p,int size){
    int id;
    cout<<"Enter ID : ";
    cin>>id;
    for(int i=0;i<size;i++){
        if(*(p+i)==id){
            cout<<"Product Exist at position "<<i+1<<endl;
            return;
        }
    }
    cout<<"Product does not exist"<<endl;
}

int main()
{
    int array[CAP] = {1, 4, 5, 6, 15};
    int size = 5;
    int choice;
    do
    {
        cout << "\n\t1. Add a new product ID at the end, but reject duplicates." << endl;
        cout << "\t2. Insert a product ID at any valid position, but reject duplicates. " << endl;
        cout << "\t3. Remove a product by product ID." << endl;
        cout << "\t4. Remove a product by position." << endl;
        cout << "\t5. Search for a product ID and return its position." << endl;
        cout << "\t6. Display all products in their current order." << endl;
        cout << "\t7. Count the number of products." << endl;
        cout << "\t8. Determine whethever a given product exists." << endl;
        cout << "\t9. Exit" << endl;
        // cout << "8." << endl;

        cout << "Enter your choice :";
        cin >> choice;
        int position_1;

        switch (choice)
        {
        case 1:
            addId_end(array, CAP, size);
            break;
        case 2:
            addId_position(array, CAP, size);
            break;
        case 3:
            removeId(array, CAP, size);
            break;
        case 4:
            removeId_position(array, CAP, size);
            break;
        case 5:
            position_1=searchId(array, size);
            if(position_1==-1){
                cout<<"Id not found";
            }
            cout<<"ID found at position "<<position_1+1<<endl;
            break;
        case 6:
            displayId(array, size);
            break;
        case 7:
            cout<<"Total No of products : "<<size<<endl;
            break;
        case 8:
            productExist(array,size);
            break;
        case 9:
            return 0;
            break;
        }
    } while (choice != 7);
}