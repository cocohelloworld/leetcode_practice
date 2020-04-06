/*
 *time: 296 ms win: 7.29%
 *memory: 416.7 MB win:100%
 *coded by jiaxin
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  // TreeNode* myroot;
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    // myroot = root;
    if (root == NULL)
      return "[]";
    queue<TreeNode *> node;
    TreeNode *k = root;
    node.push(root);
    string result;
    string single;
    result = "[";
    // cout<<result<<endl;
    while (1) {
      if (node.empty()) {
        result.erase(result.end() - 1);
        result = result + "]";
        break;
      }
      k = node.front();
      if (k == NULL) {
        int kk = 0;
        while (!node.empty() && k == NULL) {
          kk++;
          node.pop();
          k = node.front();
        }
        if (node.empty()) {
          result.erase(result.end() - 1);
          result = result + "]";
          break;
        } else {
          for (int i = 0; i < kk; i++)
            result += "null,";
        }
        continue;
      }
      stringstream ss;
      ss << (k->val);
      single = ss.str();
      result = result + single + ",";
      // cout<<result<<endl;

      node.push(k->left);
      node.push(k->right);
      node.pop();
    }
    return result;
  }
  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    // cout<<data<<endl;
    data.erase(data.begin());
    data.erase(data.end() - 1);
    queue<TreeNode *> node;
    TreeNode *firstnode;
    if (data.size()) {
      string tmp;
      int level = 0;
      int begin = 0, end = 0;
      bool left = false;
      bool first = true;
      while (begin < data.size()) {
        while (end < data.size() && data[end] != ',')
          end++;
        tmp = data.substr(begin, end - begin);
        begin = end + 1;
        end++;
        TreeNode *k;
        if (tmp == "null")
          k = NULL;
        else {
          int num;
          stringstream ss;
          ss << tmp;
          ss >> num;
          k = new TreeNode(num);
          // cout<<num<<endl;
          node.push(k);
        }
        if (!first) {
          TreeNode *curr = node.front();
          if (left) {
            curr->left = k;
          } else {
            curr->right = k;
            node.pop();
          }
        } else {
          first = !first;
          firstnode = node.front();
        }
        left = !left;
      }

    } else {
      firstnode = NULL;
    }
    return firstnode;
  }

  // Decodes your encoded data to tree.
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));