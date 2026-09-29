class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<int>> boxes(9);
        unordered_set<int> row, col;
        for(int i = 0; i < 9; ++i) {
            row.clear();
            col.clear();
            for(int j = 0; j < 9; ++j) {
                // check row
                int row_item = board[i][j] - '0';
                if(row_item >= 0) {
                    if(row.find(row_item) == row.end()) {
                        row.insert(row_item);
                    }
                    else    return false;
                }

                //check col
                int col_item = board[j][i] - '0';
                if(col_item >= 0) {
                    if(col.find(col_item) == col.end()) {
                        col.insert(col_item);
                    }
                    else    return false;
                }

                //check box
                if(row_item >= 0) {
                    int box = int(j / 3) + int(i / 3) * 3;
                    if(boxes[box].find(row_item) == boxes[box].end()) {
                        boxes[box].insert(row_item);
                    }
                    else    return false;
                }
            }
        }
        return true;
    }
};
