#include <bits/stdc++.h>

using namespace std;

void string_matching(string t, string p)
{
    int n = t.size();
    int m = p.size();

    for (int s = 0; s <= n - m; s++)
    {
        int i = 0, j = 0;
        while (j < m && t[s + i] == p[i])
        {
            i++;
            j++;
        }
        if (j == m)
            cout << "Pattern occurs with shift " << s << endl;
    }
}

int main()
{
    string str = "abaabaaab";
    string sstr = "ab";
    string_matching(str, sstr);
    return 0;
}

/* Output */
// Pattern occurs with shift 0
// Pattern occurs with shift 3
// Pattern occurs with shift 7