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
    for (int i = 0; i <= 8; i++)
    {
        cout << countBits(i) << endl;
    }
}