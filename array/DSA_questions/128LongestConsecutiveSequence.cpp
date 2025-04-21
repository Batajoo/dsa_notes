#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// self try - using ordered set
int longestConsecutive(vector<int> &nums){
    set<int> contains (nums.begin(), nums.end());
    int res = 0;
    int current = 1;

    for(int val : contains){
        if(contains.count(val+1)){
            current++;
        } else {
            current = 1;
        }
        res = max(res, current);
    }

    return res;
}

int main(){
    return 0;
}