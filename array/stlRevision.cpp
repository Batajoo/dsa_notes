#include<bits/stdc++.h>

int main(){
    std::vector<int> v = {1,2,3,4,5,6,7,8,9};

    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << *(it);
    }
    std::cout << std::endl;
    for(auto it : v){
        std::cout << it;
    }
    std::cout << std::endl;
    for(auto it = v.begin(); it!= v.end(); it++){
        std::cout << *(it);
    }
    std::cout << std::endl << std::endl;
    std::cout << "erase" <<std::endl;

    v.erase(v.begin()+1);
    v.erase(v.begin()+2 , v.end()-4);

    for(auto it: v){
        std::cout << it;
    }
    std::cout << std::endl;

    std::vector<int> v1(2,100);
    v1.insert(v1.begin(), 300);
    v1.insert(v1.begin()+2, 3, 10);

    std::vector<int> copy(10, 50);
    v1.insert(v1.begin()+2, copy.begin(), copy.end());
    
    for(auto it: v1){
        std::cout << it << " ";
    }
    std::cout << std::endl;
    std::cout << v1.size() << std::endl;
    v1.pop_back();
    v1.swap(v);
    for(auto it: v1){
        std::cout << it << " ";
    }
    std::cout << std::endl;
    v.clear();
    for(auto it: v){
        std::cout << it << " ";
    }

    return 0;
}


