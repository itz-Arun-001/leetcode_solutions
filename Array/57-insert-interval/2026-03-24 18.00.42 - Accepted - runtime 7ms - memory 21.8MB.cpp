class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
         sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // Step 2: take first interval as current
        vector<int> cur = intervals[0];

        for(int i = 1; i < intervals.size(); i++)
        {
            // Step 3: check overlap
            if(intervals[i][0] <= cur[1])
            {
                // merge
                cur[1] = max(cur[1], intervals[i][1]);
            }
            else
            {
                // no overlap → store current
                ans.push_back(cur);
                cur = intervals[i];
            }
        }

        // Step 4: push last interval
        ans.push_back(cur);

        return ans;
    }
};
