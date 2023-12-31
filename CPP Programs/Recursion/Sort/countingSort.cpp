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

// Counting Sort - O(N + Range)
// Not suitable to large ranges

/*
Step 1 : Calculate Frequency of the numbers in the array
Step 2 : Iterate through frequency array and print the numbers by their frequency times
    eq:  Freq[6] = 2 : print 6 6

Since we are iterating through 0 in our frequency array - newly created array will be sorted
*/

/*
Algorithm Steps:

    Find the Range: First, identify the range of input elements. This means finding the minimum and maximum values present in the input array.

    Count Frequencies: Create a counting array count of size (maxValue - minValue + 1) and initialize all its elements to 0. Then, traverse the input array and increment the corresponding count for each element. The index of count array represents the value in the input array.
*/

int inp[] = {88, 97, 10, 12, 15, 9, 5, 6, 12, 5, 8};

void solve()
{
    // Take Input
    int n = sizeof(inp) / sizeof(int);

    // Vector to store the sorted array
    vector<int> sortedArray;

    // Find maximum in the array to create frequency array
    int mx = *max_element(&inp[0], &inp[n - 1]);

    // Find the minimum in the array
    int mn = *min_element(&inp[0], &inp[n - 1]);

    // Frequency Array
    int *freq = new int[mx + 1]{0};

    for (int i = 0; i < n; i++)
    {
        freq[inp[i]]++;
    }

    // Create sorted array according to frequency
    for (int i = mn, currFreq; i <= mx; i++)
    {
        currFreq = freq[i]; // Store the current frequency of the number - Index : 1 have 5 frequency. eg - 1 1 1 1 1
        if (currFreq)
        {
            while (currFreq)
            {
                sortedArray.push_back(i);
                currFreq--;
            }
        }
        currFreq = 0;
    }

    // Print sorted Array
    for (auto ele : sortedArray)
        cout << ele << ' ';

    cout << nline;

    // Inline sorting - Change the parent array according to the frequency
    for (int i = 0, j = 0; i <= mx; i++)
    {
        while (freq[i] > 0)
        {
            inp[j++] = i;
            freq[i]--;
        }
    }

    for (int i = 0; i < n; i++)
        cout << inp[i] << ' ';
    cout << nline;

    // Delete Frequency Array
    delete[] freq;
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