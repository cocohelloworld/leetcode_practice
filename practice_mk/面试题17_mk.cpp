/* 2020.03.13 mk */
//16 ms
//13.5 MB

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> numbers;
        for(int i=1;i<pow(10,n);++i){
            numbers.push_back(i);
        }
        return numbers;
    }
};
