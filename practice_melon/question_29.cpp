/*
 *time: 32 ms win: 5.47%
 *memory: 9.9 MB win:100%
 *coded by jiaxin
 */
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> result;
    if (matrix.size() == 0)
      return result;
    int col = matrix[0].size(); // lie
    int row = matrix.size();    // hang
    int h1 = 0, h2 = row - 1, l1 = col - 1, l2 = 0;
    while (1) {
      for (int i = l2; i <= l1; i++) {
        result.push_back(matrix[h1][i]);
      }
      if (++h1 > h2)
        return result;

      for (int i = h1; i <= h2; i++) {
        result.push_back(matrix[i][l1]);
      }
      if (--l1 < l2)
        return result;
      for (int i = l1; i >= l2; i--) {
        result.push_back(matrix[h2][i]);
      }
      if (--h2 < h1)
        return result;
      for (int i = h2; i >= h1; i--) {
        result.push_back(matrix[i][l2]);
      }
      if (++l2 > l1)
        return result;
    }
    return result;
  }
};