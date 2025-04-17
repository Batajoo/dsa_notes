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

vector<int> productExceptSelfPrefixMethod(vector<int> &nums){
    int n = nums.size();

    vector<int> res(n);
    vector<int> prefix(n);
    vector<int> suffix(n);

    prefix[0] = 1;
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] * nums[i-1];
    }

    suffix[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    for(int i=0; i<n; i++){ 
        res[i] = prefix[i] * suffix[i];
    }

    return res;
}

vector<int> productExceptSelfOptimizedPrefixMethod(vector<int> &nums){
    int n = nums.size();

    vector<int> res(n,1);

    for(int i = 1; i<n; i++){
        res[i] = res[i-1] * nums[i-1];
    }

    int postfix = 1;
    for(int i = n-1; i>=0; i--){
        res[i] *= postfix;
        postfix *= nums[i];
    }

    return res;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelfOptimizedPrefixMethod(nums);
    for(int value: result){
        cout << value << " ";
    }
}