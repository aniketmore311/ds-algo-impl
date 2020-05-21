#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dp[1002][1002]; // this will be for memoization form i from 1 to n and j from 1 to w

int MaxVal(int n, int w, int values[], int weights[]) //recursive memoized function
{
    if (n == 0 || w == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (weights[n] <= w)
    {
        return dp[n][w] = max((values[n] + MaxVal(n - 1, w - weights[n], values, weights)), MaxVal(n - 1, w, values, weights));
    }
    else if (weights[n] > w)
    {
        return dp[n][w] = MaxVal(n - 1, w, values, weights);
    }
}

void solve()
{

    int n, i, j;
    cin >> n;

    int w;
    cin >> w;

    for (i = 0; i <= n; ++i) //initialising dp[][]
    {
        for (j = 0; j <= w; ++j)
        {
            dp[i][j] = -1;
        }
    }

    int values[n + 1]; // values are in indices 1 to n
    for (i = 1; i <= n; i++)
    {
        cin >> values[i];
    }

    int weights[n + 1]; //weights are in 1 to w
    for (i = 1; i <= n; i++)
    {
        cin >> weights[i];
    }

    int result = MaxVal(n, w, values, weights);

    cout << result << endl;
}

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}