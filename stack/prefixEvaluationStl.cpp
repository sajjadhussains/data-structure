#include<bits/stdc++.h>

using namespace std;

int precedenceCalc(char c)
{
    if(c=='^'){
        return 3;
    }
    else if(c=='/' || c=='*'){
        return 2;
    }
    else if(c=='+' || c== '-'){
        return 1;
    }
    else return -1;
}
void printStack(stack<char> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

string infixToprefix(string chk)
{
    reverse(chk.begin(),chk.end());
    cout<<chk<<endl;
    stack<char> st;
    string result;
    for(int i=0;i<chk.length();i++){
         if(chk[i] >='0' && chk[i]<='9'){
            result+=chk[i];
        }
        else if(chk[i]==')'){
            st.push(chk[i]);
        }
        else if(chk[i] =='('){

            while(!st.empty() && st.top()!=')'){
                    result+=st.top();
                    st.pop();
                  }
                  if(!st.empty()) st.pop();
        }
        else{
            while(!st.empty() && precedenceCalc(st.top())>=precedenceCalc(chk[i])){
                result+=st.top();
                st.pop();
            }
            st.push(chk[i]);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    reverse(result.begin(),result.end());
    return result;
}
int prefixEvaluation(string chk)
{
    stack<char> st;
    for(int i=chk.length()-1;i>=0;i--){
        //chk[i]-->0 to 9 operand
        cout<<"When "<<chk[i]<<" comes,stack is: ";
        if(chk[i]>='0' && chk[i]<='9'){
            st.push(chk[i]-'0');
            printStack(st);
            cout<<endl;
        }
        //chk[i]-->operator

        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            switch(chk[i]){
            case '+':
                st.push(a+b);
                printStack(st);
                cout<<endl;
                break;
            case '-':
                st.push(a-b);
                break;
            case '*':
                st.push(a*b);
                printStack(st);
                cout<<endl;
                break;
            case '/':
                st.push(a/b);
                printStack(st);
                cout<<endl;
                break;
            case '^':
                st.push(pow(a,b));
                printStack(st);
                cout<<endl;
                break;
            default:
                break;
            }
            cout<<endl;
        }
    }
    cout<<"prefix evaluation is: ";
   return st.top();
}

int main()
{
    string infix="(4*(3+5))-(2+0)" ;
    string prefix = infixToprefix(infix);
    cout<<"prefix of the given infix:"<<prefix<<endl;
    cout<<prefixEvaluation(prefix)<<endl;

   return 0;
}
