// iterative soution to 0-1 knapsack (dynamic programming)
//author: aniket more
//date: 23-05-2020

#include <iostream>
using namespace std;

int maxVal(int n, int w, int values[], int weights[])
{
    int dp[n + 1][w + 1];
    int i, j;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i] <= j)
                dp[i][j] = max(values[i] + dp[i - 1][j - weights[i]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][w];
}

void solve()
{
    int i, n, w;
    cin >> n >> w;

    int values[n + 1];
    int weights[n + 1];
    for (i = 1; i <= n; i++)
    {
        cin >> values[i];
    }
    for (i = 1; i <= n; i++)
    {
        cin >> weights[i];
    }

    int result = maxVal(n, w, values, weights);

    cout << result << endl;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
