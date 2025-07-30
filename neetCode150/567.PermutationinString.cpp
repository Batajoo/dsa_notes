#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool checkInclusion(string s1, string s2) {
        int s2Size = s2.size();
        int s1Size = s1.size();

        if(s1Size > s2Size) return false;
        
        unordered_map<char,int> s1Count, s2Count;

        for(const char &s1Val: s1){
            s1Count[s1Val]++;
        }

        int l = 0;
        int r = 0;
        
        for(r=0; r<s1Size; r++){
            s2Count[s2[r]]++;
        }

        r = s1Size - 1;
        while(r < s2Size){
            if(s1Count == s2Count) return true;
            if(!--s2Count[s2[l]]) s2Count.erase(s2[l]);
            l++;
            r++;
            s2Count[s2[r]]++;
        }

        return false;

        
    }


int main() {
    string s1 = "ab";
    string s2 = "eidbaoo";
    cout << boolalpha << checkInclusion(s1, s2) << endl;
    return 0;
}