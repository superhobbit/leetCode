Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

Answer again:
bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (board[i][j] == word.at(0)) {
                if (search(visited,board,i,j,0,word)) return true;
            }
        }
    }
    return false;
}
bool search(vector<vector<bool>>& visited, vector<vector<char>>& board, int i, int j, int index, string word){
    if (index == word.size()) return true;
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] != word.at(index)) return false;
    visited[i][j] = true;
    if (search(visited,board,i+1,j,index+1,word) || search(visited,board,i,j+1,index+1,word) || search(visited,board,i-1,j,index+1,word) || search(visited,board,i,j-1,index+1,word)) return true;
    visited[i][j] = false;
    return false;
} 
