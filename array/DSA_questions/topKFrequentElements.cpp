#include <bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k);
vector<int> topKFrequentBucketSort(vector<int>& nums, int k);

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = topKFrequentBucketSort(nums,k);
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


vector<int> topKFrequentBucketSort(vector<int>& nums, int k){
    unordered_map<int, int> count;
    vector<vector<int>> freq(nums.size() + 1);

    for(int n : nums){
        count[n]++;
    }

    for(const auto it: count){
        freq[it.second].push_back(it.first);
    }

    vector<int> result;
    for(int i = freq.size()-1; i > 0; i--){
        for(int j = 0; j < freq[i].size(); j++){
            result.push_back(freq[i][j]);
            if(result.size() == k) return result;
        }
    }

    return result;
}