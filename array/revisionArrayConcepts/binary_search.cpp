#include <bits/stdc++.h>

using namespace std;

int binarySearchIterative(int * arr, int low, int high, int value){
    int mid;
    while(low <= high){
        mid = low + (high - low)/2;
        if(arr[mid]==value) return mid;
        else if (arr[mid] < value) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int * arr, int low, int high, int value){
    int mid = low + (high - low)/2;
    
    if(arr[mid]==value) return mid;
    else if (arr[mid]<value) return binarySearchRecursive(arr, mid+1, high, value);
    else return binarySearchRecursive(arr, low, mid-1, value);

    return -1;
}


int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    //iterative approach
    // int result = binarySearchIterative(arr, 0, n - 1, x);
    // if(result == -1) cout << "Element is not present in array";
    // else cout << "Element is present at index " << result << endl;
    // return 0;

    //recursive approach 
    int result2 = binarySearchRecursive(arr, 0, n - 1, x);
    if(result2 == -1) cout << "Element is not present in array";
    else cout << "Element is present at index " << result2 << endl;
    return 0;
}