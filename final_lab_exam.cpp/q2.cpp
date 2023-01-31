#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printShop(vector<int>adj[],int v,int l)
{
      if(l==0){
        cout<<l<<endl;
        return;
      }
      int ans=false;
      int m;
      for(int i=0;i<v;i++){
        for(auto j:adj[i]){
            if(j==l){
                m=i;
                ans=true;
                break;
            }
        }
        if(ans) break;
      }
      for(auto k:adj[m]){
        cout<<k<<" ";
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
     printShop(adj,V,l);

    return 0;
}
