#include<bits/stdc++.h>

using namespace std;
int myMax(int arr[],int n)
{
    int maximum = arr[0];
    for(int i=1;i<n;i++)
    {
        if(maximum<arr[i])
        {
            maximum = arr[i];
        }
    }
    return maximum;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k=myMax(arr,n)+1;
    cout<<k<<endl;
    int freq[k]={0};
    for(int i=0;i<n;i++)
    {
        int element = arr[i];
        freq[element]++;
    }

    for(int i=0;i<=n;i++)
    {
        if(freq[i]>0){
            cout<<i<<"->"<<freq[i]<<endl;
        }
    }
    return 0;
}

