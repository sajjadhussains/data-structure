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

//string infixTopostfix(string chk)
//{
//    stack<char> st;
//    string result;
//    for(int i=0;i<chk.length();i++){
//         if(chk[i] >='0' && chk[i]<='9'){
//            result+=chk[i];
//        }
//        else if(chk[i]=='('){
//            st.push(chk[i]);
//        }
//        else if(chk[i] ==')'){
//
//            while( st.top()!='('){
//                    result+=st.top();
//                    st.pop();
//                  }
//                  st.pop();
//        }
//        else{
//            while(!st.empty() && precedenceCalc(st.top())>=precedenceCalc(chk[i])){
//                result+=st.top();
//                st.pop();
//            }
//            st.push(chk[i]);
//        }
//         cout<<"for the '"<<chk[i]<<"' char ,stack is: ";
//        printStack(st);
//        cout<<"       result status: "<<result<<endl;
//    }
//
//    while(!st.empty()){
//            char topElements = st.top();
//            result +=topElements;
//            cout<<endl<<"After pop and add  ("<<topElements<<")  to the result is: "<<result<<endl;
//            st.pop();
//        }
//
//    return result;
//}

int postfixEvaluation(string chk)
{
    stack<char> st;
    for(int i=0;i<chk.length();i++){
            cout<<chk[i]<<" ";
        //chk[i]-->0 to 9 operand
        cout<<"When "<<chk[i]<<" comes,stack is: ";
        if(chk[i]>='0' && chk[i]<='9'){
            st.push(chk[i]);
            printStack(st);
            cout<<endl;
        }
        //chk[i]-->operator

        else{
            int a = st.top()-'0';
            st.pop();
            int b = st.top()-'0';
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
        string postfix="35+*20+-";
        int result = postfixEvaluation(postfix);
        cout<<"postfix is: "<<postfix<<endl;
    return 0;
}
