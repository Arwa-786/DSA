class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++)
            for (int c = 0; c < board[0].size(); c++)
                if (dfs(board, word, r, c, 0)) return true;  // try every start
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int k) {
        if (k == word.size()) return true;                     // matched every letter

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            return false;                                      // off the grid
        if (board[r][c] != word[k]) return false;              // wrong letter (or '#')

        char temp = board[r][c];
        board[r][c] = '#';                                     // mark as used

        bool found = dfs(board, word, r + 1, c, k + 1) ||      // down
                     dfs(board, word, r - 1, c, k + 1) ||      // up
                     dfs(board, word, r, c + 1, k + 1) ||      // right
                     dfs(board, word, r, c - 1, k + 1);        // left

        board[r][c] = temp;                                    // unmark
        return found;
    }
};