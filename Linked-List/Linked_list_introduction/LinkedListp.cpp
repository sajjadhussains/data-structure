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
   

    head=removeZeroSumSublists(head);
    display(head);

    return 0;
}
