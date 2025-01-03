#include<iostream>
#include<vector>

using namespace std;

void subArray(vector<int> v){  
    int n = v.size();
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=i; k<=j; k++){
                std::cout << v[k] << " ";
            }
            std::cout << std::endl;
        }
    }
}


void printSubArrays2(vector<int> &v,int start, int end){
    if(end == v.size()){
        return;
    }

    else if (start > end){
        printSubArrays2(v, 0, end+1);
    }

    else {
        for(int i=start; i<=end; i++){
            std::cout << v[i] << " ";
        }
        cout << endl;
        printSubArrays2(v, start+1, end);
    }
}


int main()
{
    vector<int> arr = {1, 2, 3, 4};
    cout << "All Non-empty Subarrays\n";
    subArray(arr);
    printSubArrays2(arr, 0, arr.size());
    return 0;
}