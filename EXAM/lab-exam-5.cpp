#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    int mid=n/2;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i][mid];
        sum+=arr[mid][i];
    }

    for(int i=0;i<mid;i++)
    {
        sum+=arr[0][i];
        sum+=arr[i][n-1];
    }

    for(int i=n-1;i>mid;i--)
    {
        sum+=arr[i][0];
        sum+=arr[n-1][i];
    }

    sum-=arr[mid][mid];
    cout<<sum<<endl;
    return 0;
}
