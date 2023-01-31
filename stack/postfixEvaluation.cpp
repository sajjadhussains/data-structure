#include<bits/stdc++.h>

using namespace std;
void printStack(stack<int> st)
{
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int postfixEvaluation(string chk)
{
    stack<int>st;
    for(int i=0;i<chk.length();i++)
    {
        if(chk[i]>='0' &&  chk[i]<='9')
        {
            st.push(chk[i]-'0');
            cout<<"For '"<<chk[i]<<"' the stack is: ";
            printStack(st);
        }
        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
             switch(chk[i]){
            case '+':
                st.push(b+a);
                break;
            case '-':
                st.push(b-a);
                break;
            case '*':
                st.push(a*b);
                break;
            case '/':
                st.push(b/a);
                break;
            case '^':
                st.push(pow(b,a));
                break;
            default:
                break;
            }
            cout<<"For '"<<chk[i]<<"' the stack is: ";
            printStack(st);
        }
    }
    return st.top();
}



int main()
{
    string postfix="562^726/-+*781+*54*+-";
    int result = postfixEvaluation(postfix);
    cout<<endl<<"The prefix evaluation is: "<<result;
    return 0;
}
