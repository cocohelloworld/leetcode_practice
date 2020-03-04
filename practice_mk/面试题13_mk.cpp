

class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(k==0) return 1;
        if(m==1&&n==1) return 1;
        if(k<9){
            if(m>=k+1&&n>=k+1) return (k+1)*(k+2)/2;
            int cnt=0;
            m = m>10? 10:m;
            n = n>10? 10:n;
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    if(i/10+i%10+j/10+j%10 <= k) ++cnt;
                    else break;
                }
            }
            return cnt;
        }else{
            int mkuai=(m-1)/10+1;
            int nkuai=(n-1)/10+1;
            int cnt=0;
            for(int i=0;i<mkuai;++i){
                for(int j=0;j<nkuai;++j){
                    if(i+j+7 >= k) break;
                    for(int ii=0;ii<m-10*i&&ii<10;++ii){
                        for(int jj=0;jj<n-10*j&&jj<10;++jj){
                            if(i+ii+j+jj <= k) ++cnt;
                            else break;
                        }
                    }
                }
            }
            return cnt;
        }
        return 0;
    }
};
