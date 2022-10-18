#include<bits/stdc++.h>

using namespace std;

int binarySearch(int array[],int x,int low,int high)
{
    int mid = (low + high)/2;
    if(low<=high)
    {
        if(array[mid] == x)     return mid;
        else if(x > array[mid])
        {
            binarySearch(array,x,mid+1,high);
        }
        else{
            binarySearch(array,x,low,mid-1);
        }
    }
    else{
        return -1;
    }
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
    int checkValue;
    cout<<"give which value you want to check: ";
    cin>>checkValue;
    int indexNumber = binarySearch(array,checkValue,0,size-1);
    if(indexNumber != -1)
    {
        cout<<"index Number:"<<indexNumber<<", Position at: "<<indexNumber+1<<endl;
    }
    else{
        cout<<"didn't found the element"<<endl;
    }
    return 0;

}
