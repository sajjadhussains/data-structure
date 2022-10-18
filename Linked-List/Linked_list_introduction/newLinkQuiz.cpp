#include<bits/stdc++.h>

using namespace std;

class Node

{

public:

    int val;

    Node * next;

    Node(int val)

    {

        this->val=val;

    }

};
void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->val;
        if(n->next!=NULL)
        {
            cout<<"->";
        }
        n=n->next;
    }
    cout<<endl;
}
int main()

{

    Node * head = new Node(5);

    Node * a = new Node(10);

    head->next = a;
    a->next = NULL;

    display(head);
}
