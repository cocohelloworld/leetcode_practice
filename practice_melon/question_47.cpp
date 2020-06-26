/*
 *time: 16 ms win: 80.46%
 *memory: 9.5 MB win:100%
 *coded by jiaxin
 */
class Solution {
 public:
  int maxValue(vector<vector<int>>& grid) {
    vector<vector<int>> dp = grid;
    if (grid[0].size() == 0) return NULL;
    int cols = grid[0].size();
    int rows = grid.size();

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++) {
        if (i > 0 && j > 0)
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        else if (i > 0 && j == 0)
          dp[i][j] = dp[i - 1][j] + grid[i][j];
        else if (i == 0 && j > 0)
          dp[i][j] = dp[i][j - 1] + grid[i][j];
      }
    return dp[rows - 1][cols - 1];
  }
};