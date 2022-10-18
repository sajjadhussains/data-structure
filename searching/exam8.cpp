#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;

    int first = s.find_first_of('A');
    int second = s.find_last_of('Z');
    cout<<(second-first)+1<<endl;
    return 0;
}
