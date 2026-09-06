#include <iostream>
using namespace std;
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void addData(int array[],int size){
//     cout<<"Enter Data :";
//     for(int i=0;i<size;i++){
//         cin>>array[i];
//     }
// }

// void printdata(int *array,int size,int &soa){
//     cout<<"Array[10] : { ";
//     for(int i=0;i<size;i++){
//         cout<<*(array+i)<<" ";
//         soa+=array[i];
//     }
//     cout<<"}"<<endl;
// }

// int main(){
//     int sumofarr=0;
//     int arr[10];

//     addData(arr,10);
//     printdata(arr,10,sumofarr);
//     cout<<"\n\nSum of Array :"<<sumofarr<<endl;

// }
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Dynamic 2D array

int *createArray(int rows, int cols)
{
    int *arr = new int[rows * cols];
    // cout<<"your array is successfully created";
    cout << "Your " << rows << "x" << cols << " matrix is successfully created" << endl;
    return arr;
}

void adddata(int *ptr, int rows, int cols)
{
    cout << "Enter values :";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> ptr[i * cols + j];
        }
    }
}

void display(int *ptr, int rows, int cols)
{
    cout << "Array[][]: \n{ ";
    for (int i = 0; i < rows; i++)
    {
        cout << "{ ";
        for (int j = 0; j < cols; j++)
        {
            cout << ptr[i * cols + j] << " ";
        }
        cout << "}\n";
    }
    cout << " }" << endl;
}

void sumofmatrices(int *ptr3, int *ptr2, int *ptr1, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ptr3[i * cols + j] = ptr2[i * cols + j] + ptr1[i * cols + j];
        }
    }
}
int main()
{
    int rows, cols;
    cout << "Enter rows and cols :";
    cin >> rows >> cols;

    // int *array;
    int *array1 = createArray(rows, cols);
    int *array2 = createArray(rows, cols);

    // array=createArray(rows,cols);

    cout << "\nEnter data for array1" << endl;
    adddata(array1, rows, cols);
    cout << "\nEnter data for array2" << endl;
    adddata(array2, rows, cols);

    display(array1, rows, cols);
    display(array2, rows, cols);
    int *array3 = createArray(rows, cols);
    sumofmatrices(array3, array2, array1, rows, cols);
    display(array3, rows, cols);

    delete[] array1;
    delete[] array2;
    delete[] array3;

    array1 = nullptr;
    array2 = nullptr;
    array3 = nullptr;
}
