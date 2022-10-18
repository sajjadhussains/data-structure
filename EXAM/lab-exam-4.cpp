#include<bits/stdc++.h>

using namespace std;

int main()
{
    int row,col,k=0;
    cin>>row>>col;
    int new_arr[num_of_elements];
    int arr[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int element = arr[i][j];
            new_arr[k]=element;
            k++;
        }
    }
    for(int i=0;i<k-1;i++)
    {
        int element = new_arr[i];
        for(int j=i+1;j<k;j++)
        {
            if(element==new_arr[j])
            {
                new_arr[j]=-1;
            }
        }
    }
    int m=0;
    for(int i=0;i<k;i++)
    {
       cout<<new_arr[i]<<"\t";
       m++;
       if(col==m){
        cout<<endl;
        m=0;
       }
    }
    cout<<endl;
    return 0;
}

