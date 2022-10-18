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

void traversing_with_m_n(Node *&head,int m,int n)
{
    Node *current,*changingNode;
    current =head;
    int i;
    while(current!=NULL)
    {
        for(i=1;i<m &&current!=NULL;i++)
        {
            current=current->next;
        }
        changingNode = current->next;
        for(i=0;i<n && changingNode!=NULL;i++)
        {
            Node *delNode = changingNode;
            changingNode  = changingNode->next;
            delete delNode;
        }
        current->next =changingNode;
        current=changingNode;
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
}

int main()
{
    Node *head = NULL;
    int k,m,n;
    cin>>k>>m>>n;
    int i=0;
    while(i<k)
    {
        int val;
        cin>>val;
        insertAtTail(head,val);
        i++;
    }
    traversing_with_m_n(head,m,n);
    display(head);
    return 0;
}
