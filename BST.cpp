#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node ()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node (int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *root = NULL;
void insert ()
{
    int item;
    cout <<"Data to be inserted:";
    cin >> item;
    node *temp = new node(item);
    node *temp2 = new node;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {   temp2 = root;
        while (1)
        {
            if (item < temp2->data)
            {
                if (temp2->left == NULL)
                {
                    temp2->left = temp;
                    break;
                }
                else
                {
                    temp2 = temp2->left; 
                }
            }
            else
            {
                if (temp2->right == NULL)
                {
                    temp2->right = temp;
                    break;
                }
                else
                {
                    temp2 = temp2->right; 
                };
            }
        }
    }
}
node* find(int item)
{
    
    node *temp = root;
    while (1)
    {
        if (temp->data == item)
        {
            cout << "Element Present."<<endl;
            break;
        }
        else if (item < temp->data )
        {
            temp = temp->left;
            if (temp == NULL)
            {
                cout << "Element Not Found."<<endl;
                break;
            }
        }
        else
        {
            temp = temp->right;
            if (temp == NULL)
            {
                cout << "Element Not Found."<<endl;
                break;
            }
        }
    }
    return temp;
}
void pred_succ()
{
    int item;
    cout <<"Element whose predecessor and succesor to be found:";
    cin >> item;
    node *temp2 = find(item);
    node *pre=NULL,*succ = NULL;
    if (temp2 == NULL)
    {
        cout << "Such an element not present."<<endl;
        return;
    }
    else
    {
        if (temp2->left == NULL)
            cout << "No predecessor found."<<endl;
        else
        {
            pre = temp2->left;
            while (pre->right!= NULL)
            {
                pre = pre->right;
            }
            cout << "Predecessor of " << item << " is " << pre->data << endl;
        }
        if (temp2->right == NULL)
        {
            cout << "No successor found."<<endl;
        }
        else
        {
            succ = temp2->right;
            while (succ->left!= NULL)
            {
                succ = succ->left;
            }
            cout << "Successor of " << item << " is " << succ->data << endl;
        }
        return;
    }
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    else    
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main()
{
    int n;
    l:
    cout <<endl << "0) EXIT" << endl 
        << "1) Insert element in BST" << endl
        << "2) Inorder BST" << endl
        << "3) Find an element"<<endl
        << "4) Predecessor or Successor of an element" << endl;
    cin >> n;
    switch (n)
    {
    case 0:
    goto exit;
        break;
    case 1:
        insert();
        break;
    case 2 :
        inorder(root);
        break;
    case 3:
        int item;
        cout <<"Data to be searched:";
        cin >> item;
        find(item);
        break;
    case 4:
        pred_succ();
        break;
    
    default:
        cout <<"Invalid choice" << endl;
        break;
    }
    goto l;
    exit:
    return 0;
}