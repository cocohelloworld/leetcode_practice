/*
 *time: 4 ms win: 70.96%
 *memory: 15.1 MB win:100%
 *coded by jiaxin
 */
class Solution {
public:
  bool verifyPostorder(vector<int> &postorder) {
    if (postorder.size() == 0)
      return 1;
    int root = postorder[postorder.size() - 1];
    for (int i = 0; i < postorder.size(); i++) {
      if (postorder[i] > root) {

        vector<int> left(postorder.begin(), postorder.begin() + i);
        for (int i = 0; i < left.size(); i++) {
          // cout<<"left"<<left[i]<<endl;
          if (left[i] > root)
            return 0;
        }
        vector<int> right(postorder.begin() + i, postorder.end() - 1);
        for (int i = 0; i < right.size(); i++) {
          //  cout<<"right"<<right[i]<<endl;
          if (right[i] < root)
            return 0;
        }
        if (verifyPostorder(left) && verifyPostorder(right))
          return 1;
        else
          return 0;
      }

      if (i == postorder.size() - 1) {
        vector<int> left(postorder.begin(), postorder.end() - 1);
        for (int i = 0; i < left.size(); i++) {
          // cout<<"left"<<left[i]<<endl;
          if (left[i] > root)
            return 0;
        }
        if (verifyPostorder(left))
          return 1;
        else
          return 0;
      }
    }
    return 1;
  }
};