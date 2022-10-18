#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin>>t;

    for(int test=1;test<=t;test++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        for(int i=1;i<n;i++)
        {
            int flag =0;
            for(int j=0;j<n-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    flag = 1;
                }
            }
            if(flag == 0) break;
        }
        int ind = 0;
        for(int k = 0;k<n-1;k++)
        {
            if(arr[k]!=arr[k+1])
            {
               break;
            }
            else{
                ind++;
            }
        }
        int index = ind+1;
        int del = n-index;
        cout<<del<<endl;
    }
    return 0;
}
