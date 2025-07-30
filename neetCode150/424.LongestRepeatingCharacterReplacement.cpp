#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int characterReplacement(string s, int k) {
    int n = s.size();
    int res = 0;

    for(int l = 0; l < n;l++){
        unordered_map<char, int> count;
        int maxCount = 0;
        for(int r = l; r < n; r++){
            count[s[r]]++;
            maxCount = max(maxCount, count[s[r]]);

            if(r - l + 1 - maxCount <= k){
                res = max(res, r-l+1);
            }
        }
    }

    return res;
}

int main() {
    string s = "ABBB";
    int k = 1;
    cout << characterReplacement(s, k) << endl;
    return 0;
}