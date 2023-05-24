#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
    node()
    {
        data=0;
        next=NULL;
    }
};
class node *head;
void add_end()
{
    int data;
    cout << "Enter data to be inserted in node" << endl;
    cin >> data;
    node* temp = new node (data);
    if (head == NULL)
    {
        head = temp; 
    }
    else
    {
        node* temp1 = head;
        while(temp1->next != NULL)
        {
            temp1 = (*temp1).next;
        }
        temp1->next = temp;
    }
}
void add_front()
{
    int data;
    cout << "Enter data to be inserted in node" << endl;
    cin >> data;
    node* temp = new node (data);
    temp->next = head;
    head = temp;
}
void display()
{
    node* temp = head;
    cout<<endl;
    while(temp!= NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

void find()
{
    int item,pos=0,found=false;
    cout << "Enter item to be searched:";
    cin >> item;
    node* temp = head;
    while(temp->next != NULL) 
    {
        pos++;
        temp = temp->next;
        if (temp->data == item)
        {
            found = true;
            break;
        } 
    }
    if (found)
    {
        cout<<pos;
    }
    else
    {
        cout << "Item not found";
    }
    
    
}

void remove_end()
{
    node* temp = head;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {   
        if (temp->next == NULL)
        {
            delete temp;
            head = NULL;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }
}

void remove_front()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {   
        head = head->next;
    }
}
int main() 
{
    int num;
    cout << "1) Add a node to the end of list"<<endl<<"2) Remove a node from the end of list"<<endl <<"3) Add a node to the front of list"<<endl
            <<"4) Remove a node from the front of list"<<endl<<"5) Find an element"<<endl;
    l:
    cout << "Enter choice:";
    cin >> num;
    switch  (num)
    {
        case 1:
            add_end();
            display();
            break;
        case 2:
            remove_end();
            display();
            break;
        case 3:
            add_front();
            display();
            break;
        case 4:
            remove_front();
            display();
            break;
        case 5:
            find();
            break;
        default :
            cout << "Invalid choice"<<endl;
    }
    goto l;
    return 0;
}