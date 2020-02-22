/* 2020.02.18 mk */
//4 ms
//8.4 MB


class Solution {
public:
    string replaceSpace(string s) {
        int offindex=0;
        while((offindex=s.find(" ",offindex))!=s.npos){
            s.replace(offindex,1,"%20");
        }
        return s;
    }
};
