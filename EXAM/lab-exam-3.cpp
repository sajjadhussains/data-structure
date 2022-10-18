#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int k=1;k<=test;k++)
    {
        int day;
        cin>>day;
        int arr1[day],arr2[day];
        for(int i=0;i<day;i++)
        {
            cin>>arr1[i];
        }
        for(int i=0;i<day;i++)
        {
            cin>>arr2[i];
        }
        int queries_num;
        cin>>queries_num;

        for(int i=0;i<queries_num;i++)
        {
            int queries,earning=0,spend=0,balance=0;
            cin>>queries;
            for(int i=0;i<=queries;i++)
            {
                earning += arr1[i];
                spend += arr2[i];
            }
            balance = earning - spend;
            if(balance>=0) cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
        cout<<endl;
    }
}
