#include<bits/stdc++.h>

using namespace std;

void PrintArray(int arr[],int sz)
{
    for(int i=0;i<sz;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[50];
    int sz,pos,value;
    cin>>sz;
    for(int i=0;i<sz;i++)
    {
        cin>>arr[i];
    }
    PrintArray(arr,sz);
    cout<<"Position of the insertion: ";
    cin>>pos;
    cout<<"Value of the insertion: ";
    cin>>value;
    if(pos<0 || pos>sz)
    {
        cout<<"Invalid position"<<endl;
    }
    else
    {
        //for insertion
//        for(int i=sz-1;i>=pos;i--)
//        {
//            arr[i+1] = arr[i];
//        }
//        arr[pos] = value;
//         arr[sz] = arr[pos];
//         arr[pos] = value;
    //for deletion
    if(pos == sz-1) sz--;
    for(int i=pos+1;i<sz;i++)
    {
        arr[i-1] = arr[i];
    }
    sz--;
    }
    PrintArray(arr,sz);
    return 0;
}
