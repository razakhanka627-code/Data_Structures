#include <iostream>
using namespace std;

class linearList
{

private:
    int *dataList;
    int size;
    int capacity;

public:
    //````````````````````````````````````````````````````` Parameterized Constructor ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    linearList(int cap) : capacity(cap), size(-1)
    {
        dataList = new int[capacity];
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ COPY CONSTRUCTOR (DEEP COPY) ~~~~~~~~~~~~~~~~~~~~~~~~~~
    linearList(const linearList &obj)
    {
        size = obj.size;
        capacity = obj.capacity;
        dataList = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            dataList[i] = obj.dataList[i];
        }
    }
    void addData(int s)
    {

        if (s < 0 || s >= capacity)
        { // check
            cout << "You dont add data in existing array";
            return;
        }
        cout << "Enter Data :";
        for (int i = 0; i < s; i++)
        {
            cin >> *(dataList + i);
        }
        size = s;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INSERTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void insert(int index, int data)
    {
        if (index < 0 || index >= capacity)
        { // check 1
            cout << "INVALID INDREX" << endl;
            return;
        }
        if (size == capacity)
        { // check 2
            cout << "No space in Data list" << endl;
            return;
        }
        for (int i = size; i >= index; i--)
        {
            *(dataList + (i + 1)) = *(dataList + i);
        }
        *(dataList + index) = data;
        size++;
    }

    void display()
    {

        cout << "\nData_List[" << capacity << "] : { ";
        for (int i = 0; i < size; i++)
        {
            cout << *(dataList + i) << " ";
        }
        cout << "}" << endl;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SEARCHING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int searchValue(int val)
    {
        for (int i = 0; i < size; i++)
        {
            if (*(dataList + i) == val)
            {
                return i;
            }
        }
        return -1;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DELETION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void deleteData(int val)
    {
        int index = -1; // for check
        for (int i = 0; i < size; i++)
        {
            if (*(dataList + i) == val)
            {
                index = i;
                break; // cuz i dont want to deleate another value in the list
            }
        }
        if (index == -1)
        { // check must
            cout << "Value Not Found" << endl;
            return;
        }

        for (int i = index; i < size; i++)
        {
            *(dataList + i) = *(dataList + (i + 1));
        }
        size--;
    }
    ~linearList()
    {
        delete[] dataList;
    }
};

int main()
{
    linearList array(10);
    array.addData(5);
    cout << "\n~~~~~~ INSERT VALUE ~~~~~~~~\n";
    int index, data;
    cout << "Enter Index :";
    cin >> index;
    cout << "Enter Data :";
    cin >> data;
    array.insert(index, data);
    array.display();

    cout << "\n~~~~~~ SEARCH VALUE ~~~~~~~~\n";
    int value;
    cout << "Enter value to search :";
    cin >> value;
    int result = array.searchValue(value);
    if (result != -1)
    {
        cout << "Value found at position " << result + 1 << endl;
    }
    else
        cout << "Value not found" << endl;

    cout << "\n~~~~~~ DELETE VALUE ~~~~~~~~\n";
    cout << "Enter Value that u want to delete :";
    cin >> value;
    array.deleteData(value);
    array.display();

    linearList array2 = array;
    array2.display();
}