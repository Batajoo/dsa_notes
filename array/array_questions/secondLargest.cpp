#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

//using sort
int getSecondLargest(std::vector<int> &v){
    std::sort(v.begin(), v.end());
    int lastIndex = v.size()-1;
    int max = v[lastIndex];
    for(int i=lastIndex; i>=0; i--){
        if(v[i] != max && v[i] < max){
            return v[i];
        }
    }
    return -1;
}

//one pass search 
int getSecondLargestOnePass(std::vector<int> &v){
    int largest, secondLargest;
    largest = secondLargest = -1;

    for(int i=0; i<v.size(); i++){
        if(v[i]>largest){
            secondLargest = largest;
            largest = v[i];
        } else if(v[i]<largest && v[i]>secondLargest){
            secondLargest = v[i];
        }
    }

    return secondLargest;
}

int main(){
    std::vector<int> arr = { 12, 35, 1, 10, 34, 1 };
    std::cout<<getSecondLargest(arr) << std::endl;
    std::cout <<getSecondLargestOnePass(arr) << std::endl;
    return 0;
}