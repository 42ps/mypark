#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(void)
{
    size_t n, m;
    cin >> n >> m;

    set<string> d_set;
    set<string> b_set;

    for (auto i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        d_set.insert(s);
    }

    for (auto i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        b_set.insert(s);
    }

    vector<string> inter(d_set.size() + b_set.size());

    auto end = set_intersection(d_set.begin(), d_set.end(), b_set.begin(), b_set.end(), inter.begin());
    inter.erase(end, inter.end());

    cout << inter.size() << '\n';
    for (auto e : inter)
    {
        cout << e << '\n';
    }
}
