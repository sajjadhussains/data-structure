#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k=0;
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }

    for(int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<m;j++)
        {
            if(arr1[i]==arr2[j])
            {
                k=k+1;
                break;
            }
        }
        if(k==0){
            cout<<arr1[i]<<" ";
        }
    }
    cout<<endl;

    return 0;

}
