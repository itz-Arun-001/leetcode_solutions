
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
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        while (i >= 0 || j >= 0) {
            int iskip = 0;
            while (i >= 0) {
                if (s[i] == '#') {
                    iskip++;
                    i--;
                } else if (iskip > 0) {
                    iskip--;
                    i--;
                } else
                    break;
            }
            int jskip = 0;
            while (j >= 0) {
                if (t[j] == '#') {
                    jskip++;
                    j--;
                } else if (jskip > 0) {
                    jskip--;
                    j--;
                } else
                    break;
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j])
                    return false;
            } else if (i >= 0 || j >= 0) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};

/*class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1, s2;
        for (char a : s) {
            if (a >= 'a' && a <= 'z') {

                s1.push_back(a);
            } else {
                if (s1 != "")
                    s1.pop_back();
            }
        }
        for (char a : t) {
            if (a >= 'a' && a <= 'z') {
                s2.push_back(a);
            } else {
                if (s2 != "")
                    s2.pop_back();
            }
        }
        return (s1 == s2) ? true : false;
    }
};*/
