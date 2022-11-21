#include<bits/stdc++.h>

using namespace std;
int fun(int val){
    if(val==5)  return 5;//or,if(val==6)    return 0;
    int smaller_sum = fun(val+1);
    int total_sum = smaller_sum + val;
    return total_sum;
}
//2
int main()
{
    int sum = fun(1);
    printf("%d",sum);
    return 0;
}
