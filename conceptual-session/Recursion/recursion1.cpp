#include<bits/stdc++.h>

using namespace std;

void fun(int starting){
    //base condition
    if(starting ==6) return;
    cout<<starting<<" ";
    fun(starting+1);
}
int main()
{
    fun(1);
    return 0;
}
