#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs);

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> anagrams = groupAnagrams(strs);
    for(vector<string> anagramList: anagrams){
        for(string anagram: anagramList){
            cout << anagram << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs){
    vector<string> sortedStrs = strs;
    
}