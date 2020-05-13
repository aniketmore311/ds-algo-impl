//math: prime checker, factorization, prime factorization, euclid's gcd
//author: aniket more
//date: 13/05/2020
#include <iostream>
#include <vector>

using namespace std;

bool isprime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int gcd(int a, int b) // euclid's gcd algorithm
{
    if (b == 0)
        return a;
    else
    {
        gcd(b, a % b);
    }
}

long long lcm(int a, int b)
{
    long long answer = (a * b) / gcd(a, b);
    return answer;
}

vector<int> allFactorsVector(int n)
{
    vector<int> v;
    for (int i = 1; i * i <= n; i++) //the loop
    {
        if (n % i == 0) // if i is a factor
        {
            v.push_back(i);         // add i
            if (i * i != n)         // if i is not the root factor
                v.push_back(n / i); // then only add its cofactor
        }
    }
    return v;
}

vector<int> primeFactorsVector(int n) //implementation which returns a vector
{
    vector<int> v;                   //vector to be returned
    for (int i = 2; i * i <= n; i++) // the loop
    {
        while (n % i == 0) // if a factor is found
        {
            v.push_back(i); // add it to the list
            n = n / i;      // divide n by that factor untill n is no longer divisible by that factor
        }
    }
    if (n != 1)         // at this point if n is not 1 that means n has no factor in 2 to sqrt(n) that means it is a prime
        v.push_back(n); // prime is its own prime factor
    return v;           //return the vector
}

void printVector(vector<int> vec)
{
    for (auto num : vec)
        cout << num << " ";
    cout << "\n";
}

int main()
{
    vector<int> f, pf;
    cout << isprime(8) << endl;  //0
    cout << isprime(13) << endl; //1
    cout << isprime(0) << endl;  // 0
    cout << isprime(1) << endl;  //0

    f = allFactorsVector(44); // 1 44 2 22 4 11
    printVector(f);

    pf = primeFactorsVector(44); //2 2 11
    printVector(pf);

    cout << gcd(21, 24) << endl; //3
    cout << gcd(1, 10) << endl;  // 1
    cout << gcd(2, 8) << endl;   // 2

    cout << lcm(7, 9) << endl; //63
    cout << lcm(2, 4) << endl; // 4
    cout << lcm(1, 5) << endl; // 5


}
