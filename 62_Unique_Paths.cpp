A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

First time using DP!!!
int uniquePaths(int m, int n) {
    int record[m][n];
    for(int i = n-1; i >= 0; --i){
        for (int j = m-1; j >= 0; --j){
            if (i == n-1) {
                record[j][i] = 1;
                continue;
            }
            if (j == m-1){
                record[j][i] = 1;
                continue;
            }
            record[j][i] = record[j+1][i]+record[j][i+1];
        }
    }
    return record[0][0];
}
