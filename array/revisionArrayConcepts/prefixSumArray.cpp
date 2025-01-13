#include <iostream>

using namespace std;

void fillPrefixSum(int * arr, int n, int * pSum){
    pSum[0] = arr[0];
    for(int i=1; i<n; i++){
        pSum[i] = pSum[i-1] + arr[i];
    }
}

int main()
{
    int arr[] = { 10, 4, 16, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int prefixSum[n];
   
      // Function call
    fillPrefixSum(arr, n, prefixSum);
    for (int i = 0; i < n; i++)
        cout << prefixSum[i] << " ";
}