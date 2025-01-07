#include <bits/stdc++.h>

using namespace std;

int minOps(std::vector<int> &arr, int k){
    int max = 0;
    int n = arr.size();
    int count=0;
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }

    for(int i=0; i<n; i++){
        if((max - arr[i]) % k != 0 ){
            return -1;
        }
        count += (max - arr[i])/k;
    }

    return count;
}

int main() {
    vector<int> arr = { 21, 33, 9, 45, 63 };
    int k = 6;

    cout << minOps(arr, k) <<endl;
    return 0;
}