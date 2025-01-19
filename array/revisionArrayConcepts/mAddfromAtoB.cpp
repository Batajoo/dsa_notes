#include<iostream>
#include<vector>

using namespace std;

int find(int m,vector<pair<int, int>> q){
    int mx = 0;
    vector<int> pre(5,0);
    for(int i=0;i<m;i++){
        int a = q[i].first;
        int b = q[i].second;

        pre[a-1] += 100;
        pre[b] -= 100;
    }

    for(int i=1;i<5;i++){
        pre[i] += pre[i-1];
        mx = max(mx, pre[i]);
    }

    return mx;
}

int main()
{
 
    int m = 3;
    vector<pair<int, int> > q
        = { { 2, 4 }, { 1, 3 }, { 1, 2 } };
 
    // Function call
    cout << find(m, q);
    return 0;
}