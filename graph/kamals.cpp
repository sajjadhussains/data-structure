#include<bits/stdc++.h>

using namespace std;
vector<int>v[20];
bool visit[20];

int bfs(int src)
{
    queue<int>q;
    q.push(src);
    int count=0;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        if(visit[parent]==true) continue;
        count++;
        for(auto i:v[parent])
        {
            int children=i;
            if(visit[children] == false)    q.push(children);
        }
        visit[parent] = true;
    }
    return count;
}

int main()
{
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    memset(visit,false,sizeof(visit));
    int k;
    cin>>k;
    int result = bfs(k);
    cout<<result-1<<endl<<endl;

    return 0;
}
