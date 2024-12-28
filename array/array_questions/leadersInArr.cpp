#include <bits/stdc++.h>

using namespace std;

//nested loop
std::vector<int> leaders(std::vector<int> &v){
    std::vector<int> leader;
    int n = v.size();

    for(int i=0; i<n; i++){
        int j;
        for(j=i+1; j<n; j++){
            if(v[j]>v[i]){
                break;
            }
        }
        if(j==n){
            leader.push_back(v[i]);
        }
    }
    return leader;
}


//using suffix Maximum
std::vector<int> leadersSuffixMax(std::vector<int> &arr){
    std:vector<int> temp;
    int n = arr.size();
    int sufMax = arr[n - 1];
    temp.push_back(sufMax);
    for(int i=n-2;i>=0; i--){
        if(arr[i]>sufMax){
            sufMax = arr[i];
            temp.push_back(sufMax);
        }
    }
    std::reverse(temp.begin(), temp.end());
    return temp;
}

int main() {
    vector<int> arr = { 16, 17, 4, 3, 5, 2 };
    vector<int> result = leaders(arr);
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;

    std::vector<int> result2 = leadersSuffixMax(arr);
    for(int res: result2){
        std::cout << res << " ";
    }
    std::cout << std::endl;

    return 0;
}