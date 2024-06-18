// Problem: A. Guess the Maximum
// Contest: Codeforces - Codeforces Round 951 (Div. 2)
// URL: https://codeforces.com/contest/1979/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

void BruteSolve() { return; }

void Solve() {
  int n;
  cin >> n;
  int a[n];
  forn { cin >> a[i]; }
  long long min_max = 1e9 + 1;
  for (int i = 0; i < n - 1; i++) {
    min_max = min((long long)max(a[i], a[i + 1]), min_max);
  }
  cout << min_max - 1 << endl;

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_cases;
  cin >> test_cases;
  while (test_cases-- > 0) {
    Solve();
  }
  return 0;
}
