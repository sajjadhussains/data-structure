#include<bits/stdc++.h>

using namespace std;

void prefixArray(int pre_arr[],int arr[],int size)
{
        pre_arr[0] = arr[0];
        for(int i=1;i<size;i++)
        {
            pre_arr[i] = arr[i] + pre_arr[i-1];
        }
}
int main()
{
    int t;
    cin>>t;

    for(int test=1;test<=t;test++)
    {
        cout<<"Case: "<<test<<endl;
        int n,q;
        cin>>n>>q;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int pre_arr[n];

        prefixArray(pre_arr,arr,n);

        for(int i=1;i<=q;i++)
        {
            int l;
            cin>>l;
            if(l==1)
            {
                int ind;
                cin>>ind;
                cout<<arr[ind]<<endl;
                arr[ind] = 0;
                prefixArray(pre_arr,arr,n);
            }
            if(l==2)
            {
                int ind,value;
                cin>>ind>>value;
                arr[ind] = arr[ind] + value;
                prefixArray(pre_arr,arr,n);
            }
            if(l==3)
            {
                int ind1,ind2,sum;
                cin>>ind1>>ind2;
                if(ind1==0)
                {
                    sum = pre_arr[ind2];
                }
                else
                {
                    int sum = pre_arr[ind2] - pre_arr[ind1-1];
                }
                cout<<sum<<endl;
            }
        }

    }
    return 0;
}
