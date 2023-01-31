#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int maximum= arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>maximum)  maximum=arr[i];
    }
    int maxi = maximum+1;
    int chk[maxi]={0};
    for(int i=0;i<n;i++){
            chk[arr[i]]++;
    }
    for(int i=0;i<maxi;i++){
            int element = chk[i];
        if(element>0){
            cout<<i<<"found "<<element<<"times"<<endl;
        }
    }
    return 0;
}
