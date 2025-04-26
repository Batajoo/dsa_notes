#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();

    int l = 0;
    int r = 1;

    int trappedWater = 0;

    while(r < n-1){
        l = r-1;
        while(height[r] > height[r+1] && r<n-1)
            r++;
        cout << l << " " << r << endl;
        int waterLevel = min(height[l], height[r]);
        for(int i = l+1; i<r; i++){
            trappedWater += (waterLevel - height[i]);
        }
        r++;
    }

    return trappedWater;
}

int main(){
    vector<int> height = {4,2,0,3,2,5};
    cout << trap(height) << endl;
    return 0;
} 