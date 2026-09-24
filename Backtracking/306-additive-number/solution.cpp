/*class Solution {
public:
    bool ans = false;
    bool help(string& num,int idx,int& n,int cnt,long long& prev1,long long&
prev2) { if (idx==n) return cnt>=3; if (idx>n) return false;
        // if(prev1+prev2==curr) return true;
        for (int i=idx;i<n;i++) {
            if (num[idx]=='0'&&i>idx)
                break;
            string a=num.substr(idx,i - idx+1);
            long long val=stoll(a);
            /*if(cnt<2)
            {
                temp.push_back(val);
                if(temp.size()<2 )
                {
                    prev1=val;
                }
                else{
                    prev2=val;
                }
                if(help(num,i+1,n,temp,prev1,prev2))
                     return true;
                temp.pop_back();
            }//<-- break
            if (cnt<2) {
                if (cnt==0) {
                    prev1 = val;
                    if (help(num,i+1,n, cnt+1,prev1,prev2))
                        return true;
                } else {
                    prev2=val;
                 if (help(num,i+1,n, cnt+1,prev1,prev2))
                        return true;
                }
                continue;
            }
            if (prev1+prev2!=val)
                continue;
            long long x=prev1;
            prev1=prev2;
            prev2=val;
            if(help(num,i +1,n,cnt+1, prev1, prev2))
                return true;
            prev2=prev1;
            prev1=x;
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        int n=num.size(),cnt=0;
        long long p1=0,p2=0;
        return help(num,0,n,cnt,p1,p2);
        // return ans;
    }
};*/

class Solution {
public:
    bool help(string& num, int idx, int& n, int cnt, long long& prev1,
              long long& prev2) {
        if (idx == n)
            return cnt >= 3;

        for (int i = idx; i < n; i++) {
            if (num[idx] == '0' && i > idx)
                break;

            if (cnt < 2) {
                string a = num.substr(idx, i - idx + 1);

                if (a.size() > 18)
                    break;

                long long val = stoll(a);

                if (cnt == 0) {
                    prev1 = val;
                    if (help(num, i + 1, n, cnt + 1, prev1, prev2))
                        return true;
                } else {
                    prev2 = val;
                    if (help(num, i + 1, n, cnt + 1, prev1, prev2))
                        return true;
                }

                continue;
            }

            long long val = prev1 + prev2;
            string expected = to_string(val);

            if (num.compare(idx, expected.size(), expected) != 0)
                continue;

            long long x = prev1;
            prev1 = prev2;
            prev2 = val;

            if (help(num, idx + expected.size(), n, cnt + 1, prev1, prev2))
                return true;

            prev1 = x;
            prev2 = val;
        }

        return false;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();
        long long p1 = 0, p2 = 0;
        return help(num, 0, n, 0, p1, p2);
    }
};
