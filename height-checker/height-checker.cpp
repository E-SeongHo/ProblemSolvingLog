class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        // Solution2)
        // using the constraint : 1 <= heights[i] <= 100
        vector<int> counts(101, 0);
        for(auto h : heights)
            counts[h]++;
       
        int current = 1;
        int cnt = 0;
        
        for(int i = 0; i < heights.size(); ++i)
        {
            if(!counts[current])
            {
                current++;
                i--;
                continue;
            }
            if(heights[i] != current) cnt++;
            counts[current]--;
        }
        
        return cnt;        
        
    }
};