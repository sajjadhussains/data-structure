#include<bits/stdc++.h>

using namespace std;

//WAP that will take n integer numbers into an array, and then sum up all the integers in that array.
//
//Sample input
//Sample output
//5
//1  2  3  4  5
//15
//6
//2  8  3  9  0  1
//23

void sumOfArray(int array[],int size)
{
    int sum = 0;
    for(int i=0;i<size;i++)
    {
        sum = sum + array[i];
    }
    cout<<"Sum is: "<<sum<<endl;
}
void evenIndexPosition(int array[],int size)
{
    int sum = 0;
    for(int i=0;i<size;i++)
    {
        if(i%2==0)
        {
            sum += array[i];
        }
    }
    cout<<"sum of the array is: "<<sum<<endl;
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
    evenIndexPosition(array,size);
    return 0;
}
