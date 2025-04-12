#include <bits/stdc++.h>

using namespace std;

// O(n2) time complexity - not optimal solution
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result;
    int n = nums.size();

    for(int i = 0; i<n; i++){
        int total = 1;
        for(int j = 0; j<n; j++){
            if(i!=j)
                total *= nums[j];
        }
        result.push_back(total);
    }

    return result;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);
    for(int value: result){
        cout << value << " - ";
    }
}