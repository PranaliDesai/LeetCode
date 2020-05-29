class Solution {
public:
    bool stoneGame(vector<int>& p) {
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());
        int ans1=1;
        int ans2=0;
        for (int i = 0 ;i<p.size();i++){
            if (i%2==0) ans1+=p[i];
            else ans2+=p[i];
        }
        return ans1>ans2;
    }
};
