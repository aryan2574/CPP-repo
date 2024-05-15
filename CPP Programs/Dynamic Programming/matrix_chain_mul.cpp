#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mod1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"

#define sz(x) ((int)(x).size())
#define set_bits __builtin_popcount
#define set_bitsll __builtin_popcountll
#define setp(x, y) fixed << setprecision(y) << x

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define scnfi(n) scanf("%d", &n)
#define scnfii(n, m) scanf("%d%d", &n, &m)
#define scnfl(n) scanf("%I64d", &n)
#define scnfll(n, m) scanf("%lld%lld", &n, &m)
#define scnfstr(str) scanf("%s", &str);

#define prntfi(n) printf("%d\n", n)
#define prntfii(n, m) printf("%d %d\n", n, m)
#define prntfl(n) printf("%I64d\n", n)
#define prntfll(n, m) printf("%I64d %I64d\n", n, m)
#define prntfstr(s) printf("%s\n", s)

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

void ayush_2574_cp()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

// ____________________________________________________________________________________

// Matrix chain multiplication --
// Time - O(N^3)
// Space - O(N)

/*
I/P:
2
4
4 5 3 2
4
10 15 20 25


O/p:
70
8000
*/

// DP Solution - Memoization
int f2(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + f2(i, k, arr, dp) + f2(k + 1, j, arr, dp);
        mini = min(mini, steps);
    }

    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N, vector<vector<int>> &dp)
{
    return f2(1, N - 1, arr, dp);
}

// Recursion solution - O(2^N)
int f(int i, int j, vector<int> &arr)
{
    if (i == j)
        return 0;

    int mini = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int steps = (arr[i - 1] * arr[k] * arr[j]) + f(i, k, arr) + f(k + 1, j, arr);
        mini = min(mini, steps);
    }

    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    return f(1, N - 1, arr);
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        // Initialize the dp array with -1
        vector<vector<int>> dp(N, vector<int>(N, -1));

        // Calling the recursive solution
        cout << matrixMultiplication(arr, N) << endl;

        // Calling the memoized DP solution
        cout << matrixMultiplication(arr, N, dp) << endl;
    }
}

// _____________________________________________________________________________________

signed main(void)
{
    auto t1 = std::chrono::high_resolution_clock::now();
    ayush_2574_cp();
    solve();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    // cout << "Time : " << duration.count() << " ms" << endl;
    debug(duration.count());
    return 0;
}