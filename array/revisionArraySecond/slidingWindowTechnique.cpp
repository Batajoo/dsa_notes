#include <iostream>

using namespace std;

/*
This technique is commonly used in algorithms like 
    - finding subarrays with a specific sum, 
    - finding the longest substring with unique characters, 
    - or solving problems that require a fixed-size window to process elements efficiently.

Two types of sliding window technique:
    - Fixed Sized Sliding Window
    - Variable Size Sliding Window

How to Identify Sliding Window Problems:
    These problems generally require Finding Maximum/Minimum Subarray, Substrings which satisfy some specific condition.
    The size of the subarray or substring ‘K’ will be given in some of the problems.
    These problems can easily be solved in O(N2) time complexity using nested loops, using sliding window we can solve these in O(n) Time Complexity.
    *Required Time Complexity: O(N) or O(Nlog(N))
    *Constraints: N <= 106 , If N is the size of the Array/String.
*/

// use cases of sliding window technique

// 1. To find the maximum sum of all subarrays of size K:
void findMaximumSumOfAllSubarraysSizeK();


// main program execution 
int main (){
    findMaximumSumOfAllSubarraysSizeK();

    return 0;
}

int maxSum(int arr[], int n, int k){
    if(n < k) return -1;

    int maxSum = 0;

    //growing the window
    for(int i=0; i<k;i++){
        maxSum += arr[i];
    }

    int f = 0;
    int l = k-1;

    int currentSum = maxSum;

    while(l<n-1){
        
        currentSum = currentSum - arr[f++] + arr[++l];
        if(currentSum > maxSum) maxSum = currentSum;
    }

    return maxSum;
}

int maxSumSlidingWindow2(int arr[], int n, int k){
    if(n < k) return -1;

    int maxSum = 0;
    for(int i=0; i<k; i++){
        maxSum += arr[i];
    }
    int window_sum = maxSum;
    for(int i=k; i<n;i++){
        window_sum += arr[i] - arr[i-k];
        maxSum = max(window_sum, maxSum);
    }
    return maxSum;
}

void findMaximumSumOfAllSubarraysSizeK(){
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSumSlidingWindow2(arr, n, k);
}
