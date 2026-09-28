#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[50],size;
    cin>>size;

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    //implement bubble sort

    for(int i=1;i<size;i++){
        cout<<i<<"th iteration"<<endl;
        int flag = 0;
        for(int j=0;j<size-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=1;
            }
            printArray(arr,size);
        }
        if(flag == 0){
            break;
        }
    }

    printArray(arr,size);

    return 0;
}