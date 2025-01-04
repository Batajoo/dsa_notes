#include <bits/stdc++.h>

using namespace std;

//right rotation in array


//rotate one by one method 
//time complexity - O(n*d);
//space complexity = O(1)
void rotateArr(std::vector<int> &arr, int d){
    int lastEl;
    int n = arr.size();

    for(int i=0; i<d; i++){
        lastEl = arr[n-1];
        for(int j=n-1;j>0;j--){
            arr[j] = arr[j-1];
        }
        arr[0] = lastEl;
    }
}

//using temporary array;
void rotateArrayTemArr(std::vector<int> &arr, int d){
    // std::vector<int> temp;
    // d %= arr.size();
    // for(int i=0; i<d; i++){
    //     int lastEl = *(arr.end()-d+i);
    //     temp.push_back(lastEl);
    // }

    // for(int i=0; i<arr.size()-d; i++){
    //     temp.push_back(arr[i]);
    // }

    // arr.swap(temp);

    int n = arr.size();

    d %= n;
    std::vector<int> temp(n);

    for(int i=0; i<d; i++){
        temp[i] = arr[n-d+i];
    }

    for(int i=0; i<n-d; i++){
        temp[i+d] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = temp[i];
    }
}

void rotateArrayReverseMethod(std::vector<int> &arr, int d){
    std::reverse(arr.begin(), arr.end());
    std::reverse(arr.begin()+d, arr.end());
    std::reverse(arr.begin(), arr.begin()+d);
}

void rotateArrayJugglingAlgo(std::vector<int> &arr, int d){
    int n = arr.size();

    d %= n;

    int cycles = std::gcd(n,d);

    for(int i=0; i<cycles; i++){
        int currIdx = i;
        int currEl = arr[currIdx];

        do {
            int nextIdx = (currIdx + d) % n;
            int nextEl = arr[nextIdx];

            arr[nextIdx] = currEl;
            currEl = nextEl;
            currIdx = nextIdx;
        }while(currIdx != i);
        
    }
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6};
    vector<int> arr2 = { 1, 2, 3, 4, 5, 6, 7,8};
    
    int d = 2;

    //one by one rotation
    rotateArr(arr, d);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    cout << endl;

    //temporary array method 
    rotateArrayTemArr(arr2,d);
    rotateArrayReverseMethod(arr2, d);
    rotateArrayJugglingAlgo(arr2, d);

    for (int i = 0; i < arr2.size(); i++)
        cout << arr2[i] << " ";


    return 0;
}