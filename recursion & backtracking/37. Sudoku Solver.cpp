class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<set<int>> record_row(9, set<int>());
        vector<set<int>> record_col(9, set<int>());
        vector<vector<set<int>>> record_grid(3, vector<set<int>>(3, set<int>()));
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    //⚠️注意：输入的是char，存数据的是int，如果直接int(char), 则0的ascii值是48
                    //所以要用 char - '0'转换成int
                    record_row[i].insert(board[i][j] - '0');
                    record_col[j].insert(board[i][j] - '0');
                    //始终注意是/还是%，最好自己试验两个数看下结果
                    record_grid[i / 3][j / 3].insert(board[i][j] - '0');
                }
            }
        }
        
        helper(board, 0, 0, record_row, record_col, record_grid);
        
    }
    
    bool helper(vector<vector<char>>& board, int i, int j, vector<set<int>>& record_row, vector<set<int>>& record_col, vector<vector<set<int>>>& record_grid) {
        if (i == 9)
            return true;
        if (j >= 9)
            return helper(board, i + 1, 0, record_row, record_col, record_grid);
        if (board[i][j] != '.')
            return helper(board, i, j + 1, record_row, record_col, record_grid);
        for (int num = 1; num <= 9; num++) {
            if (record_row[i].count(num) || record_col[j].count(num) || record_grid[i / 3][j / 3].count(num))
                continue;
            board[i][j] = num + '0';
            record_row[i].insert(num);
            record_col[j].insert(num);
            record_grid[i / 3][j / 3].insert(num);
            if (helper(board, i, j + 1, record_row, record_col, record_grid))
                return true;
            board[i][j] = '.';
            record_row[i].erase(num);
            record_col[j].erase(num);
            record_grid[i / 3][j / 3].erase(num);
        }
        return false;
    }
  
  //void 方式的递归函数在此处是错误的！！！！
  //因为本题要求在本身数组上进行改变，所以当得到正确结果后，就应该不再执行，退出程序
  //如果是bool，则可以在那个时候返回true，退出执行
  //但是如果是void，即使得到了正确结果，最终还是return，函数并不知道这次对不对，会一直执行下去，直到最后的边界条件
      /*void helper(vector<vector<char>>& board, int i, int j, vector<set<int>>& record_row, vector<set<int>>& record_col, vector<vector<set<int>>>& record_grid) {
        if (i == 9)
            return ;
        if (j >= 9)
            helper(board, i + 1, 0, record_row, record_col, record_grid);
        if (board[i][j] != '.')
            helper(board, i, j + 1, record_row, record_col, record_grid);
        for (int num = 1; num <= 9; num++) {
            if (record_row[i].count(num) || record_col[j].count(num) || record_grid[i / 3][j / 3].count(num))
                continue;
            board[i][j] = num + '0';
            record_row[i].insert(num);
            record_col[j].insert(num);
            record_grid[i / 3][j / 3].insert(num);
            helper(board, i, j + 1, record_row, record_col, record_grid)
                
            board[i][j] = '.';
            record_row[i].erase(num);
            record_col[j].erase(num);
            record_grid[i / 3][j / 3].erase(num);
        }*/
        
    }
};
