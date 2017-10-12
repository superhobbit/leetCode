Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.


Not sure if it is the best solution, beats only 14.93%, but appears on the first column
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (!obstacleGrid.size()) return 0;
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>>result(n, vector<int>(m,0));
    result[n-1][m-1] = obstacleGrid[n-1][m-1] ? 0 : 1;
    for (int i = n-1; i >= 0; --i){
        for (int j = m-1; j >= 0; --j){
            if (i == n-1) {
                if (!obstacleGrid[i][j] && !obstacleGrid[n-1][m-1]){
                    if (j != m-1) result[i][j] = 1;
                    continue;                        
                }else break;
            }
            if (j == m-1) {
                if (!obstacleGrid[i][j] && !obstacleGrid[n-1][m-1]){
                    if (i != n-1) result[i][j] = i+1 == n-1 ? 1 : result[i+1][j];
                    continue;                        
                }else continue;
            }
            if (obstacleGrid[i][j]) continue;
            else result[i][j] = result[i+1][j] + result[i][j+1];
        }
    }
    return result[0][0];
}
