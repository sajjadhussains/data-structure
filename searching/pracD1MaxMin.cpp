#include<bits/stdc++.h>

using namespace std;

void maximum(int array[],int size)
{
    int max=array[0];
    int index = 0;
    for(int i=1;i<size;i++)
    {
        if(max<array[i])
        {
            max = array[i];
            index = i;
        }
    }
    cout<<"Max: "<<max<<", Index:"<<index<<endl;
}
void minimum(int array[],int size)
{
    int min=array[0];
    int index = 0;
    for(int i=1;i<size;i++)
    {
        if(min>array[i])
        {
            min = array[i];
            index = i;
        }
    }
    cout<<"Minimum: "<<min<<", Index:"<<index<<endl;
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
    maximum(array,size);
    minimum(array,size);
    return 0;
}
