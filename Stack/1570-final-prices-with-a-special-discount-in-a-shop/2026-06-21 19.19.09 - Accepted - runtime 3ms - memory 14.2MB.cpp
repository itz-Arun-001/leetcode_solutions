/*class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for(int i=0;i<prices.size();i++)
        {
            for(int j=i+1;j<prices.size();j++)
            {
                if(prices[i]>=prices[j]){
                    prices[i]-=prices[j];
                    break;
                }
            }
        }
        return prices;

    }
};*/
/*
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        for (int i = 0; i < prices.size(); i++) {
            if (st.empty()) {
                st.push(i);
                continue;
            } else if (prices[st.top()] >= prices[i]) {
                while (!st.empty() && prices[st.top()] >= prices[i]) {
                    prices[st.top()] -= prices[i];
                    st.pop();
                }
                st.push(i);
            } else {
                st.push(i);
            }
        }
        return prices;
    }
};*/
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
};