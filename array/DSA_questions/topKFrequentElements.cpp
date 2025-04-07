#include <bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k);

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = topKFrequent(nums,k);
    for(auto res: result){
        cout << res << " ";
    }
    return 0;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for(int n: nums){
        count[n]++;
    }

    vector<pair<int, int>> arr;
    for(const auto p: count){
        arr.push_back({p.second, p.first});
    }
    sort(arr.rbegin(), arr.rend());

    vector<int> result;
    for(int i=0; i<k; i++){
        result.push_back(arr[i].second);
    }

    return result;
}