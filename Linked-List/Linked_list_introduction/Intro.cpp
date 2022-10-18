#include<bits/stdc++.h>

using namespace std;

class Node{
public:
        int data;
        Node *next;
        //constructor creation
        Node(int val)
        {
            data = val;
            next = NULL;
        }
};
void insertATTail(Node* &head,int val)
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
    temp->next = newNode;
}
void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->data;
        if(n->next!=NULL)
            cout<<"->";
        n=n->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;

    int n;
    char choice = 'Y';
    while(choice == 'Y')
    {
        cout<<"Enter the value: ";
        cin>>n;
        insertATTail(head,n);
        cout<<"Do you want to continue:(Y/N)";
        cin>>choice;
    }

//    Node* second =new Node();
//    Node* third = new Node();
//    Node* fourth = new Node();
//
//    head->data = 1;
//    head->next = second;
//    second->data = 5;
//    second->next = third;
//    third->data = 8;
//    third -> next = fourth;
//    fourth->data = 9;
//    fourth->next = NULL;
    display(head);
}
