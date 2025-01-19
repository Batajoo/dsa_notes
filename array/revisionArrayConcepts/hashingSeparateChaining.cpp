#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Hash {
    int Bucket;
    vector<vector<int>> table;

    Hash(int b){
        this->Bucket = b;
        table.resize(Bucket);
    }

    int hashFunction(int x){
        return (x % Bucket);
    }

    void insertItem(int key){
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key);
    void displayHash();
};

void Hash::deleteItem(int key){
    int index = hashFunction(key);
    auto it = find(table[index].begin(), table[index].end(), key);
    if(it != table[index].end()){
        table[index].erase(it);
    }
}

void Hash::displayHash(){
    for(int i=0; i<Bucket; i++){
        cout << i;
        for(int x: table[i]){
            cout << "--> " << x;
        }
        cout << endl;
    }
}

int main() {
    // Vector that contains keys to be mapped
    vector<int> a = {15, 11, 27, 8, 12};

    // Insert the keys into the hash table
    Hash h(7); // 7 is the number of buckets 
    for (int key : a)
        h.insertItem(key);

    // Delete 12 from the hash table
    h.deleteItem(12);

    // Display the hash table
    h.displayHash();

    return 0;
}