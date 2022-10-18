#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value=val;
        next = NULL;
    }
};

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->next!=NULL)
        {
            cout<<"->";
        }
        n = n->next;
    }
    cout<<endl;
}
void insertAtTail(Node* &head,int val)
{
    Node *newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next =newNode;
}

void insertAtHead(Node* &head,int val)
{
    Node *newNode = new Node(val);
    //update of newNode->next
    newNode->next = head;
    //update of head
    head = newNode;
}

int main()
{
    Node *head = NULL;

    int value,choice=1;
    cout<<"choice 1:Insertion at head"<<endl
        <<"choice 2:Insertion at tail"<<endl
        <<"choice 0:Exit"<<endl;
    while(choice != 0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtHead(head,value);
            cin>>choice;
        case 2:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtTail(head,value);
            cin>>choice;
            break;
        default:
            break;
        }
    }
    display(head);
    return 0;
}
