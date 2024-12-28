#include <iostream>
#include <vector>

std::vector<int> getAlternatives(std::vector<int> arr){
    std::vector<int> temp;
    for(int i=0; i<arr.size(); i += 2){
        temp.push_back(arr.at(i));
    }
    return temp;
}

//Recursive method
void getAlternativeRec(std::vector<int> &arr, int index, std::vector<int> &res){
    if(index < arr.size()){
        res.push_back(arr[index]);
        getAlternativeRec(arr, index + 2, res);
    }    
}

std::vector<int> getAlternatives2(std::vector<int> &arr){
    std::vector<int> res;
    getAlternativeRec(arr, 0, res);
    return res;
}



int main(){
    std::vector<int> arr = {10, 20, 30, 40, 50};
    std::vector<int> arr2 = {1,2,3,4,5};
    std::vector<int> alternatives = getAlternatives(arr);
    std::vector<int> alternatives2 = getAlternatives2(arr2);
    for(auto i: alternatives){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for(auto i: alternatives2){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}