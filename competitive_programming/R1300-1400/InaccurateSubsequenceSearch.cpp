// Problem: D. Inaccurate Subsequence Search
// Contest: Codeforces - Codeforces Round 938 (Div. 3)
// URL: https://codeforces.com/contest/1955/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    map<int, int> countb;
    form
    {
        int t;
        cin >> t;
        if (countb.find(t) == countb.end())
        {
            countb[t] = 0;
        }
        countb[t]++;
    }
    int actual_window_pair = 0;
    form
    {
        if (countb.find(a[j]) != countb.end())
        {
            countb[a[j]]--;
            if (countb[a[j]] >= 0)
            {
                actual_window_pair++;
            }
        }
    }
    int ans = actual_window_pair >= k;
    for (int i = 1; i <= n - m; i++)
    {
        if (countb.find(a[i - 1]) != countb.end())
        {
            countb[a[i - 1]]++;
            if (countb[a[i - 1]] > 0)
            {
                actual_window_pair--;
            }
        }
        if (countb.find(a[i + m - 1]) != countb.end())
        {
            countb[a[i + m - 1]]--;
            if (countb[a[i + m - 1]] >= 0)
            {
                actual_window_pair++;
            }
        }
        ans += actual_window_pair >= k;
    }
    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
