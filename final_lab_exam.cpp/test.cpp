#include<bits/stdc++.h>

using namespace std;
vector<int>v[20];
bool visit[20];

void bfs(int src,int l)
{
    queue<pair<int,int>>q;
    q.push({src,0});
    while(!q.empty())
    {
        pair<int,int>parent = q.front();
        q.pop();
        if(visit[parent.first] == true)  continue;
        if(parent.second== l){
            cout<<parent.first<<" ";
        }
        for(auto i:v[parent.first])
        {
            int children = i;
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
        int l;
        cin>>l;
        bfs(0,l);
        cout<<endl;
        return 0;
}

