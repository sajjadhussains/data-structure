#include<bits/stdc++.h>

using namespace std;
vector<int>V[20];
vector<bool>visit[20];

void bfs(int src)
{
    queue<pair<int,int>>q;
    q.push({src,0});
    while(!q.empty())
    {
        pair<int,int>parent = q.front();
        q.pop();
        if(visit[parent.first] == true) continue;
        cout<<parent.first<<":"<<parent.second<<endl;
        for(int i=0;i<v[parent.first].size();i++)
        {
            int children = v[parent.first][i];
            if(visit[children] == false) q.push({children,parent.second+1});
        }
        visit[parent.first] = true;
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
        bfs(0);
        return 0;
}
