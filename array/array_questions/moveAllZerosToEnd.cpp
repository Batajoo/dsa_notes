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

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);

    // Print the modified array
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}