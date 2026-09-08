#include <iostream>
#define CAP 10
using namespace std;

void addcode_end(int *arr,int capa,int &size){
    if(size==capa){
        cout<<"List is full No space avaliable "<<endl;
        return;
    }
    int value;
    cout<<"Enter supply code :";
    cin>>value;
    *(arr+size)=value;
    size++;

}

void addcode_position(int *arr,int capa,int &size){
    if (size == capa)
    {
        cout << "List is full No space avaliable " << endl;
        return;
    }
    int position,code;
    cout<<"Enter position where u want to enter supply code :";
    cin>>position;
    if(position<0||position>size){
        cout<<"Invalid position "<<endl;
        return;
    }
    cout<<"Enter code :";
    cin>>code;
    for(int i=size-1;i>=position-1;i--){
        *(arr+(i+1))=*(arr+i);
    }
    *(arr+(position-1))=code;
    size++;
}

void removecode_position(int *arr,int &size){
    if(size==-1){
        cout<<"No deletion possible (list is empty)"<<endl;
        return;
    }
    int position;
    cout<<"Enter position of code that you want to delete :";
    cin>>position;
    if(position<0||position>=size){
        cout<<"Invalid position "<<endl;
        return;
    }
    for(int i=position-1;i<size;i++){
        *(arr+i)=*(arr+(i+1));

    }
    size--;
}

void removeallOccurance(int *arr,int &size ){
    if (size == -1)
    {
        cout << "No deletion possible (list is empty)" << endl;
        return;
    }
    int code;
    cout << "Enter code that you want to delete :";
    cin >> code;

    for(int i=0;i<size;i++){
        if(*(arr+i)==code){
            for(int j=i;j<size;j++){
                *(arr+j)=*(arr+(j+1));
            }
        size--;
        }
    }
}

void search(int *arr,int size){
    int code;
    cout<<"Enter code that you want to seaech :";
    cin>>code;
    for(int i=0;i<size;i++){
        if(*(arr+i)==code){
            cout<<"occur at position "<<i+1<<endl;
        }
    }
}

void clearlist(int *arr,int size){
    for(int i=0;i<size;i++){
        *(arr+i)=0;
    }
    cout<<"List is clear"<<endl;
}

void display(int *arr,int size){
    cout<<"List : { ";
    for(int i=0;i<size;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<"}"<<endl;
}

void reverse(int *arr,int size){
    int temp;
    for(int i=0,j=size-1;i<j;i++,j--){
        temp=*(arr+i);
        *(arr+i)=*(arr+j);
        *(arr + j)=temp;
    }
}

void displaysize_capa(int capa,int size){
    cout<<"Capacity : \t"<<capa<<endl;
    cout << "Size   : \t" <<size<< endl;
}

    int
    main()
{
    int size=-1;
    int supplyCode[CAP]={1,2,3,4,5};
    size=5;
    int choice;
    do{
        cout << "\n1. Add a supply code at the end."<<endl;
        cout << "2. Insert a supply code at a specified position." << endl;
        cout << "3. Remove a supply code from a specified position." << endl;
        cout << "4. Remove all occurrences of a specified supply code." << endl;
        cout << "5. Search for a supply code and report all positions where it occurs." << endl;
        cout << "6. Display the list." << endl;
        cout << "7. Reverse the list in-place using array operations." << endl;
        cout << "8. Display the current size and capacity." << endl;
        cout << "9. Clear the entire list." << endl;
        cout << "10. Exit.\n" << endl;

        cout<<"Enter choice :";
        cin>>choice;
        switch (choice)
        {
        case 1:
            addcode_end(supplyCode,CAP,size);
            break;
        case 2:
            addcode_position(supplyCode, CAP, size);
            break;
        case 3:
            removecode_position(supplyCode, size);
            break;
        case 4:
            removeallOccurance(supplyCode, size);
            break;
        case 5:
            search(supplyCode, size);
            break;
        case 6:
            display(supplyCode, size);
            break;
        case 7:
            reverse(supplyCode , size);
            break;
        case 8:
            displaysize_capa(CAP,size);
            break;
        case 9:
            clearlist(supplyCode,size);
            break;
        case 10:
            return 0;
            break;

        // default:
        //     break;
        }
    }while(choice!=9);
}
