#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> cell(n,vector<int>(n,0));
    int answer = 0;
    for(auto v : results){
        cell[v[0] - 1][v[1] - 1] = 1; //이긴 경기
        cell[v[1] - 1][v[0] - 1] = -1; //진 경기
    }
    for(int i =0; i < n; i++)
        for(int j =0; j < n; j++){
            if(cell[i][j] == 1) //승리 한 대상
                for(int k = 0; k<n; k++) 
                    if(cell[j][k] == 1) cell[i][k] = 1, cell[k][i] = -1; //대상이 승리한 상대
            if(cell[i][j] == -1) //진 대상
                for(int k = 0; k<n; k++) 
                    if(cell[j][k] == -1) cell[i][k] = -1, cell[k][i] = 1; //대상이 진 상대
        }
    for(auto vec: cell){
        for(auto vec2: vec)
            cout << vec2 << ", ";
        cout << endl;
    }

    for(auto vec: cell){
        cout << count_if(vec.begin(), vec.end(), [](int k){return (k == 1 || k == -1);}) << endl;
        answer += (count_if(vec.begin(), vec.end(), [](int k){return (k == 1 || k == -1);}) == n-1)?1:0;
    }
    return answer;
}

int main(){
    vector<vector<int>> test = {{4,3},{4,2},{3,2},{1,2},{2,5},{2,6},{2,7}};
    // test = {{4,3},{4,2},{3,2},{1,2},{2,5}, {2,6}, {6,5}};
    test = {{1,2},{4,5},{3,4},{2,3}};
    test = {{4,3}, {4,2}, {3,2}, {1,2}, {2,5}};
    int num = 5;
    int ans = solution(num, test);
    printf("ans = %d\n", ans);
    return 0;
}