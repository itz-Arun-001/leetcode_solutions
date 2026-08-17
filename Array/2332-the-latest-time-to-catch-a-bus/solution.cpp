class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        int m=buses.size();
        int n=passengers.size();
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int i=0,j=0;
        int cnt=0;
        int lastpas;
        unordered_map<int,int>freq;
             while (i < m) {
            cnt = 0;

            while (j < n && passengers[j] <= buses[i] && cnt < capacity) {
                lastpas = passengers[j];
                cnt++;
                freq[passengers[j]]++;
                j++;
            }

            i++;
        }
        int ans;
               if (cnt < capacity) {
            ans = buses[m - 1];

            while (freq[ans] > 0)
                ans--;

            return ans;
        }
        ans = lastpas - 1;
        while (freq[ans] > 0)
            ans--;
        return ans;
        
    }
};
