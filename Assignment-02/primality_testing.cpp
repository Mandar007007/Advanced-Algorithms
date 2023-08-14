#include <iostream>
#include <random>
#include <ctime>

using namespace std;

unsigned int gcd(unsigned int, unsigned int);
unsigned int power(unsigned int, unsigned int, unsigned int);
bool primality_test(unsigned int);

int main()
{
    srand((unsigned)time(NULL));
    unsigned int number = 100007;
    cout << primality_test(number);
    return 0;
}

bool primality_test(unsigned int number)
{
    if (number <= 1 || number == 4)
        return false;
    if (number <= 3)
        return true;
    int k = 5000; // Increase the number of iterations for larger numbers
    while (k > 0)
    {
        unsigned int a = 2 + (rand() % (number - 4));
        if (gcd(number, a) != 1)
            return false;
        if (power(a, number - 1, number) != 1)
            return false;
        k--;
    }
    return true;
}

unsigned int gcd(unsigned int a, unsigned int b)
{
    if (a < b)
        return gcd(b, a);
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

unsigned int power(unsigned int a, unsigned int n, unsigned int p)
{
    unsigned int res = 1;
    a = a % p;
    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % p;
        n = n >> 1;
        a = (a * a) % p;
    }
    return res;
}
