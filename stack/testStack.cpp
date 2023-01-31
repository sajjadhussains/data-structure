#include<bits/stdc++.h>

using namespace std;
void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main()
{
  stack<int>st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  printStack(st);
  return 0;
}
