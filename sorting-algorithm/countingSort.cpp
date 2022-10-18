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

    //step1-->find the max
    int max = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    //step 2-->declare count array
    int count[max+1]={0};
    //step 3-->count frequency of the given array
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    //step 4-->cumulative sum
    for(int i=1;i<max+1;i++)
    {
        count[i]+=count[i-1];
    }

    //step 5-->traverse main array and accomplish final step
    int sorting_arr[n];
    for(int i=n-1;i>=0;i--)
    {
        count[arr[i]]--;
        int k=count[arr[i]];
        sorting_arr[k] = arr[i];
    }

    cout<<"After sorting: ";
    printArray(sorting_arr,n);

    return 0;

}
