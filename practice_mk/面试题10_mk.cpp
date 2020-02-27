/* 2020.02.27 mk */
//0 ms
//8.3 MB

class Solution {
public:
    int numWays(int n) {
        ++n;
        if(n<2) return n;
        int a=0;
        int b=1;
        int c;
        for(int i=1;i<n;++i){
            c=(a+b)%1000000007;
            a=b;
            b=c;
        }
        return c;
    }
};
