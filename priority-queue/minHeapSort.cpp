#include<bits/stdc++.h>

using namespace std;
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int array[],int n,int current){
    int smallest = current;
    int leftChild = 2*current+1;
    int rightChild = 2*current + 2;
    if(leftChild<n && array[leftChild]<array[smallest]){
        smallest = leftChild;
    }
    if(rightChild<n && array[rightChild]<array[smallest]){
        smallest = rightChild;
    }
    if(smallest !=current){
        swap(array[current],array[smallest]);
        heapify(array,n,smallest);
    }
}
void printArray(int arr[],int n){
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
string orderName(int num){
    string name;
    switch(num){
        case 1:
            name="st";
            break;
            case 2:
                name = "nd";
                break;
            case 3:
                name ="rd";
                break;
            default:
                name="th";
                break;
    }
    return name;
}
void heapSort(int array[],int size){
    int count = 1;
    for(int i=size-1;i>=0;i--){
        swap(array[0],array[i]);
        heapify(array,i,0);
         cout<<"after heapify in heapsort->"<<endl<<count<<orderName(count)<<" iteration is:";
         printArray(array,size);
         cout<<endl;
        count++;
    }
}

int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    int nonLeafStart = (n/2)-1;
    for(int i=nonLeafStart;i>=0;i--)
    {
        heapify(array,n,i);
    }
    cout<<endl<<endl;
    cout<<"after heapify:";
    printArray(array,n);
    heapSort(array,n);
    cout<<endl<<"after heapsort:";
    printArray(array,n);
    return 0;
}

