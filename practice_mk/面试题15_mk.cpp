/* 2020.03.08 mk */
//8 ms
//8.3 MB

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint16_t nl = n;
        uint16_t nh = n >> 16;
        int cnt=0;
        while(nl){
            if(nl%2==1) ++cnt;
            nl/=2;
        }
        while(nh){
            if(nh%2==1) ++cnt;
            nh/=2;
        }
        return cnt;
    }
};
