class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0;
        int j = height.size()-1;
        int ans = 0;
        while(j>i){
            ans = max(ans, (j - i) * min(height[j],height[i]));
            if (height[j] >height[i]) i++;
            else j--;
        }
        return ans;
    }
};
