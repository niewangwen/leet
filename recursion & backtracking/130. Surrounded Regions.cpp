//TLE解法
//对于每个O都进行一遍dfs，然后判断其是否能变成X

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X')
                    continue;
                if(dfs(board, i, j, m, n))
                    board[i][j] = 'X';
            }
        }
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
            if (board[i][j] == 'O')
                return false;
        }
        if (board[i][j] == 'X' || board[i][j] == 'Q')
            return true;
        else 
            board[i][j] = 'Q';
        bool ret =  dfs(board, i + 1, j, m, n) && dfs(board, i - 1, j, m, n)
                 && dfs(board, i, j + 1, m, n) && dfs(board, i, j - 1, m, n);
        // if (ret) board[i][j] = 'X'; //WRONG
        // 注意，不能在dfs内部直接修改board的值
        // 因为判断依赖于遍历过的O，此时O会被改成Q，如果一个O三面是X而一面是O，且那个O先被遍历
        // 则有可能出错
        // eg:  X X |   badcase: X X |  ->  X X |    
        //    X O X |          X O X |    X X X |
        //    X O O |          X Q O |    X Q O |
        board[i][j] = 'O';
        return ret;
    }

// 既然上面的TLE了，那么主要focus边界点，看看边界点最多能延伸到多远

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                        dfs(board, i, j, m, n); 
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'Q')
                    board[i][j] = 'O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        board[i][j] = 'Q';
        vector<pair<int, int>> di = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (auto ele : di) {
            int x = i + ele.first, y = j + ele.second;
            if (x < 0 || x == m || y < 0 || y == n)
                continue;
            if (board[x][y] == 'X' || board[x][y] == 'Q')
                continue;
            dfs(board, x, y, m, n);
        }
    }
