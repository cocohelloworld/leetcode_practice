/* 2020.02.26 mk */
//156 ms
//26.8 MB


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int hang = board.size();
        int lie = board[0].size();
        int ge = word.size();
        vector<vector<int>> idboard;
        if (ge > hang * lie) return 0;
        for(int i = 0;i<ge;++i){
            vector<int> zimuboard;
            for(int j=0;j<hang;++j){
                for(int k=0;k<lie;++k){
                    if(board[j][k] == word[i]){
                        zimuboard.push_back(j*lie+k);
                    }
                }
            }
            if(zimuboard.size()==0) return 0;
            idboard.push_back(zimuboard);
        }
        vector<int> path;
        bool flag;
        for(int headid = 0;headid<idboard[0].size();++headid){
            flag = findNext(0, headid, idboard, lie, path);
            if(flag) return 1;
        }
        return 0;
    }
    bool findNext(int ceng, int headid, vector<vector<int>>& idboard, int lie, vector<int>& path){
        bool flag = 0;
        if(ceng == idboard.size()-1) return 1;
        if(ceng == 0 && headid == idboard[0].size()) return 0;
            for(int curid = 0;curid<idboard[ceng+1].size();++curid){
                if((abs(idboard[ceng][headid]-idboard[ceng+1][curid]) == 1 && idboard[ceng][headid]/lie == idboard[ceng+1][curid]/lie) || abs(idboard[ceng][headid]-idboard[ceng+1][curid]) == lie  ) {
                    if(find(path.begin(), path.end(), idboard[ceng+1][curid]) != path.end()) continue;
                    path.push_back(idboard[ceng][headid]);
                    flag = findNext(ceng+1, curid, idboard, lie, path);
                    if(flag) return 1;
                    path.pop_back();
                }
            }
        return 0;
    }
};
