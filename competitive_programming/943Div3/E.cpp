// Problem: E. Cells Arrangement
// Contest: Codeforces - Codeforces Round 943 (Div. 3)
// URL: https://codeforces.com/contest/1968/problem/E
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

void BruteSolve()
{
    return;
}

void Solve()
{
    int n;
    cin >> n;
    vector<pi> cells;
    set<int> dt;
    cells.pb({1, 1});
    cells.pb({2, 1});
    if (n > 2)
    {
        cells.pb({1, 3});
        for (int i = 4; i <= n; i++)
        {
            cells.pb({i, i});
        }
    }
    for (auto x : cells)
    {
        cout << x.first << wp << x.second << endl;
    }
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
