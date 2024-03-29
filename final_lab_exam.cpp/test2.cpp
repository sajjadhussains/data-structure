#include<bits/stdc++.h>

using namespace std;
vector<int>v[100];
bool visit[100];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        if(visit[parent] == true) continue;
        cout<<parent<<endl;
        for(int i=0;i<v[parent].size();i++){
            int children = v[parent][i];
            if(visit[children] == false) q.push(children);
        }
        visit[parent] = true;
    }
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
       bfs(1);
        return 0;
}
