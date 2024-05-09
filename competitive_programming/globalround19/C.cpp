// Problem: C. Andrew and Stones
// Contest: Codeforces - Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int n;
    cin >> n;
    int a[n];
    ull sum_e = 0;
    ull sum_o = 0;
    forn
    {
        cin >> a[i];
    }
    int odds = 0;
    int ones = 0;
    for (int i = 1; i < n - 1; i++)
    {
        odds += a[i] % 2;
        ones += a[i] == 1;
        sum_e += ((a[i] + 1) % 2) * a[i];
        sum_o += (a[i] % 2) * a[i];
    }
    if (sum_e > 0 || ((odds > ones) && odds > 1))
    {
        cout << sum_e / 2 + (sum_o + odds) / 2 << endl;
    }
    else
    {
        cout << -1 << endl;
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