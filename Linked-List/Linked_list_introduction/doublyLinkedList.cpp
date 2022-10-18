#include<bits/stdc++.h>

using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode *next;
    doublyNode *prev;
    doublyNode(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};
void insertionAtTail(doublyNode *&head,int val)
{
    doublyNode *newNode = new doublyNode(val);
    if(head == NULL)
    {
        head=newNode;
        return;
    }
    doublyNode *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
    return;
}
void display(doublyNode *head)
{
    doublyNode *temp = head;
    while(temp != NULL)
    {
        cout<<temp->value;
        if(temp->next!=NULL)
        {
            cout<<"->";
        }
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    doublyNode *head = NULL;
    int choice,position,value;

    cout<<"choice 1:Insertion at tail."<<endl;
    cout<<"choice 0:Exit"<<endl;
    cin>>choice;
    while(choice!=0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter the value:  ";
            cin>>value;
            insertionAtTail(head,value);
        }
        cout<<"next choice:";
        cin>>choice;
    }
    display(head);
    return 0;
}
