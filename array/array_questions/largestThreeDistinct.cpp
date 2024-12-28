#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//three traversals
vector<int> get3largest(vector<int> &v){
    int fst, scd, thd, i, n;
    fst = scd = thd = -1;
    n = v.size();

    for(i=0; i<n; i++){
        if(v[i]>fst){
            fst = v[i];
        }
    }

    for(i=0; i<n; i++){
        if(v[i]>scd && v[i] != fst){
            scd = v[i];
        }
    }

    for(i=0; i<n; i++){
        if(v[i]>thd && v[i] != scd && v[i] != fst){
            thd = v[i];
        }
    }

    return {fst, scd, thd};
}   

vector<int> get3largestOnePass(std::vector<int> &v){
    int fst = INT_MIN, scd = INT_MIN, thd = INT_MIN;

    for(const auto x: v){
        if(x > fst){
            thd = scd;
            scd = fst;
            fst = x;
        }
        else if(x > scd && x != fst){
            thd = scd;
            scd = x;
        }
        else if(x > thd && x != fst && x != scd){
            thd = x;
        }
    }

    if (fst == INT_MIN){
        fst = -1;
    }
    if (scd == INT_MIN){
        scd = -1;
    }
    if (thd == INT_MIN){
        thd = -1;
    }

    return {fst, scd, thd};
}
int main()
{
    vector<int> arr = {12, 13, 1, 10, 34, 1};

    vector<int> res = get3largest(arr);
    vector<int> res2 = get3largestOnePass(arr);
    for (int x : res)
        cout << x << " ";
    cout << endl;

    for (int x : res2)
        cout << x << " ";
    cout << endl;

    return 0;
}