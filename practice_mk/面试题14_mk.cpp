/* 2020.03.08 mk */
//4 ms

class Solution {
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        if(n%3==1) return pow(3,n/3-1)*4;
        if(n%3==2) return pow(3,n/3)*2;
        return pow(3,n/3);
    }
};
/*
class Solution {
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        long mul = 1;
        while(n){
            if(n<6){
                if(n==5) mul = ((mul*2)%1000000007*3)%1000000007;
                else mul = (mul*n)%1000000007;
                break;
            }
            n-=3;
            mul=(mul*3)%1000000007;
        }
        return mul;
    }
};
*/
