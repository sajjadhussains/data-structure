#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Stack <int> st;
    Stack <int> minStack;

    int min = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i] <= min){
            min = arr[i];
            st.push(arr[i]);
            minStack.push(arr[i]);
        }
        else{
            st.push(arr[i]);
        }
    }
    while(!st.empty()){
        if(st.Top()!=minStack.Top()){
            st.pop();
            cout<<minStack.Top()<<" ";
        }
        else{
            cout<<minStack.Top()<<" ";
            st.pop();
            minStack.pop();
        }
    }
}
