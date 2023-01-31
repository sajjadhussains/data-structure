#include<bits/stdc++.h>

using namespace std;
vector<int>v[20];
bool visit[20];
int numOfHouse(int src)
{
    int count = 0;
    for(auto i:v[src])
    {
        cout<<i<<" ";
        count++;
    }
    return count;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(visit,false,sizeof(visit));
    int src;
    cin>>src;
    int result  = numOfHouse(src);
    cout<<endl<<result<<endl;
    return 0;
}
