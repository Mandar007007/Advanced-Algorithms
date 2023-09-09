#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> buildDFA(const string &substring)
{
    int m = substring.length();
    vector<int> dfa(m + 1, 0);

    int j = 0;
    for (int i = 1; i < m; ++i)
    {
        while (j > 0 && substring[i] != substring[j])
        {
            j = dfa[j - 1];
        }

        if (substring[i] == substring[j])
        {
            j++;
        }

        dfa[i] = j;
    }

    return dfa;
}

vector<int> findOccurrences(const string &text, const string &substring)
{
    vector<int> dfa = buildDFA(substring);
    vector<int> occurrences;
    int n = text.length();
    int m = substring.length();
    int j = 0;

    for (int i = 0; i < n; ++i)
    {
        while (j > 0 && text[i] != substring[j])
        {
            j = dfa[j - 1];
        }

        if (text[i] == substring[j])
        {
            j++;
        }

        if (j == m)
        {
            occurrences.push_back(i - m + 1);
            j = dfa[j - 1];
        }
    }

    return occurrences;
}

int main()
{
    string text = "ababcababcabcabc";
    string substring = "abc";

    vector<int> result = findOccurrences(text, substring);

    if (result.empty())
    {
        cout << "No occurrences found." << endl;
    }
    else
    {
        cout << "Occurrences found at positions:";
        for (int pos : result)
        {
            cout << " " << pos;
        }
        cout << endl;
    }

    return 0;
}

// Output
// Occurrences found at positions: 2 7 10 13