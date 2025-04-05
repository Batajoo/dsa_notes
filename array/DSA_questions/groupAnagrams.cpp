#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs);
vector<vector<string>> groupAnagramHashTable(vector<string> &strs);

int main(){
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    vector<vector<string>> anagrams = groupAnagramHashTable(strs);
    for(vector<string> anagramList: anagrams){
        for(string anagram: anagramList){
            cout << anagram << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string, vector<string>> res;

    for(string str: strs){
        string sortedWord = str;
        sort(sortedWord.begin(), sortedWord.end());
        res[sortedWord].push_back(str);
    }

    vector<vector<string>> result;
    for(auto it = res.begin(); it != res.end(); it++){
        result.push_back(it->second);
    }
    return result;
}

//hash table approach

vector<vector<string>> groupAnagramHashTable(vector<string> &strs){
    unordered_map<string, vector<string>> res;

    for(const auto &s: strs){
        vector<int> count(26,0);
        for(char c: s){
            count[c-'a']++;
        }
        string key = to_string(count[0]);
        for(int i = 1;  i<26; i++){
            key += ','+ to_string(count[i]);
        }
        cout << key << endl;
        res[key].push_back(s);
    }

    vector<vector<string>> result;
    for(const auto & pair: res){
        result.push_back(pair.second);
    }
    return result;
}