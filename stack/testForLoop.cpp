#include<bits/stdc++.h>

using namespace std;

void functionTest(int n)
{
    if(n==0){
        return;
    }
    n--;
    functionTest(n);
    cout<<"Testing"<<endl;
}

int main()
{
    functionTest(5);


    return 0;
}
