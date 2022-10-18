#include<bits/stdc++.h>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //Code

   int t;
   cin>>t;

   for(int test=1;test<=t;test++)
   {
        int n;
       unsigned short q;
       cin>>n>>q;
       int arr[n];
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       //cout<<"\n";
       cout<<"Case "<<test<<":"<<"\n";
       for(int i=1;i<=q;i++)
       {
           int l,j;
           cin>>l>>j;
           int minimum = arr[l-1];
           for(int k=l-1;k<j-1;k++)
           {
               if(minimum>arr[k+1])
               {
                   minimum = arr[k+1];
               }
           }

           cout<<minimum<<"\n";
       }
   }

  return 0;
}

