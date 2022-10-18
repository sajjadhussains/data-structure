#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[])
{
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[6]={7,2,13,2,11,14};

    for(int i=1;i<6;i++)
    {
        cout<<"Iteration no: "<<i<<endl;
        for(int j=0;j<5;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            printArray(arr);
        }
    }

    return 0;
}
