#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int value;
    Node *next;

    Node(int val)
    {
        value= val;
        next = NULL;
    }
};
class Queue{
    public:
    Node* front;
    Node* rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    //enque-push
    void push(int val)
    {
        Node *newNode = new Node(val);
        if(front == NULL){
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next=newNode;
        rear = rear->next;
    }
    //deque-pop
    int pop(){
        int chk=-1;
        if(front==NULL)
        {
            cout<<"underflow || There is no element in the list"<<endl;
            return chk;
        }
        Node *delNode;
        delNode = front;
        chk=delNode->value;
        front = front->next;
        if(front==NULL){
            rear=NULL;
        }
        delete delNode;
        return chk;
    }
    //peak->front() back()
    int Front()
    {
        int chk;
        chk = front->value;
        return chk;
    }
    int Back()
    {
        int chk;
        chk = rear->value;
        return chk;
    }
    //empty check
    bool empty()
    {
        if(front == NULL)
        {
            return true;
        }
        else
            return false;
    }

};

