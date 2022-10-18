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

    int sqrr = sqrt(n);
    int ind = 0;
    while(ind<n)
    {
        for(int i=0;i<sqrr;i++)
        {
            cout<<arr[ind]<<" ";
            ind++;
        }
        cout<<endl;
    }
    return 0;
}
