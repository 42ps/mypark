#include <iostream>
#include <vector>

using namespace std;

const size_t pos[4][2] = {
    {0, 0},
    {0, 1},
    {1, 0},
    {1, 1},
};

int dq(const vector<vector<size_t>> &paper, size_t x, size_t y, size_t len, size_t cnt[])
{
    int results[4];
    int one_color = 0;

    if (len == 1)
    {
        return paper[x][y];
    }

    size_t h = len / 2;

    for (int i = 0; i < 4; i++)
    {
        size_t nx = x + pos[i][0] * h;
        size_t ny = y + pos[i][1] * h;
        results[i] = dq(paper, nx, ny, h, cnt);
        one_color += results[i];
    }

    if (one_color == 0 || one_color == 4)
    {
        return one_color / 4;
    }

    for (auto r : results)
    {
        cnt[r]++;
    }

    return 5;
}

int main(void)
{
    size_t n;

    cin >> n;

    vector<vector<size_t>> paper(n, vector<size_t>(n, 0));

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }

    size_t cnt[6] = {0};
    int last = dq(paper, 0, 0, n, cnt);

    cnt[last]++;

    cout << cnt[0] << '\n';
    cout << cnt[1] << '\n';
}