#include <bits/stdc++.h>

using namespace std;

void horspool_string_matching(string t, string p, vector<int> &shift)
{
    int n = t.size();
    int m = p.size();

    int i = m - 1;
    while (i < n)
    {
        int k = 0;
        while (k < m && t[i - k] == p[m - k - 1])
        {
            k++;
        }
        if (k == m)
            cout << "Pattern occurs with shift " << i - m + 1 << endl;
        if (t[i] == ' ')
        {
            i += m;
        }
        else
        {
            i += shift[t[i] - 'a'];
        }
    }
}

int main()
{
    string str = "jimmy hailed leader to leader stop";
    string sstr = "leader";
    int m = sstr.size();
    vector<int> shift_table(27, m);
    for (int i = 0; i < sstr.size() - 1; i++)
    {
        shift_table[sstr[i] - 'a'] = m - i - 1;
    }

    cout << "\nShift table\n";
    for (auto x : shift_table)
    {
        cout << x << " ";
    }
    cout << "\n\n";

    horspool_string_matching(str, sstr, shift_table);
    return 0;
}

// Output

// Shift table
// 3 6 6 2 1 6 6 6 6 6 6 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6

// Pattern occurs with shift 13
// Pattern occurs with shift 23