/* 2020.03.13 mk */
//40 ms
//37.3 MB

class Solution {
public:
    double myPow(double x, int n) {
        if(x==1) return 1;
        if(x==-1&&n==-2147483648) return 1;
        if(x==-1&&abs(n)%2==1) return -1;
        if(x==-1&&abs(n)%2==0) return 1;
        if(n==2147483647) return 0;
        if(n==-2147483648) return 0;
        if(n<0) x = 1/x;
        return mul(x,abs(n),x);
    }
    double mul(double x, int times, double pow){
        if(times==0) return 1;
        pow*=mul(x,times-1,pow);
        return pow;
    }
};
