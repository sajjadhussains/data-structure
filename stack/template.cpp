#include<bits/stdc++.h>

using namespace std;

template<typename T1,typename T2>
T2 sum(T1 a,T1 b)
{
    T2 result = (a+b)*2.3;
    return result;
}

int main()
{
    cout<<sum<int,double>(10,20)<<endl;
    return 0;
}
