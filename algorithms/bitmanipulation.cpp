/**
 * bit manupulation
 * 
 * representation equivalance:
 * the signed representation of -x = unsigned representation of 2^n-x where n is
 * the size of the number 32 for a 32 bit integer
 * hence signed(-43) = unsigned (2^32 - 43)
 * 
 * overflow condition:
 * in signed form ( 2^(n-1) - 1 )++ = -( 2^(n-1) )
 * (2^31 - 1) + 1 = -( 2^31 )
 * 
 * odd even and divisibility and power of 2
 * if x&1 == 1 => odd
 * if x&1 == 0 => even
 * in general case 
 * if x&(2^k-1) == 0 => divisible by 2^k , 
 * because n is divisible by 8(1000) only when its last 3 binary digits are 0
 * in above examples k = 1
 * 
 * n is power of 2 if x&(x-1) == 0
 * reason: let n be power of 2 n(..00100..00) and n-1(..00011..11) hence 
 *  
 * negation of a number
 * ~x = -x-1
 * 
 * shifting
 * n<<k == n * (2^k) 
 * n>>k == n % (2^k) 
 * 
 * getting and setting bits
 * get ith bit 
 *  n & 1<<i
 * set ith bit to 1 (doing or with 1 gives 1 => futile )
 *  n | 1<<i
 * set ith bit to 0 (doing and with 0 gives 0 => futile )
 *  n & ~(1<<n)
 * invert ith bit of n
 *  n ^ 1<<i    (xor)
 * 
 * other
 * doing x & (x-1) sets the last 1 to 0
 * doing x & (-x) sets all 1 to 0 except the last one
 * doing x | (x-1) inverts all o's to 1's that come afer the last set bit
 */
#include <iostream>
using namespace std;

int countBits(unsigned int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n >>= 1;
    }
    return count;
}

int setBits(int n)
{
    int count{0};
    // while any bit is remaining
    while (n > 0)
    {
        // increse the count
        count++;
        // remove that set bit
        n = n & (n - 1);
    }
    return count;
}

bool isPowerof2(int n)
{
    if (n == 0)
        return false;
    while (n % 2 == 0)
        n = n >> 1;
    return (n == 1);
}

int main()
{
    // for (int i = 0; i <= 8; i++, cout << "----------" << endl)
    // {
    //     cout << "i: " << i << endl;
    //     cout << countBits(i) << endl;
    //     cout << setBits(i) << endl;
    //     const char *ans = isPowerof2(i) ? "true" : "false";
    //     cout << ans << endl;
    // }
    // cout << ~10 << " == " << -10 - 1 << endl;
    int x = 5328;                          // 00000000000000000001010011010000
    cout << __builtin_clz(x) << "\n";      // 19 Count Leading Zeros
    cout << __builtin_ctz(x) << "\n";      // 4  Count Tailing Zeros
    cout << __builtin_popcount(x) << "\n"; // 5  total 1's
    cout << __builtin_parity(x) << "\n";   // 1  parity of number of 1's (even=0 of odd=1)
}