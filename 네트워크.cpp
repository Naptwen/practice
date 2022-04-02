#include <string>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> *c, int i)
{
    if((*c)[i][i] == 0) return false;
    (*c)[i][i] = 0;
    for (int j = 0; j < (*c)[0].size(); j++)
        if((*c)[i][j]) dfs(c, j);
    return true;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    for (int k = 0; k < computers.size(); k++)
       if(dfs(&computers, k)) answer++;
    return answer;
}

int main()
{
    vector<vector<int>> test = {{1, 1, 0, 1}, {1, 1, 0, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}};
    test = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int ans = solution(3, test);
    printf("%d\n", ans);
    return 0;
}