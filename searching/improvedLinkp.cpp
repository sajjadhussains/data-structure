#include<bits/stdc++.h>

using namespace std;

class Node
{
public:

    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

struct Test{
    int position[1000];
};

int countLength(Node* &head);
void insertAtTail(Node* &head,int val)
{
    Node *newNode = new Node(val);
    if(head ==NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtHead(Node* &head,int val)
{
    //s1:create new node
    Node *newNode = new Node(val);
    //s2:update of new node->next
    newNode->next = head;
    //s3:update of head
    head = newNode;
}
void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->data;
        if(n->next!=NULL)
        {
            cout<<"->";
        }
        n=n->next;
    }
    cout<<endl;
}
int countLength(Node* &head)
{
    int count=0;
    Node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void insertAtSpecificPosition(Node* &head,int pos,int val)
{
    int i=0;
    Node* temp = head;
    while(i<pos-2)
    {
        temp = temp->next;
        i++;
    }
    Node *newNode =new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

int searchByValueUnique(Node* &head,int key)
{
    Node* temp = head;
    int count = 1;
    if(temp ==NULL)
    {
        return -1;
    }
    while(temp->data != key)
    {
        if(temp == NULL)
        {
            return -1;
        }
        temp = temp->next;
        count++;
    }
    return count;
}
void searchByValueDuplicate(Node *head,int key)
{
    int count = 1;
    Node* temp = head;
    int size,flag=0;
    size = countLength(head);
    int position[size+1],k=1;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            position[k]=count;
            k++;
            flag = 1;
        }
        temp=temp->next;
        count++;
    }
    cout<<endl;
    if(flag == 0) cout<<"The search value is not yet in the list"<<endl;
    else{
        position[0] = k;
        cout<<"The value is found at position: ";
        for(int i=1;i<position[0];i++)
        {
            cout<<position[i];
            if(i<position[0]-1) cout<<",";
        }
        cout<<endl;
    }
}
Test SearchByValueDuplicateReturn(Node* &head,int key)
{
    Node *temp = head;
    Test T;
    int k=1;
    int count = 1;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            T.position[k] = count;
            k++;
        }
        temp=temp->next;
        count++;
    }
    T.position[0]=k;
    return T;
}
void searchByValueUnique(Node* &head,int searchValue,int value)
{
    //step-1:Search the position of the searchValue
    int position = searchByValueUnique(head,searchValue);
    //step-2:Insert the value at [psoition+1]
    insertAtSpecificPosition(head,position+1,value);
}
void deleteAtHead(Node *&head)
{
    Node *temp = head;
    if(temp!=NULL){
        head = temp->next;
        delete temp;
    }
    else{
        cout<<"There is no value in the linked list."<<endl;
    }
}
void deletionAtTail(Node *&head)
{
    Node* temp = head;
    if(temp != NULL)
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
    else{
        if(temp == NULL)
        {
            cout<<"There is no valued in the linked list."<<endl;
        }
        else{
            deleteAtHead(head);
        }
    }
}

void deleteAtSpecificPosition(Node *&head,int position)
{
    Node *temp = head;
    if(temp != NULL &&position<=countLength(head))
    {
        if(position==1)
            deleteAtHead(head);
        else if(position==countLength(head))
            deletionAtTail(head);
        else
        {
            int i=1;
            while(i<position-1){
            temp=temp->next;
            i++;
        }
        Node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        }
    }
    else{
        //if(position>countLength(head))
            cout<<"Position out of bound"<<endl;
        //else
          //  cout<<"There is no value in the list."<<endl;
    }
}

void deletionByValueUnique(Node* &head,int value)
{
    //find the position of the value
    int position =  searchByValueUnique(head,value);
    if(position == -1)  cout<<"Value is not found at the linked list";
    //delete the node at that position
    deleteAtSpecificPosition(head,position);
}
Node *reverseNonRecursive(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if(head == NULL)
    {
        cout<<"The linked list is empty"<<endl;
        return head;
    }
    Node *Next = head->next;
    while(true){
        current->next = prev;
        prev = current;
        if(current == NULL)
            break;
        current = Next;
        Next = Next->next;
    }
    return prev;
}

