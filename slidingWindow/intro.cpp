#include<iostream>
#include <vector>

using namespace std;

int maxSum(vector<int> &arr, int k){
    int n = arr.size();
    
    if(n <= k){
        cout << "Invalid";
        return -1;
    }

    int max_sum = 0;
    for(int i = 0; i<k; i++){
        max_sum += arr[i];
    }

    int window_sum = max_sum;
    for(int i=k; i<n; i++){
        window_sum += arr[i];
        window_sum -= arr[i - k];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

int main(){
    vector<int> arr = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;

    cout << maxSum(arr, k) << endl;
    return 0;
}