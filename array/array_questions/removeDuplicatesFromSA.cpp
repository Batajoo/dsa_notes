#include<bits/stdc++.h>

using namespace std;

//time Complexity - O(n2)
int removeDuplicates(std::vector<int> &v){
    const int n = v.size();
    for(int i=0; i<n-1; i++){
        if(v[i]==v[i+1]){
            v.erase(v.begin()+i+1);
        }
    }
    return v.size();
}

//best approach
//time Complexity - 0(n)
int removeDuplicates2(std::vector<int> &v){
    int n = v.size();
    if (n <= 1) return n;
    int idx = 1;

    for(int i = 1; i< n; i++){
        if(v[i] != v[i-1]){
            v[idx++] = v[i];
        }
    }
    return idx;
}

//using set
int removeDuplicates3(std::vector<int> &v){
    std::unordered_set<int> temp (v.begin(), v.end());
    std::vector<int> temp2(temp.begin(), temp.end());
    v.swap(temp2);
    return v.size();
}

//using hash_set 2
int removeDuplicates4(std::vector<int> &v){
    std::unordered_set<int> s;

    int idx = 0;

    for(int i=0; i<v.size(); i++){
        if(s.find(v[i]) == s.end()){
            s.insert(v[i]);
            v[idx++] = v[i];
        }
    }

    return s.size();
}


int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int newSize = removeDuplicates4(arr);
    for (int i = 0; i < newSize; i++) 
        cout << arr[i] << " ";
    return 0;
}