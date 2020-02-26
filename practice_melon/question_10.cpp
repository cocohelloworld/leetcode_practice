class Solution {
 public:
  // vector<vector<int>> history;
  bool exist(vector<vector<char>>& board, string word) {
    if (!board.size()) return 0;
    if (!word.length()) return 1;
    vector<vector<int>> history(board.size(), vector<int>(board[0].size(), 0));
    // vector<vector<int>> v(board.size(), vector<int>(board.size(),1));

    //  vector<vector<int>> history;
    //  for(int i = 0;i<board.size();i++){
    //     for(int j=0;j<board[0].size();j++){
    //     history[i].push_back(0);
    //     }}
    // cout<<history.size()<<endl;
    cout << history[board.size() - 1][board[0].size() - 1] << endl;
    int k = 0;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == word[0]) {
          history[i][j] = 1;
          k++;
          if (search(board, word, k, history, i, j))
            return 1;
          else {
            history.clear();
            k = 0;
          }
        }
      }
    }
    return 0;
  }
  bool search(vector<vector<char>>& board, string word, int k,
              vector<vector<int>> history, int i, int j) {
    // if(k==strlen(word))return 1;
    if (i != 0) {
      int n = i;
      n--;
      int m = j;
      if (board[n][m] == word[k]) {
        int kk = k++;
        if (kk == word.length())
          return 1;
        else if (search(board, word, kk, history, n, m)) {
          cout << word[kk] << endl;
          history[n][m] = 1;
          return 1;
        };
      }
    }

    if (i != board.size() - 1) {
      int n = i;
      n++;
      int m = j;
      if (board[n][m] == word[k]) {
        int kk = k++;
        if (kk == word.length())
          return 1;
        else if (search(board, word, kk, history, n, m)) {
          cout << word[kk] << endl;
          history[n][m] = 1;
          return 1;
        };
      }
    }

    if (j != 0) {
      int n = i;
      int m = j;
      m--;
      if (board[n][m] == word[k]) {
        int kk = k++;
        if (kk == word.length())
          return 1;
        else if (search(board, word, kk, history, n, m)) {
          cout << word[kk] << endl;
          history[n][m] = 1;
          return 1;
        };
      }
    }

    if (j != board[0].size() - 1) {
      int n = i;
      int m = j;
      m++;
      if (board[n][m] == word[k]) {
        int kk = k++;
        if (kk == word.length())
          return 1;
        else if (search(board, word, kk, history, n, m)) {
          cout << word[kk] << endl;
          history[n][m] = 1;
          return 1;
        };
      }
    }

    return 0;
  }
};