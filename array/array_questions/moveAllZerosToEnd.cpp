#include<bits/stdc++.h>

using namespace std;

void pushZerosToEnd(std::vector<int> &arr){
    std::vector<int> temp;
    int zerosCount = 0;
    for(const auto &num: arr){
        if(num != 0){
            temp.push_back(num);
        } else {
            zerosCount++;
        }
    }
    while(zerosCount>0){
        temp.push_back(0);
        zerosCount--;
    }

    temp.swap(arr);
}

// two traversal approach
void pushZerosToEnd2(std::vector<int> &arr){
    int nonZeroCount = 0;
    int n = arr.size();
    for(int i=0;i<n; i++){
        if(arr[i] != 0){
            arr[nonZeroCount++] = arr[i];
        }
    }

    while(nonZeroCount < n){
        arr[nonZeroCount++] = 0;
    }
}

//one traversal approach

void pushZerosToEnd3(std::vector<int> &arr){
    int nonZeroCount = 0; 
    int n = arr.size();

    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            std::swap(arr[i], arr[nonZeroCount]);
            nonZeroCount++;
        }
    }
}

void pushZerosToEnd4(vector<int> &arr){
    stable_partition(arr.begin(), arr.end(), [](int n){
        return n!=0;
    });
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd4(arr);

    // Print the modified array
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}