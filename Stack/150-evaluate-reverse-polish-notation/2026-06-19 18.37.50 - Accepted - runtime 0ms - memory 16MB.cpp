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









class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> st;
        for (string s : t) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                if (s == "+") {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(a + b);
                } else if (s == "-") {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(b - a);
                } else if (s == "*") {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(a * b);

                } else {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(b / a);
                }
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};