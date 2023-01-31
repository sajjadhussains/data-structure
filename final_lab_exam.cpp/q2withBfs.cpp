#include<bits/stdc++.h>

using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
    void BFS(vector<int>adj[],int source,int V,int l)
    {
        int level = 0;
        vector<bool> visited(V,false);
        queue<int>Q;
        visited[source] = true;
        Q.push(source);
        if(l==level) cout<<l<<" "<<endl;
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            level++;
            for(auto element:adj[u]){
                int v = element;
                if(visited[v] != true){
                    visited[v] = true;
                    Q.push(v);
                    if(level==l){
                        cout<<v<<" ";
                    }
                }
            }
        }
        cout<<endl;
    }
int main()
{
     int V,E,source=0;
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
    BFS(adj,source,V,l);
     cout<<endl;
    return 0;
}
