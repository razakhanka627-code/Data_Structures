#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int value = 0) : data(value)
    {
        next = nullptr;
    }
};

class linkedlist
{
private:
    node *head;
    node *tail;

public:
    linkedlist()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertionatEnd()
    {
        int value;
        cout << "Enter value that u want to insert :";
        cin >> value;
        node *newNode = new node(value);
        // node* temp=head;
        if (head == nullptr)
        {
            head = newNode;
            // tail=newNode;
            // return;
        }
        else
        {
            tail->next = newNode;
        }
        // while(temp!=nullptr){
        //     temp=temp->next;
        // }

        tail = newNode;
    }

    void inertionatStart()
    {
        int value;
        cout << "Enter value that u want to insert :";
        cin >> value;
        node *newNode = new node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertionBeforeValue()
    {
        if (head == nullptr)
        {
            cout << "list does not exixt" << endl;
            return;
        }
        int beforeVal, value;
        cout << "Enter Before Value :";
        cin >> beforeVal;
        node *temp = head;
        node *previous = nullptr;
        while (temp != nullptr && temp->data != beforeVal)
        {
            previous = temp;
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Value not found " << endl;
            return;
        }
        cout << "Enter value that u want to insert :";
        cin >> value;
        node *newNode = new node(value);
        if (temp == head)
        {
            // tail->next=newNode;
            newNode->next = head;
            head = newNode;
            return;
        }
        previous->next = newNode;
        newNode->next = temp;
    }

    void insertAfterValue()
    {
        if (head == nullptr)
        {
            cout << "list does not exixt" << endl;
            return;
        }
        int afterVal, value;
        cout << "Enter After Value :";
        cin >> afterVal;

        node *current = head;
        while (current != nullptr && current->data != afterVal)
        {
            current = current->next;
        }
        if (!current)
        {
            cout << "Value Not Found" << endl;
            return;
        }
        cout << "Enter Value : ";
        cin >> value;
        node *newNode = new node(value);
        if (current->next == nullptr)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void display()
    {
        node *temp = head;
        if (head == nullptr)
        {
            cout << "list not found " << endl;
            return;
        }
        cout << "list : ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool search(int val)
    {
        node *current = head;
        while (current != nullptr && current->data != val)
        {
            current = current->next;
        }
        if (!current)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void deletefirstNode()
    {
        if (!head)
        {
            cout << "list not found" << endl;
            return;
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        else
        {
            node *current = head;
            head = current->next;
            delete current;
            // current=nullptr;
        }
    }

    void deletelastNode()
    {
        if (!head)
        {
            cout << "List Not Found" << endl;
            return;
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            node *current = head;
            node *previous = nullptr;
            while (current->next != nullptr)
            {
                previous = current;
                current = current->next;
            }
            tail = previous;
            tail->next = nullptr;
            delete current;
        }
    }

    void deleteMiddleNode()
    {
        int value;
        cout << "Enter value that u want to delete :";
        cin >> value;
        if (!head)
        {
            cout << "List Not Found" << endl;
            return;
        }
        node *current = head;
        node *previous = nullptr;
        while (current != nullptr && current->data != value)
        {
            previous = current;
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Value not found " << endl;
            return;
        }
        if (current == head)
        {
            deletefirstNode();
        }
        else if (current == tail)
        {
            deletelastNode();
        }
        else
        {
            previous->next = current->next;
            delete current;
        }
    }
};

int main()
{
    linkedlist list;
    cout << "~~~~~~~ Insertion At End ~~~~~~~~~" << endl;
    list.insertionatEnd();
    list.insertionatEnd();
    list.display();
    cout << "~~~~~~~ Insertion At start ~~~~~~~~~" << endl;
    list.inertionatStart();
    list.inertionatStart();
    list.display();
    cout << "~~~~~~~ Insertion Before Value ~~~~~~~~~" << endl;
    list.insertionBeforeValue();
    list.display();
    cout << "~~~~~~~ Insertion After Value ~~~~~~~~~" << endl;
    list.insertAfterValue();
    list.display();
    cout << "~~~~~~~ Insertion After Value ~~~~~~~~~" << endl;
    list.insertAfterValue();
    list.display();
    int x;
    cout << "Enter value that u want to search :";
    cin >> x;
    if (list.search(x))
    {
        cout << "Value found" << endl;
    }
    else
    {
        cout << "Value Not found" << endl;
    }
    cout << "~~~~~~~ Delete first node ~~~~~~~~~" << endl;
    list.deletefirstNode();
    list.display();
    cout << "~~~~~~~ Delete last node ~~~~~~~~~" << endl;
    list.deletelastNode();
    list.display();
    cout << "~~~~~~~ Delete node at the middle by value ~~~~~~~~~" << endl;
    list.deleteMiddleNode();
    list.display();
}