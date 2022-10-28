#include<bits/stdc++.h>

using namespace std;

template<typename N>class QueueNode{
    public:
    N value;
    QueueNode *next;

    QueueNode(N val)
    {
        value= val;
        next = NULL;
    }
};
template<typename Q>class Queue{
    public:
    QueueNode <Q> *front;
    QueueNode <Q> *rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    //enque-push
    void push(Q val)
    {
        QueueNode <Q> *newNode = new QueueNode<Q>(val);
        if(front == NULL){
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next=newNode;
        rear = rear->next;
    }
    //deque-pop
    Q pop(){
        Q chk;
        if(front==NULL)
        {
            cout<<"underflow || There is no element in the list"<<endl;
            return chk;
        }
        QueueNode <Q> *delNode;
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
    Q Front()
    {
        Q chk;
        chk = front->value;
        return chk;
    }
    Q Back()
    {
        Q chk;
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

