#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

struct pair_hash{
    size_t operator()(const pair<int,int> &p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, unordered_set<char>> row, col;
    unordered_map<pair<int, int>, unordered_set<char>, pair_hash> boxes;

    for(int i = 0; i < 9; i++){
        for(int j=0; j < 9; j++){
            char value = board[i][j];
            if(value == '.') continue;

            if(row[i].count(value) || col[j].count(value) || boxes[{i/3,j/3}].count(value))
                return false;

            row[i].insert(value);
            col[j].insert(value);
            boxes[{i/3,j/3}].insert(value);
        }
    }

    return true;
}

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << (isValidSudoku(board) ? "Valid" : "Invalid") << endl;
    return 0;
}