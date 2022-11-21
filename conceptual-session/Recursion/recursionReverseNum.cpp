#include<bits/stdc++.h>

using namespace std;

void fun(int starting){
    //base condition
    if(starting == 6)   return;
    //recursive call
    fun(starting+1);
    //after recursive call
    cout<<starting<<" ";
}
int main()
{
    fun(1);
    return 0;
}
