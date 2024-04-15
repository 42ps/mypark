#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    cin.tie(NULL);

    unordered_map<int, string> no_to_name;
    unordered_map<string, int> name_to_no;

    size_t n, m;
    string name;

    name.reserve(20);

    cin >> n >> m;

    for (auto i = 0; i < n; i++)
    {
        auto no = i + 1;

        cin >> name;
        no_to_name.insert(make_pair(no, string(name)));
        name_to_no.insert(make_pair(name, no));

        name.clear();
    }

    string problem;
    problem.reserve(20);

    for (auto i = 0; i < m; i++)
    {
        cin >> problem;

        try
        {
            auto no = stoi(problem);
            cout << no_to_name.find(no)->second << '\n';
        }
        catch (std::exception e)
        {
            cout << name_to_no.find(problem)->second << '\n';
        }

        problem.clear();
    }
}