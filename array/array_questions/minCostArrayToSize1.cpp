#include <bits/stdc++.h>

using namespace std;

int cost(vector<int> &arr){

    int min = *min_element(arr.begin(), arr.end());

    return ((arr.size()-1)*min);
}

int main()
{
    vector<int> a = { 4, 3, 2 };
    cout << cost(a) << endl;
    return 0;
}