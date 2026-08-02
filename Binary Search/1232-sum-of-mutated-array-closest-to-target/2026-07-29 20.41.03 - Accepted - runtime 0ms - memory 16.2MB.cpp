class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int mx = *max_element(arr.begin(), arr.end());
       
        int l = 0, r = mx;
        while (l<=r) {
            int m = l + (r - l) / 2;
            int sum = 0;
            for (int x : arr) {
                if (x > m)
                    sum += m;
                else
                    sum += x;
            }
            if (sum == target)
                return m;

            else if (sum > target)
                r = m - 1;
            else
                l = m + 1;
          
        }
        int suml = 0;
        for (int x : arr) {
            if (x > l)
                suml += l;
            else
                suml += x;
        }
        int sumr = 0;
        for (int x : arr) {
            if (x > r)
                sumr += r;
            else
                sumr += x;
        }
        int d1=abs(suml-target);
        int d2=abs(sumr-target);
        return (d1<d2)?l:r;
    }
};