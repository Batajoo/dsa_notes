#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


string minWindow_BruteForceMethod(string s, string t) {
    unordered_map<char, int> tMap;

    int n = s.size();
    int minCount = n + 1;
    string res = "";

    for(char val: t) tMap[val]++;

    for(int l = 0; l < n; l++){
        unordered_map<char, int> subCount;
        for(int r = l; r < n; r++){
            subCount[s[r]]++;

            bool contains = true;
            for(pair<char, int> val: tMap){
                if(subCount[val.first] < val.second){
                    contains = false;
                    break;
                }
            }

            if(contains && ((r - l + 1) < minCount)){
                minCount = r - l + 1;
                res = s.substr(l, r-l+1);
            }
        }
    }

    return res;
}

string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char, int> tMap, subCount;

        int n = s.size();
        int minSize = n + 1;
        string res = "";

        for(char &val: t) tMap[val]++;
        
        int l = 0;
        for(int r = 0; r < n;){
            subCount[s[r]]++;
            
            bool contains = true;
            for(const pair<char, int> &val: tMap){
                if(subCount[val.first] < val.second){
                    contains = false;
                    break;
                }
            }

            if(contains){
                if(r - l + 1 < minSize){
                    minSize = r - l + 1;
                    res = s.substr(l,r - l + 1);
                }
                subCount[s[l]]--;
                l++;
            } else {
                r++;
            }
        }

        return res;
    }

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
    return 0;
}