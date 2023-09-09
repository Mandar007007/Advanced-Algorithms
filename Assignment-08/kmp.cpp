#include <bits/stdc++.h>

using namespace std;

int main()
{
    string pattern = "0aaabb";
    int cnt = 0;
    vector<int> pi(20, 0);
    int k = 0;
    for (int q = 2; q <= pattern.size() - 1; q++)
    {
        bool t = (pattern[k + 1] != pattern[q]);
        cnt++;
        while (k > 0 && t)
        {
            k = pi[k];
            t = (pattern[k + 1] != pattern[q]);
            cnt++;
        }
        if (!t)
            k++;
        pi[q] = k;
    }
    cout << cnt << endl;
    for (auto x : pi)
        cout << x << " ";
    return 0;
}
