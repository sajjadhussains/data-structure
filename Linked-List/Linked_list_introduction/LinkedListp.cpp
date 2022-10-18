#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
};

void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->next != NULL)
        {
            cout<<"->";
        }
        n = n -> next;
    }
    cout<<endl;
}
int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    head->value = 3;
    head->next=second;
    second->value = 6;
    second->next = third;
    third->value = 9;
    third->next = fourth;
    fourth->value = 12;
    fourth->next=NULL;
    display(head);

    return 0;
}
