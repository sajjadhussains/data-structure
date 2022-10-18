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

        int element_count[1001]={0};
        for(int i=0;i<n;i++)
        {
            int element = arr[i];
            element_count[element]++;
        }
        int max_value = element_count[1];
        for(int i=2;i<1001;i++)
        {
           int value = element_count[i];
           if(max_value<value)
           {
               max_value = value;
           }
        }
        int ans = n - max_value;
        cout<<ans<<endl;
    }
    return 0;
}
