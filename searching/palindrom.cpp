#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,temp,rem,sum;
    cin>>n;
    temp = n;
    sum =0;
    while(n>0)
    {
        rem = n%10;
        sum =(sum*10)+rem;
        n = n/10;
    }
    if(temp == sum)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