Node *reverseRecursive(Node* &head)
{
    //Base call
    if(head == NULL || head->next == NULL)
    {
        if(head==NULL) cout<<"The linked list is empty."<<endl;
    }
    //Recursive call
    Node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int findMid(Node *&head){
    Node *slow = head;
    Node *fast = head;
    if(head == NULL)
    {
        return -1;
    }
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
void makeCycle(Node *&head,int pos){
    Node *temp = head;
    Node *startNode;
    int count = 1;
    while(temp->next != NULL)
    {
        if(count == pos) startNode=temp;
        temp=temp->next;
        count++;
    }
    temp->next = startNode;
}
bool detectCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        //cycle test
        if(slow->next == fast->next){
            return true;
        }
    }
    return false;
}
void removeCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    //step 1: fast = slow
    do{
        slow = slow->next;
        fast = fast->next->next;

    }while(slow!=fast);

    //step 2: Reinitialization of fast
    fast = head;
    //step 3: fast->next = slow->next
    while(fast->next != slow->next){
        slow = slow->next;
        fast = fast->next;
    }
    //step 4:
        slow->next = NULL;
}
int main()
{
    Node *head = NULL;
    int value,position;
    int choice;

    cout<<"Choice 1:Insertion at head"<<endl
        <<"Choice 2:Insertion at tail."<<endl
        <<"Choice 3:Insertion at any position"<<endl
        <<"Choice 4:Search a value(Unique List)"<<endl
        <<"Choice 5:Search a value(duplication enabled list)"<<endl
        <<"Choice 6:Search a value(unique list)"<<endl
        <<"Choice 7:Deletion at head"<<endl
        <<"Choice 8:Deletion at tail"<<endl
        <<"choice 9:Deletion at a specific position"<<endl
        <<"choice 10:Deletion by value(uinque list)"<<endl
        <<"choice 11:Reverse of list non recursive"<<endl
        <<"choice 12:Finding the mid(slow-fast pointer Method)"<<endl
        <<"choice 13:Make a cycle at k position"<<endl
        <<"choice 14:Detect cycle in the list"<<endl
        <<"choice 15:Remove cycle (if any)"<<endl
        <<"choice 0: Exit"<<endl<<endl;

        cout<<"Next choice: ";
        cin>>choice;
    while(choice !=0)
    {

        switch(choice)
        {
        case 1:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 2:
            cout<<"Enter the value: ";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 3:
            cout<<"Enter the desired position: ";
            cin>>position;
            cout<<"Enter the value: ";
            cin>>value;
            insertAtSpecificPosition(head,position,value);
            break;
        case 4:
            cout<<"Enter the value to search: ";
            cin>>value;
            position=searchByValueUnique(head,value);
            if(position!=-1)
            {
                cout<<"The number is at position "<<position<<endl;
            }
            else{
                cout<<"The number is not yet in the list"<<endl;
            }
            break;
        case 5:
            cout<<"Enter the value to search: "<<endl;
            cin>>value;
            //searchByValueDuplicate(head,value);
            Test T;
            T = SearchByValueDuplicateReturn(head,value);
            if(T.position[0] == 1)
            {
                cout<<"The searched value is not yet in the list"<<endl;
            }
            else{
                int size = T.position[0];
                for(int i=1;i<size;i++)
                {
                    cout<<T.position[i];
                    if(i<size-1) cout<<",";
                }
                cout<<endl;
            }
            cout<<endl;
            break;
        case 6:
            cout<<"Enter the value to search: ";
            int searchValue;
            cin>>searchValue;
            cout<<"Enter the value to insert: ";
            cin>>value;
            searchByValueUnique(head,searchValue,value);
            break;
        case 7:
            deleteAtHead(head);
            break;
        case 8:
            deletionAtTail(head);
            break;
        case 9:
            if(head ==NULL)
            {
                cout<<"There is no value in the linked list."<<endl;
                break;
            }
            cout<<"Enter the position of the value: ";
            cin>>position;
            deleteAtSpecificPosition(head,position);
            display(head);
            break;
        case 10:
            cout<<"Enter the value to delete:";
            int deleteValue;
            cin>>deleteValue;
            deletionByValueUnique(head,deleteValue);
            break;
        case 11:
            head=reverseRecursive(head);
            break;
        case 12:
            int mid;
            mid=findMid(head);
            if(mid == -1)
                {
                    cout<<"The LL is empty."<<endl;
                }
            else
                {
                    cout<<"The mid value is "<<mid<<endl;
                }
            break;
         case 13:
            cout<<"Enter the desired position to create cycle:";
            cin>>position;
            makeCycle(head,position);
            break;
         case 14:
            bool cycleStatus;
            cycleStatus = detectCycle(head);
            if(cycleStatus == true)
                cout<<"There is a cycle in the list"<<endl;
            else
                cout<<"There is no cycle in the list"<<endl;
            break;
         case 15:
            cycleStatus = detectCycle(head);
            if(cycleStatus == true)
            {
                removeCycle(head);
            }
            else{
                cout<<"There is no cycle in the list"<<endl;
            }
        default:
            break;

        }
        cout<<"Next choice: ";
        cin>>choice;
    }
    cout<<endl
        <<"Linked List:";
    display(head);
    //reversedListPrint(head);
    cout<<endl<<"Length of the Linked list: "<<countLength(head)<<endl;

    return 0;
}
