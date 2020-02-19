/*
time: 32ms
win:86.23%
coded by jiaxin
*/
class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (!matrix.size() || !matrix[0].size()) {
      return false;
    }
    int n_end = matrix.size() - 1;     // hang
    int m_end = matrix[0].size() - 1;  // lie
    int n_start = 0, m_start = 0;
    int find = 0;

    while (1) {
      if (matrix[n_start][m_end] == target) {
        return true;
      } else if (matrix[n_start][m_end] < target) {
        if (n_start < n_end)
          n_start++;
        else
          return false;
      } else if (matrix[n_start][m_end] > target) {
        if (m_start < m_end)
          m_end--;
        else
          return false;
      }
      if (n_start == n_end && m_start == m_end &&
          matrix[n_start][m_end] != target) {
        return false;
      }
    }
  }
};