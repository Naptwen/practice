#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

// int tri2(vector<vector<int> > *vec, int i, int j)
// {
//     if (i + 1 == (*vec).size())
//         return (*vec)[i][j];
//     return (*vec)[i][j] + max(tri2(vec, i + 1, j + 1), tri2(vec, i + 1, j));
// }

// int solution2(vector<vector<int> > triangle)
// {
//     int answer = 0;
//     return answer = tri2(&triangle, 0, 0);
// }

// int tri(vector<vector<int> > *vec, int i, int j)
// {
//     int a = 0, b = 0;
//     if (i == 0)
//         return (*vec)[0][0];
//     if (j - 1 >= 0)
//         a = tri(vec, i - 1, j - 1);
//     if (j < (*vec)[i - 1].size())
//         b = tri(vec, i - 1, j);
//     return (*vec)[i][j] + max(a, b);
// }

int solution(vector<vector<int> > triangle)
{ 
    //top down
    vector<vector<int> > dp(triangle.begin(), triangle.end());
    for (int i = 0; i< triangle.size() - 1; i++){
        for (int j = 0; j< triangle[i].size(); j++){
            dp[i + 1][j    ] =  max(dp[i + 1][j    ], dp[i][j] + triangle[i + 1][j]);
            dp[i + 1][j + 1] =  max(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
        }    
    } 
    return  *max_element(dp.back().begin(), dp.back().end());
}

int main()
{
    int a[5][5] =   {{7, 0, 0, 0, 0},
                    {3, 8, 0, 0, 0},
                    {8, 1, 0, 0, 0},
                    {2, 7, 4, 4, 0},
                    {4, 5, 2, 6, 5}};
    vector<vector<int> > test(5);
    test[0].push_back(a[0][0]);
    test[1].push_back(a[1][0]);
    test[1].push_back(a[1][1]);
    test[2].push_back(a[2][0]);
    test[2].push_back(a[2][1]);
    test[2].push_back(a[2][2]);
    test[3].push_back(a[3][0]);
    test[3].push_back(a[3][1]);
    test[3].push_back(a[3][2]);
    test[3].push_back(a[3][3]);
    test[4].push_back(a[4][0]);
    test[4].push_back(a[4][1]);
    test[4].push_back(a[4][2]);
    test[4].push_back(a[4][3]);
    test[4].push_back(a[4][4]);
    printf("%d\n", solution(test));
}