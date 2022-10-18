#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    cout<<"Before sorting: ";
    printArray(arr,n);

    //insertion sort implement
    for(int i=1;i<n;i++)
    {

        int key = arr[i];
        cout<<"i :"<<i<<" key: "<<key<<endl;
        int j=i-1;
        while(arr[j]>key && j>=0)
        {
            arr[j+1] = arr[j];
            printArray(arr,n);
            j--;
        }
        arr[j+1] = key;
        printArray(arr,n);
    }
    cout<<"After sorting: ";
    printArray(arr,n);

    return 0;

}
