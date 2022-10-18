#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;
int gloabalId = 100;

class person
{
    string name;
    float salary;
    int id;
public:
    person(){
        name="";
        salary=-1.0;
        id = -1;
    }
    //setter function to access private element
    void setName(string name){
        this->name = name;
    }
    void setSalary(float salary){
        this->salary = salary;
    }
    person(string name,float salary){
        setName(name);
        setSalary(salary);
        id=gloabalId;
        gloabalId++;
    }
    //getter function
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    float getSalary(){
        return salary;
    }
    void print(){
        cout<<name<<" | "<<id<<" | "<<salary<<" | "<<endl;
    }

};
int main()
{
    Stack<person>st;
    person a("akib zaman",654.6);
    person b("Ria akther",200.6);
    person c("Farid Ahmed",354.7);
    st.push(a);
    st.push(b);
    st.push(c);
    while(!st.empty()){
        person printObj;
        printObj = st.pop();
        printObj.print();
    }

    return 0;
}
