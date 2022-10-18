#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node* next;
    Node* prev;
    Node(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

class Stack{
public:
    Node *head;
    Node *top;
    int count =0;
    void push(int val)
    {
        Node *newNode = new Node(val);
        if(head == NULL)
        {
            head = top = newNode;
            count++;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
    }
    //pop implementation
    int pop()
    {
        Node *delNode;
        delNode = top;
        int chk=-1;
        //if there is no element in stack
        if(head==NULL)
        {
            cout<<"Stack Underflow"<<endl;
            return chk;
        }
        if(head==top)//if 1 element in stack
        {
            top = head = NULL;
        }
        //more than 1 element in stack
        else{
             top = delNode->prev;
             top->next = NULL;
        }
        chk = delNode->value;
        delete delNode;
        count--;
        return chk;
    }
    //empty
    bool empty()
    {
        if(head == NULL) return true;
        else return false;
    }
    //size
    int size()
    {
        return count;
    }
    //top
    int top()
    {
        if(head == NULL)
        {
            cout<<"Stack underflow.There is no element in the stack."<<endl;
        }
        else return top->value;
    }
int main()
{
    Node *head = NULL;

}
