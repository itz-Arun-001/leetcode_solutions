
#include <bits/stdc++.h>
#pragma GCC target("abm")
#pragma GCC target("bmi")
#pragma GCC target("avx2")
#pragma GCC target("bmi2")
#pragma GCC target("lzcnt")
#pragma GCC target("popcnt")
#pragma GCC target("native")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-march=native")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insnS2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-Pointer-checks")


using namespace std;
static const size_t ARENA_SIZE = 1 << 26; 
alignas(max_align_t) static unsigned char arena[ARENA_SIZE];
static size_t arena_pos = 0;

void* operator new(size_t sz) {
    size_t aligned = (sz + alignof(max_align_t) - 1) & ~(alignof(max_align_t) - 1);
    if (arena_pos + aligned > ARENA_SIZE) {
        throw bad_alloc();
    }
    void* ptr = arena + arena_pos;
    arena_pos += aligned;
    return ptr;
}

void operator delete(void*) noexcept {}
void operator delete(void*, size_t) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete[](void *, size_t) noexcept {}

/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int height = heights[i];

            int left = i;
            int right = i;

            // go left
            while(left >= 0 && heights[left] >= height)
                left--;

            // go right
            while(right < n && heights[right] >= height)
                right++;

            int width = right - left - 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};
*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea = 0;
        stack<int>st;

        for(int i = 0; i < n; i++) {
            while(!st.empty()&&heights[st.top()]>heights[i])
            {
                int index=st.top();
                st.pop();
                int nse=i;   //nse is next smaller element     //pse is previous smaller element
                int pse=(st.empty())?-1:st.top();
                maxarea=max(maxarea,heights[index]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int index=st.top();   st.pop();
            int nse=n;
            int pse=(!st.empty())?st.top():-1;
            maxarea=max(maxarea,heights[index]*(nse-pse-1));
        }
        return maxarea;
    }
};