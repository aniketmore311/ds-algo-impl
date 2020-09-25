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
int main()
{
    for (int i = 0; i <= 8; i++)
    {
        cout << countBits(i) << endl;
    }
}