
#include<bits/stdc++.h>

using namespace std;
template<typename N>class StackNode
{
public:
    N value;
    StackNode* next;
    StackNode* prev;
    StackNode(N val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

template<typename S>class Stack{
    StackNode <S> *head;
    StackNode <S> *top;
    StackNode <S> *Mid;
    int count =0;
public:
    Stack()
    {
        head = NULL;
        top = NULL;
        Mid = NULL;
    }
    void push(S val)
    {
        StackNode <S> *newNode = new StackNode <S> (val);
        if(head == NULL)
        {
            head = top = Mid = newNode;
            count++;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        if(count%2==1){
            Mid = Mid->next;
        }
        count++;
    }
    //pop implementation
    S pop()
    {
        StackNode <S> *delNode;
        delNode = top;
        S chk;
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
        if(count%2==0)
        {
            Mid = Mid->prev;
        }
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
    //find mid of the stack
    S mid()
    {
        if(count==0){
            return -1;
        }
       S midVal;
       midVal = Mid->value;
       return midVal;
    }
    //top
    S Top()
    {
        S chk;
        if(head == NULL)
        {
            cout<<"Stack underflow.There is no element in the stack."<<endl;
        }
        else return top->value;

        return chk;
    }
};
