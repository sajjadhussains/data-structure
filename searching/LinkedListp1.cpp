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
        if(n->next!=NULL)
            cout<<"->";
            n=n->next;
    }
    cout<<endl;
}
int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    head->value = 1;
    head->next = second;
    second->value = 5;
    second->next = third;
    third->value = 10;
    third->next = fourth;
    fourth->value =144;
    fourth->next = NULL;
    display(head);

    return 0;
}
