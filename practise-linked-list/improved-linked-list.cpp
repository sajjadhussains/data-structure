#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int value;
        Node *Next;
        Node(int val){
            value = val;
            Next = NULL;
        }

};
void display(Node* n){
    while(n!=NULL){
        cout<<n->value;
        if(n->Next!=NULL) cout<<" -> ";
        n = n->Next;
    }
    cout<<endl;
}
//insert at tail of the linked list
void insertAtTail(Node* &head,int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->Next!=NULL){
        temp = temp->Next;
    }
    temp->Next = newNode;

}

//insertion at head
void insertionAtHead(Node *&head,int val){
    Node* newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}


int main(){
    Node* head = NULL;
    // insertAtTail(head,1);
    // insertAtTail(head,5);
    // insertAtTail(head,8);
    // insertAtTail(head,9);
    int n;
    int choice = 2;
    cout<<"choice 1:Insertion at Head"<<endl<<"Choice 2: Insertion at tail"<<"Choice 3: Exit"<<endl;
    while(choice == 2 || choice == 1){
        cout<<"Enter the value: ";
        cin>>n;
        if(choice == 1) insertionAtHead(head,n);
        else if(choice == 2) insertAtTail(head,n);

        cout<<"Next Choice: ";
        cin>>choice;
    }

    display(head);

    return 0;
}