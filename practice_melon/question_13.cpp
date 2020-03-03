/*
 *time: 4ms win:88.08%
 *memory: 9.6 MB win:100%
 *coded by jiaxin
 */
class Solution {
public:
	int width;
	int length;
	int ktotal;
	int result = 0;
	vector<vector<int>> visit;
	int movingCount(int m, int n, int k) {
		int i = 0, j = 0;
		width = m;
		length = n;
		total = k;
		if (!k)return 1;
		vector<vector<int>> newhis(m, vector<int>(n, 0));
		visit = newhis;
		result = move(0, 0);
		return result;
	}
	int move(int i, int j) {
		visit[i][j] = 1;
		int sum = 1;
		if (i % 10 + (j + 1) % 10 <= total - ((i) / 10 + (j + 1) / 10)) {
			if (j + 1 <= length - 1 && !visit[i][j + 1]) {
				sum += move(i, j + 1);
			}
		}
		if (((i + 1) % 10 + j % 10) <= total - ((i + 1) / 10 + j / 10)) {
			if (i + 1 <= width - 1 && !visit[i + 1][j]) {
				sum += move(i + 1, j);
			}
		}
		return sum;
	}
};