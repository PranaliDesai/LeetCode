class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        if (strs.size() == 0) return s;
        int len;
        len = strs[0].size();
        int i =0;
        int count =0;
        while (i<len){
            count = 0;
            for (auto k: strs){
                if (k.size()>=i &&strs[0][i]==k[i]) count ++;
            }
            if (count == strs.size()) s+=strs[0][i];
            else break;
            i++;

        }
        return s;
    }
};
