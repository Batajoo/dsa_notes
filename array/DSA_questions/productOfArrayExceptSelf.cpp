#include <bits/stdc++.h>

using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {
    int totalWindow = 1;
    int index = 0;
    int n = nums.size();
    for(int i = index; i<n; i++){
        totalWindow *= nums[i];
    }
    cout << totalWindow << endl;
    int i = 1;
    int j = n - 1;
    vector<int> result;
    result.push_back(totalWindow);
    while(index < n){
        cout << totalWindow << endl;
        totalWindow = totalWindow / nums[(i++ % n)] / nums[index++] * nums[(++j % n)];
        result.push_back(totalWindow);
    }
    return result;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);
    for(int value: result){
        cout << value << " ";
    }
}