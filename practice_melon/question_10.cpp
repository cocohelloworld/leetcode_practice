/*
 *time: 524ms win:5%
 *memory: 258.4 MB win:100%
 *coded by jiaxin
 */

/*
*一般递归经验：返回true有哪些？字符到底，判断寻找是否成功+递归函数。返回false？一般是不满足if最后返回false
*可改进的地方：
*1. 上下左右四个搜索可以使用两个数组代替：x[4]={0,0,-1,1},y[4]={-1,1,0,0}
*2. 可以使用直接把字符改成随意的不是字母的字符，代表被访问过，节省储存历史的空间。
*/

class Solution {
public:
	string word;
	vector<vector<char>> board;
	bool exist(vector<vector<char>>& board, string word) {
		if (!board.size()) return 0;
		if (!word.length()) return 1;
		vector<vector<int>> newhis(board.size(), vector<int>(board[0].size(), 0));
		vector<vector<int>> history = newhis;
		this->word = word;
		this->board = board;
		int k = 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == word[0]) {
					history[i][j] = 1;
					k++;
					if (k == word.length())
						return 1;
					if (search(k, history, i, j))
						return 1;
					else {
						history = newhis;
						k = 0;
					}
				}
			}
		}
		return 0;
	}
	bool search(int k,
		vector<vector<int>> history, int i, int j) {
		if (i > 0) {
			int n = i;
			n--;
			int m = j;
			if (board[n][m] == word[k] && history[n][m] != 1) {
				int kk = k;
				kk++;
				history[n][m] = 1;
				if (kk == word.length())
					return 1;
				if (search(kk, history, n, m)) {
					return 1;
				}
				else {
					history[n][m] = 0;
				}
			}
		}

		if (i < board.size() - 1) {
			int n = i;
			n++;
			int m = j;
			if (board[n][m] == word[k] && history[n][m] != 1) {
				int kk = k;
				kk++;
				history[n][m] = 1;
				if (kk == word.length())
					return 1;
				if (search(kk, history, n, m)) {
					return 1;
				}
				else {
					history[n][m] = 0;
				}
			}

		}

		if (j > 0) {
			int n = i;
			int m = j;
			m--;
			if (board[n][m] == word[k] && history[n][m] != 1) {
				int kk = k;
				kk++;
				history[n][m] = 1;
				if (kk == word.length())
					return 1;
				if (search(kk, history, n, m)) {
					return 1;
				}
				else {
					history[n][m] = 0;
				}
			}
		}

		if (j < board[0].size() - 1) {
			int n = i;
			int m = j;
			m++;
			if (board[n][m] == word[k] && history[n][m] != 1) {
				int kk = k;
				kk++;
				history[n][m] = 1;
				if (kk == word.length()) {
					return 1;
				}
				if (search(kk, history, n, m)) {
					return 1;
				}
				else {
					history[n][m] = 0;
				}
			}
		}
		return 0;
	}
};