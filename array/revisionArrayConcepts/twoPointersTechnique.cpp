#include <iostream>
#include <vector>

using namespace std;

bool twoSum(vector<int> &arr, int target){
    int left = 0; 
    int right = arr.size() - 1;

    while(left < right){
        int sum = (arr[left] + arr[right]);
        if(target == sum){
            return true;
        }
        else if (target < sum){
            right--;
        } else {
            left++;
        }
    }
    return false;
}

int main(){
    vector<int> arr = {-3, -1, 0, 1, 2};
    int target = -2;
    if (twoSum(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}