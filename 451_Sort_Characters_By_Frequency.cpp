class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char,int> mp;
        priority_queue<pair<int,char>> q; 

        for(char i: s){
            mp[i]++;
        }
        for(auto it: mp){
            q.push({it.second,it.first}); 
        }
        
        string t;
        while(!q.empty()){
            for(int i = 0; i < q.top().first; ++i){
                t.push_back(q.top().second);
            }
            q.pop();
        }
        
        return t;
    }
    
};
