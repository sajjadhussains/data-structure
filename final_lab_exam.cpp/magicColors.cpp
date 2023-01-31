#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<=t;i++)
    {
        int n;
        cin>>n;
        string s="";
        for(int i=0;i<n;i++)
        {
            char c;
            cin>>c;
            s+=c;
        }
        string result1="";
         for(int i=0;i<n;i+=2)
         {
             if((s[i]=='R' && s[i+1] =='B') || (s[i]=='B' && s[i+1] =='R') ) result1+='P';
             else if((s[i]=='R' && s[i+1] =='G') || (s[i]=='G' && s[i+1] =='R') ) result1+='Y';
             else if((s[i]=='B' && s[i+1] =='G') || (s[i]=='G' && s[i+1] =='B') ) result1+='C';
             else {
                    result1+=s[i];
                    if(s[i+1]) result1+=s[i+1];
                    };
         }
         int pCount=0,yCount=0,cCount=0,rCount=0,gCount=0,bCount=0;
         for(int i=0;i<result1.length();i++)
         {
             if(result1[i]=='P') pCount++;
             if(result1[i]=='Y') yCount++;
             if(result1[i]=='C') cCount++;
             if(result1[i]=='G') gCount++;
             if(result1[i]=='R') rCount++;
             if(result1[i]=='B') bCount++;
         }
         int pRem=pCount%2,yRem=yCount%2,cRem=cCount%2,rRem=rCount%2,gRem=gCount%2,bRem=bCount%2;
         string result2="";
         for(int i=0;i<result1.length();i++)
         {
             if(result1[i]=='P' &&  pRem==1){
                result2+=result1[i];
                pRem++;
             }
              if(result1[i]=='Y' &&  yRem==1){
                result2+=result1[i];
                yRem++;
             }
              if(result1[i]=='C' &&  cRem==1){
                result2+=result1[i];
                cRem++;
             }
              if(result1[i]=='R' &&  rRem==1){
                result2+=result1[i];
                rRem++;
             }
              if(result1[i]=='G' &&  gRem==1){
                result2+=result1[i];
                gRem++;
             }
              if(result1[i]=='B' &&  bRem==1){
                result2+=result1[i];
                bRem++;
             }
         }
         cout<<result2<<endl;
    }

    return 0;
}
