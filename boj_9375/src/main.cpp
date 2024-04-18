#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solve()
{
    int n;
    cin >> n;
    unordered_map<string, int> counts;

    for (int i = 0; i < n; i++)
    {
        string name, type;
        cin >> name >> type;
        counts[type]++;
    }

    vector<int> v_counts;

    for (auto c : counts)
    {
        v_counts.push_back(c.second);
    }

    if (v_counts.empty())
    {
        return 0;
    }

    vector<int> comb(v_counts.size(), 0);
    int cn = comb.size();

    comb[0] = v_counts[0];

    for (int i = 1; i < cn; i++)
    {
        int p = comb[i - 1];
        int c = v_counts[i];
        comb[i] = p + c + p * c;
    }

    return comb[cn - 1];
}

int main(void)
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cout << solve() << '\n';
    }
}