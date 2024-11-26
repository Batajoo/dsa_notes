#include <iostream>
#include <vector>
#include <algorithm>

int binarySearchRecursive(std::vector<int> arr, int element, int low, int high){
    // int mid = (low + high)/2; it may cause int overflow for large array sets
    int mid = low + (high - low)/2;
    while(low<=high){
        if(arr[mid]==element){
            return mid;
        } 
        else if(arr[mid]>element){
            return binarySearchRecursive(arr, element, low, mid-1);
        }
        else {
            return binarySearchRecursive(arr, element, mid+1, high);
        }
    }
    return -1;
}

int binarySearchIterative(const std::vector<int> arr, int element){
    int low = 0;
    int high = arr.size() - 1;
    while(low < high) {
        int mid = low + (high - low)/2;

        if(arr[mid] == element) return mid;
        else if (arr[mid] < element) low = mid + 1;
        else high = mid -1;
    }
    return -1;
}

void display(std::vector<int> arr){
    std::cout << "------------------------" << std::endl;
    for(int i=0; i<arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "------------------------" << std::endl;
}

int main(){
    std::vector<int> nums = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int first = 0;
    int last = nums.size()-1;
    int valueSeaching = 1;
    display(nums);
    std::sort(nums.begin(), nums.end());
    display(nums);
    std::cout << "Binary Search Recursive index value => " << binarySearchRecursive(nums, valueSeaching, first, last) << std::endl;
    std::cout << "Binary Search Iterative index value => " << binarySearchIterative(nums, valueSeaching) << std::endl;
    return 0;
}