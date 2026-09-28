#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[50], size;
    cin >> size;

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    // Find maximum
    int max = arr[0];

    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    // Count array
    int count[max + 1];

    for(int i = 0; i <= max; i++){
        count[i] = 0;
    }

    // Frequency
    for(int i = 0; i < size; i++){
        count[arr[i]]++;
    }

    // Cumulative sum
    for(int i = 1; i <= max; i++){
        count[i] = count[i - 1] + count[i];
    }

    // Final array
    int final[size];

    for(int i = size - 1; i >= 0; i--){
        int k = count[arr[i]] - 1;
        final[k] = arr[i];
        count[arr[i]]--;
    }

    // Print
    for(int i = 0; i < size; i++){
        cout << final[i] << " ";
    }

    cout << endl;

    return 0;
}