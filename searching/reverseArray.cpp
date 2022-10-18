#include<bits/stdc++.h>

using namespace std;

void reverseArray(int array[],int size)
{
    for(int i=0,j=size-1;i<j;i++,j--)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int size;
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++)
    {
        cin>>array[i];
    }
    reverseArray(array,size);
    return 0;
}
