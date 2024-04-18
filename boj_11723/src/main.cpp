#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    set<size_t> s;
    size_t n;
    stringstream ss("");

    cin >> n;

    for (auto i = 0; i < n; i++)
    {
        string cmd;
        size_t x;

        cin >> cmd;

        if (cmd == "all")
        {
            for (auto j = 1; j <= 20; j++)
            {
                s.insert(j);
            }
            continue;
        }
        else if (cmd == "empty")
        {
            s.clear();
            continue;
        }

        cin >> x;

        if (cmd == "add")
            s.insert(x);
        else if (cmd == "remove")
            s.erase(x);
        else if (cmd == "check")
        {
            cout << s.count(x) << '\n';
        }
        else if (cmd == "toggle")
        {
            if (s.count(x))
                s.erase(x);
            else
                s.insert(x);
        }
    }
}
