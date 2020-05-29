class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        if(n == 0) return true;
        if(n >= magazine.size()) return false;
        vector<int> cnt(26, 0);
        for(auto ch : magazine){
            cnt[ch-'a']++;
        }
        for(auto ch : ransomNote){
            cnt[ch-'a']--;
        }
        for(auto i : cnt){
            if(i<0) return false;
        }
        return true;
    }
};
