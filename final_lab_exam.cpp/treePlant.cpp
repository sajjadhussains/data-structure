#include<bits/stdc++.h>

using namespace std;

int main()
{
    int y;
    long long int ans=1,value=0,element=2;
    cin>>y;
    if(y==1) ans=1;
    else if(y==2) ans=2;
    else{
        for(int i=0;i<y-1;i++){
            if(i<=1) value+=1;
            else{
                if(i==2){
                    value+=element;
                }
                else{
                    element*=2;
                    value+=element;
                }
            }
        }
    }
    if(y==1) ans=1;
    else if(y==2) ans=2;
    else{
        int multiple = value*2;
        ans = value * multiple;
    }
    cout<<ans<<endl;
    return 0;
}
