#include<bits/stdc++.h>

using namespace std;
//what is linear search?--->Linear search is a searching algorithm,which search one by one from an array.it's time complexity is o(n);

void printArray(int arr[],int sz){
    for(int i=0;i<sz;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int sz,arr[50];
    cin>>sz;
    for(int i=0;i<sz;i++){
        cin>>arr[i];
    }

    char c;
    cin>>c;
    while(toupper(c)=='Y'){
        int checkValue;
        cin>>checkValue;
        int flag = 0;
        for(int i=0;i<sz;i++){
            if(arr[i]==checkValue){
                flag=1;
                cout<<"Index No: "<<i<<" position"<<endl;
                break;
            }
        }
        if(flag==0){
            cout<<"Not Found"<<endl;
        }
        cout<<"Do you wnat to continue Searching: (Y/N)";
        cin>>c;
    }

    printArray(arr,sz);

    return 0;

}