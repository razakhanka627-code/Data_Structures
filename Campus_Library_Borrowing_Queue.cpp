//Ali Raza
//25p-0729
#include <iostream>
#define CAP 10
using namespace std;

void addId_end(int *p,int capa, int &size)
{
    if(capa-1==size){
        cout<<"No space avaliable"<<endl;
        return;
    }
    int id;
    cout<<"Enter Id :";
    cin>>id;
    *(p+(size+1))=id;
    size++;
}

void addId_position(int *p, int capa, int &size){
    if (capa - 1 == size)
    {
        cout << "No space avaliable" << endl;
        return;
    }
    int position;
    int id;
    cout<<"Enter Position :";
    cin>>position;
    cout << "Enter Id :";
    cin >> id;
    for(int i=size;i>=position-1;i--){
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
    if (position<0 || position>capa)
    {
        cout << "Invalid position" << endl;
        return;
    }
    
    // int id;
   
    // cout << "Enter Id :";
    // cin >> id;
    for (int i = position-1; i <=size; i++)
    {
        *(p + i) = *(p + (i+1));
    }
    size--;
}

void searchId(int *p,int size)
{
    int id;
    cout<<"Enter id that u want to search :";
    cin>>id;
    int index;
    for(int i=0;i<size;i++){
        if(*(p+i)==id){
            cout<<"Id : "<<id<<" found at position "<<i+1<<" "<<endl;
        }
    }
    cout<<"Id Not found "<<endl;
}

void displayId(int *p,int size){
    cout<<"No. \t\tID"<<endl;
    for(int i=0;i<size;i++){
        cout << i + 1 << " \t\t" << *(p + i) << endl;
    }
    
}

void listReport(int *p,int capa,int size){
    int space=0;
    if(size==capa-1){
        cout<<"List is full (no space avaliable)"<<endl;
    }
    else if(size<capa){
        space=(capa-1)-size;
        cout<<space+1<<" empty spaces are avaliable in out list"<<endl;
    }
}

    int main()
{
    int array[CAP]={1,4,5,6,15};
    int size=5;
    int choice;
    do{
        cout << "\n\t1. Add a student ID at the end of the list." << endl;
        cout << "\t2. Insert a student ID" << endl;
        cout << "\t3. Remove a student ID" << endl;
        cout << "\t4. Search for a student ID and report its position." << endl;
        cout << "\t5. Display all currently issued student IDs." << endl;
        cout << "\t6. Report whether the list is empty or full." << endl;
        cout << "\t7. Exit" << endl;
       // cout << "8." << endl;

       cout<<"Enter your choice :";
       cin>>choice;

       switch(choice){
        case 1:
            addId_end(array,CAP,size);
        break;
        case 2:
            addId_position(array, CAP, size);
            break;
        case 3:
            removeId(array, CAP, size) ;
        break;
        case 4:
            searchId(array,size);
        break;
        case 5:
            displayId(array,size);
        break;
        case 6:
            listReport(array,CAP,size);
        break;
        case 7:
            return 0;
        break;
        }
    }while(choice!=7);
}