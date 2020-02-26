/*
 *time: 4 ms, win:73.8%
 *memory: 8.1 MB, win:100%
 *coded by jiaxin
 */
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int sum = 0;
		while (n) {
			if (n % 2) { sum++; n -= 1; }
			else n /= 2;
		}
		return sum;
	}
};