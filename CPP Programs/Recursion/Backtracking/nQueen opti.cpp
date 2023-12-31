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

// Print the board
void printBoard(int board[][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
                cout << " Q ";
            else
                cout << " _ ";
        }
        cout << nline;
    }
    cout << nline;
}

// Variables to maintain pos of col, left diagonal, right diagonal
bitset<32> col, ld, rd;

bool isSafePositionOptimised(int i, int j, int n)
{
    // Check col
    if (col[j])
        return false;

    // Check left diagonal
    if (ld[i - j + n - 1])
        return false;

    // Check right diagonal
    if (rd[i + j])
        return false;

    // If all fine : then make those values 1 and return true
    col[j] = ld[i - j + n - 1] = rd[i + j] = 1;
    return true;
}

// Give 1 solution for the nQueen problem
bool nQueenProblem(int board[][10], int m, int n, int i)
{
    // Base Case
    if (i == m)
    {
        // Print board
        printBoard(board, m, n);

        return true;
    }

    // Recursive Case
    // Start with first row : check whether we can place the queen at the current postion
    // To check : 1. Check if there is already any queen presents in the current col
    // 2. Check if diagonally up left and up right any queen is present or not
    // If not place the queen and move to the next row
    // Otherwise, don't place the queen, return false and backtrack.

    // Try to place queen at every col position in the current row
    for (int j = 0; j < n; j++)
    {
        if (isSafePositionOptimised(i, j, n))
        {
            board[i][j] = 1; // Place the queen

            // Next recursion call
            bool nextQueenRakhPaye = nQueenProblem(board, m, n, i + 1);
            if (nextQueenRakhPaye)
                return true;

            // Backtrack
            // If placing queen in board[i][col] doesn't lead to a solution, then
            // remove queen from board[i][col]

            board[i][j] = 0; // Backtrack
            col[j] = ld[i - j + n - 1] = rd[i + j] = 0;
        }
    }

    // We have tried for all positions in the current row and could not place the queen
    // Remember we are calling recursion at each row so return false if we can not place queen at that row
    return false;
}

void solve()
{
    int x;
    cin >> x;

    int board[10][10] = {0};
    int m(x), n(x);

    // For one solution
    nQueenProblem(board, m, n, 0);
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