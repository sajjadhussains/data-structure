#include<bits/stdc++.h>

using namespace std;

void findTheValue(int array[],int size,int x)
{
    int flag = 0;
    cout<<"Found at index position: ";
    for(int i=0;i<size;i++)
    {
        if(array[i]==x)
        {
            cout<<i<<",";
            flag=1;
        }
    }
    if(flag<1)
    {
        cout<<"Not Found"<<endl;
    }
}

int main()
{
    int n;
    cout<<"give the size of the array: ";
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int checkValue;
    cout<<"which value you want to check: ";
    cin>>checkValue;
    findTheValue(arr,n,checkValue);
}
