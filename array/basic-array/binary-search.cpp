#include<bits/stdc++.h>

using namespace std;

int binarySearch(int low,int high,int arr[],int value){
    if(low>high){
        return -1;
    }
    int mid =low + (high-low)/2;
    if(arr[mid]==value){
        return mid;
    }
    else if(arr[mid]<value){
       return binarySearch(mid+1,high,arr,value);
    }
    else{
        return binarySearch(low,mid-1,arr,value);
    }
    
}
int main()
{
    int arr[50];
    int sz;
    cin>>sz;
    for(int i=0;i<sz;i++){
        cin>>arr[i];
    }
    int value;
    cin>>value;
    int result = binarySearch(0,sz-1,arr,value);
    if(result ==-1){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"found at index "<<result<<endl;
    }

    return 0;
}