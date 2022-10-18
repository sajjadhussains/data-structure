#include<bits/stdc++.h>
#define n 5
using namespace std;
class Queue{
    private:
    int arr[n];
    int r;
    int f;
public:
    Queue(){
        r=-1;
        f=-1;
    }
    void enque(int val){
        int s;
        if(r==-1 && f==-1){
            f++;
            r++;
            arr[r]=val;
        }
        else{
            s = (r+1) % n;
            if(s!=f){
                arr[s]=val;
                r=s;
            }
            else{
                cout<<"Queqe overloaded"<<endl;
            }
        }
    }

    int Deque(){
        if(arr[f]==0 && r==f)
        {
            cout<<"underflow";
            return -1;
        }
        else{
            int retVal = arr[f];
            if(f!=r)    f= (f+1)%n;
            else arr[f] = 0;
            return retVal;
        }
    }
    void print()
	{
		int cnt = (r + n - f) % n + 1;
		cout << "Queue: ";
		for (int i = 0; i < cnt; i++)
		{
			int idx = (f + i) % n;
			cout << arr[idx] << " ";
		}
		cout << "\n\n";
	}
};
int main()
{
    Queue q;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.Deque();
    q.print();

    return 0;
}
