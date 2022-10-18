#include<stdio.h>
int main()

{

    int n;

    cin>>n;

    int count_divided_by_two=0;

    while(n%2==0)

    {

        count_divided_by_two++;

        n/=2;

    }

    cout<<count_divided_by_two<<endl;

}
