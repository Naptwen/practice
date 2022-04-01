#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int solution(int m, int n, vector<vector<int>> puddles)
{
    vector<vector<int>> path(m, vector<int>(n, 0));
    for (int i = 0; i < puddles.size(); i++)
        path[puddles[i][0] - 1][puddles[i][1] - 1] = -1; // set 0

    path[0][0] = 1;
    for (int k = 0; k < m + n - 1; k++)
        for(int i = 0, j = k-i; i <= k; i++, j = k-i){
            if ( i <m && j <n && path[i][j] != -1)
                {
                    if (i + 1 < m  &&  path[i + 1][j] != -1)
                        path[i + 1][j] += path[i][j];
                    if (j + 1 < n &&  path[i][j + 1] != -1)
                        path[i][j + 1] += path[i][j];
                }
        }
    return path[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> test = {{2, 2}};
    int answ = solution(4, 3, test);
    printf("%d\n", answ);
    return 0;
}