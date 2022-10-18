#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val){
        value = val;
        next = NULL;
    }
};
void insertAtTail(Node *&head,int val)
{
    Node *newNode = new Node(val);
    if(head==NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void even_replace(Node *n)
{
    while(n!=NULL)
    {
        int element = n->value;
        if(element % 2==0)
        {
            n->value = -1;
        }
        n=n->next;
    }
}
void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->next != NULL)
        {
            cout<<"->";
        }
        n=n->next;
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    Node *head = NULL;
    int i=0;
    while(i<n)
    {
        int val;
        cin>>val;
        insertAtTail(head,val);
        i++;
    }
    even_replace(head);
    display(head);
    return 0;
}
