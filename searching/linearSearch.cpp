#include<bits/stdc++.h>

using namespace std;

int main()
{
    int size;
    cout<<"give the size of array: ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    char c;
    cout<<"Do you want to search: (Y/N)";
    cin>>c;
    while(toupper(c) == 'Y')
    {
        cout<<"which value you want to check: ";
    int checkValue;
    cin>>checkValue;
    int flag = 0;
    for(int i=0;i<size;i++)
    {
        if(arr[i] == checkValue){
            cout<<i<<endl;
            flag = 1;

        }
    }
    if(flag == 0)
    {
        cout<<"didn't found your given element"<<endl;
        cout<<"Do you want to continue: (Y/N)";
        cin>>c;
    }
}

    return 0;
}
