#include <bits/stdc++.h>

using namespace std;

bool knapsack(vector<int> &P, vector<int> &W, int C, int V)
{
    int n = P.size();
    vector<vector<int>> M(n + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= C; w++)
        {
            if (W[i - 1] <= w) // Fix the indexing here
            {
                if ((P[i - 1] + M[i - 1][w - W[i - 1]]) > M[i - 1][w]) // Fix the indexing here
                {
                    M[i][w] = P[i - 1] + M[i - 1][w - W[i - 1]]; // Fix the indexing here
                }
                else
                {
                    M[i][w] = M[i - 1][w]; // Fix the indexing here
                }
            }
            else
            {
                M[i][w] = M[i - 1][w]; // Fix the indexing here
            }
        }
    }
    if (M[n][C] >= V)
        return true;
    return false;
}

bool sos(vector<int> &S, int sum)
{
    if (knapsack(S, S, sum, sum))
        return true;
    return false;
}

int main()
{
    vector<int> s = {3, 2, 7};
    int sum = 6;
    cout << sos(s, sum);

    return 0;
}


// Output 
// s = {3,2,7,1}
// sum = 6
// o: 1

// s = {3,2,7}
// sum = 6
// o: 0