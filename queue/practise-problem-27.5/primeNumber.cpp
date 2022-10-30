#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=3;i<=n;i++){
        int count=0;
        if(i==3){
            cout<<2<<" ";
        }
        for(int j=2;j<i;j++)
        {
            if(i%j==0){
                count++;
                break;
            }
        }
        if(count==0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}
