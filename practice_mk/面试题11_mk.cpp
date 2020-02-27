/* 2020.02.27 mk */
//8 ms
//14.5 MB

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i=0;
        while(i+1<numbers.size()){
            if(numbers[i++]<=numbers[i]) continue;
            else  return numbers[i];
        }
        return numbers[0];
    }
};
