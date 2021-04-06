#include <bits/stdc++.h>
#include <math.h>
using namespace std;
// debugging
//------------------------------------------------------------------------------
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define deb(x...)                 \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define deb(x...)
#endif
void print(int arr[], int n)
{
    cerr << "[ ";
    for (int i = 0; i < n; i++)
    {
        cerr << arr[i] << ", ";
    }
    cerr << "] " << endl;
}
// typedef
//------------------------------------------------------------------------------
typedef long long int ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define ff first
#define ss second
#define pb push_back
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const ll MOD = 998244353;
const ll INF = 1e18;
const ll maxn = 2e5 + 5;
//-----------------------------------------------------------------------------
void merge(int arr[], int lo, int hi, int mid)
{
    if (hi <= lo)
        return;
    int k = 0;
    int aux[hi - lo + 1];
    int i = lo;
    int j = mid + 1;
    for (k = 0; k < (hi - lo + 1); k++)
    {
        if (i > mid)
        {
            aux[k] = arr[j];
            j++;
        }
        else if (j > hi)
        {
            aux[k] = arr[i];
            i++;
        }
        else if (arr[i] <= arr[j])
        {
            aux[k] = arr[i];
            i++;
        }
        else if (arr[j] <= arr[k])
        {
            aux[k] = arr[j];
            j++;
        }
    }
    for (int l = 0, m = lo; l < (hi - lo + 1); l++, m++)
    {
        arr[m] = aux[l];
    }
}

void mergeSort(int arr[], int lo, int hi)
{
    if (hi <= lo)
        return;
    int mid = lo + (hi - lo) / 2;
    mergeSort(arr, 0, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, hi, mid);
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    print(arr, n);
    mergeSort(arr, 0, n - 1);
    print(arr, n);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOS int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
