#include<bits/stdc++.h>

using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
}
void printShop(vector<int>adj[],int l)
{
    if(l==0) cout<<"0"<<endl;
    else{
        for(auto k:adj[l-1]){
        cout<<k<<" ";
    }
    }
    cout<<endl;
}
int main()
{
     int V,E;
    cin>>V>>E;
    vector<int>adj[V];
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    int l;
    cin>>l;
    printShop(adj,l);
    return 0;
}
