/* 2020.02.22 mk */
//24 ms
//15.3 MB

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0) return false;
        int m = matrix[0].size();
        if(m==0) return false;
        int a=m/2;
        int b=n/2;
        int aa=a,bb=b;
        if(matrix[b][a]==target) return true;
        if(matrix[b][a]<target){
            while(matrix[bb+b/2][aa+a/2]<target && (b/2 != 0 || a/2 != 0)){
                b=b/2;
                a=a/2;
                bb+=b;
                aa+=a;
            }
            for(int i=bb+1;i<n;++i){
                for(int j=0;j<m;++j){
                    if(matrix[i][j] == target) return true;
                    if(matrix[i][j] > target) break;
                }
            }
            for(int i=0;i<bb+1;++i){
                for(int j=aa+1;j<m;++j){
                    if(matrix[i][j] == target) return true;
                    if(matrix[i][j] > target) break;
                }
            }
        }else{
            while(matrix[bb-b/2][aa-a/2]>target && (b/2 != 0 || a/2 != 0)){
                b=b/2;
                a=a/2;
                bb-=b;
                aa-=a;
            }

            for(int i=0;i<bb;++i){
                for(int j=0;j<m;++j){
                    if(matrix[i][j] == target) return true;
                    if(matrix[i][j] > target) break;
                }
            }
            for(int i=bb;i<n;++i){
                for(int j=0;j<aa;++j){
                    if(matrix[i][j] == target) return true;
                    if(matrix[i][j] > target) break;
                }
            }
        }

        return false;
    }
};
