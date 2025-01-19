#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Hash {
    int BUCKET;
    int numOfElements;

    Hash(int b){
        this->BUCKET = b;
        this->numOfElements = 0;
        table.resize(BUCKET);
    }

    vector<vector<int>> table;

    int HashFunction(int x){
        return (x % BUCKET);
    }

    float getLoadFactor(){
        return (float) numOfElements / BUCKET;
    }

    void rehashing(){
        int oldBucket = BUCKET;
        BUCKET = 2 * BUCKET;
        vector<vector<int>> oldTable = table;
        table.clear();
        table.resize(BUCKET);
        numOfElements = 0;

        for(int i=0; i< oldBucket; i++){
            for(int key: oldTable[i]){
                insertItem(key);
            }
        }
    }

    void insertItem(int key){
        while(getLoadFactor() > 0.5){
            rehashing();
        }
        int index = HashFunction(key);
        table[index].push_back(key);
        numOfElements++;
    }

    void displayHash();
    void deleteItem(int key);
};

void Hash::deleteItem(int key){
    int index = HashFunction(key);

    auto it = find(table[index].begin(), table[index].end(), key);
    if(it != table[index].end()){
        table[index].erase(it);
        numOfElements--;
    }    
}

void Hash::displayHash(){
    for(int i=0; i<BUCKET; i++){
        cout << i;
        for(int x: table[i]){
            cout << " --> " << x;
        }
        cout << endl;
    }
}

int main() {
    // Vector that contains keys to be mapped
    vector<int> a = {15, 11, 27, 8, 12};

    // Insert the keys into the hash table
    Hash h(7); // 7 is the number of buckets in the hash table
    for (int key : a)
        h.insertItem(key);

    // Delete 12 from the hash table
    h.deleteItem(12);

    // Display the hash table
    h.displayHash();

    // Insert more items to trigger rehashing
    h.insertItem(33);
    h.insertItem(45);
    h.insertItem(19);

    // Display the hash table after rehashing
    cout << "\nAfter rehashing:\n";
    h.displayHash();

    return 0;
}