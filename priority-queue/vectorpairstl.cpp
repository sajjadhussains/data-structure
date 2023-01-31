#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> PAIR;
int main()
{
  vector<int>V(5,-5);
  //normal way printing vector like an array
  for(int i=0;i<V.size();i++){
    cout<<V[i]<<" ";
  }
  cout<<endl;
  //printing with iterator
  vector<int>::iterator it;
  for(it = V.begin();it!=V.end();it++)
  {
      cout<<*it*2<<" ";
  }
  cout<<endl;
  //auto register in range based traversal
  for(auto element:V){
    cout<<element*3<<" ";
  }
  cout<<endl;
  //auto register in place of iterator
  for(auto it=V.begin();it!=V.end();it++)
  {
      cout<<*it*4<<" ";
  }
  cout<<endl;

  priority_queue<PAIR,vector<PAIR>,greater<PAIR>>PQ;
  PQ.push(make_pair(1,9));
  PQ.push(make_pair(6,2));
  PQ.push(make_pair(4,1));
  while(!PQ.empty()){
    cout<<PQ.top().first<<"|"<<PQ.top().second<<endl;
    PQ.pop();
  }

  return 0;
}
