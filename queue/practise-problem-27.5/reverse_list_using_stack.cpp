#include<bits/stdc++.h>
#include"MYSTACK.h";

using namespace std;

class Node{
    public:
    int value;
    Node *next;
};

Node *reverseList(Node *head)
{
    Stack <Node *> st;
    //pushhing list value into stack
    Node *ptr = head;
    while(ptr->next!=NULL){
        st.push(ptr);
        ptr=ptr->next;
    }
    //reverse list from stack
    ptr = head;
    while(!st.empty()){
        ptr->next = st.Top();
        ptr = ptr->next;
        st.pop();
    }
    return head;
}

void printList(Node *n)
{
    cout<<"given list: ";
    while(n)
    {
        cout<<n->value;
        if(n->next!=NULL)
        {
            cout<<"->";
        }
        n=n->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *first = new Node;
    first->value =
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = fourth;
    fourth->value=4;
    fourth->next = NULL;
    head = reverseList(head);
    printList(head);
    return 0;
}
