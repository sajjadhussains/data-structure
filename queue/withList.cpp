#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

class Queue{
    Node *front;
    Node *rear;
public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    //enque-->push(val)
    void push(int val)
    {
        Node *newNode = new Node(val);
        if(front == NULL)
        {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
        return;
    }
};
int main()
{

}
