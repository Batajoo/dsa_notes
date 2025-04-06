#include <iostream>
#include <vector>
#include <algorithm>

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
    
}