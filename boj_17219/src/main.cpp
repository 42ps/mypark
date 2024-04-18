#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    map<string, string> dict;

    for (int i = 0; i < n; i++)
    {
        string site, pw;

        cin >> site >> pw;
        dict[site] = pw;
    }

    for (int i = 0; i < m; i++)
    {
        string target;
        cin >> target;

        cout << dict[target] << '\n';
    }
}