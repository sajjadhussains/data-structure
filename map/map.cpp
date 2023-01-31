#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int,int>M;
    M[3] = 9;
    M[2] = 3;
    M.insert(make_pair(4,10));
    for(auto i:M){
        cout<<i.first<<"|"<<i.second<<endl;
    }
    return 0;
}
