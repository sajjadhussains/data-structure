#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0,j=m-1;i<=j;i++,j--)
    {
        for(int row=0;row<n;row++)
        {
           int temp =arr[row][i];
           arr[row][i] = arr[row][j];
           arr[row][j] = temp;
        }
    }

    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
