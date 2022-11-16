#include<bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int value;
    ListNode *next;
};




ListNode* solve(ListNode* head , bool & anychange){

        if(head == NULL){
            return head;
        }
        ListNode* temp = head;
        int sum = 0;

        while(temp != NULL){
            sum+=temp->value;
            if(sum == 0)
                break;
            temp = temp->next;
        }
        if(sum == 0){
            anychange = true;
            return temp->next;
        }
        head->next = solve(head->next,anychange);
        return head;
    }


    ListNode* removeZeroSumSublists(ListNode* head) {

        while(true){
            bool anychange = false;
            head = solve(head , anychange);

            if(head == NULL || anychange == false)
                break;
        }

            return head;
    }

void display(ListNode *n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->next != NULL)
        {
            cout<<"->";
        }
        n = n -> next;
    }
    cout<<endl;
}
int main()
{
    ListNode* head = new ListNode();
    ListNode* second = new ListNode();
    ListNode* third = new ListNode();
    ListNode* fourth = new ListNode();
    ListNode* fifth = new ListNode();
    ListNode* six = new ListNode();
    ListNode* seven = new ListNode();
    ListNode* eight = new ListNode();
    ListNode* nine = new ListNode();
    ListNode* ten = new ListNode();
    ListNode* eleven = new ListNode();
    head->value = 4;
    head->next=second;
    second->value = 6;
    second->next = third;
    third->value = -10;
    third->next = fourth;
    fourth->value = 8;
    fourth->next=fifth;
    fifth->value=9;
    fifth->next = six;
    six->value=10;
    six->next=seven;
    seven->value=-19;
    seven->next=eight;
    eight->value = 10;
    eight->next=nine;
    nine->value=-18;
    nine->next=ten;
    ten->value=20;
    ten->next=eleven;
    eleven->value=25;
    eleven->next=NULL;

    head=removeZeroSumSublists(head);
    display(head);

    return 0;
}
