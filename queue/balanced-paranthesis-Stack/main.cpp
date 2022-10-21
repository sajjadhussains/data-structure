#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

bool balancedParenthesis(string s)
{
    int n = s.size();
    bool isBalanced = true;
    Stack <char> st;
    if(s[0]==')' || s[0]=='}'||s[0]==']') return false;
    for(int i=0;i<n;i++)
    {
        //opening bracket->(,{,[
        if(s[i]=='(' || s[i]=='{' || s[i] == '[')
            {
                st.push(s[i]);
            }
        //closing bracket->
        else if(s[i]==')'){
            if(st.Top()=='(')
            {
                st.pop();
            }
            else{
                isBalanced = false;
                break;
            }
        }
         else if(s[i]=='}'){
            if(st.Top()=='{')
            {
                st.pop();
            }
            else{
                isBalanced = false;
                break;
            }
        }
         else if(s[i]==']'){
            if(st.Top()=='[')
            {
                st.pop();
            }
            else{
                isBalanced = false;
                break;
            }
        }
    }
    if(!st.empty()){
        isBalanced = false;
    }
    return isBalanced;
}
int main()
{
    string chk;
    cin>>chk;
    if(balancedParenthesis(chk))   cout<<"Yes";
    else cout<<"NO";
    cout<<endl;

    return 0;
}
