#include<bits/stdc++.h>
#include"MYHEADER.h"

using namespace std;

int main()
{
    Queue q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int chk;
        cin>>chk;
        q.push(chk);
    }
    while(!q.empty()){
        cout<<q.pop()<<" ";
    }
    cout<<endl;

    return 0;
}
