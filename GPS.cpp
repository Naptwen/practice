#include <vector>
#include <iostream>
using namespace std;
#define INT_MAX 2147483646

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
// 거점 갯수 n, 도로개수 m, 도롱연결 정보 edge_list 택시 시간대별로 보내오는 거점 정보의 총개수 k 머물렀던 거점의 정보 gps_log
// BFS로 풀이하였으나 한계에 부딫힘
// 참고 https://yabmoons.tistory.com/586 참고
// 참고 https://ansohxxn.github.io/programmers/130/
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log)
{
    int answer = 0;
    vector<vector<int>> edges(n + 1);   // gps_log에 등록된 값을 그대로 받기위하여 + 1사이즈
    for (auto vec : edge_list)          // connection check
    {
        edges[vec.front()].push_back(vec.back()); 
        edges[vec.back()].push_back(vec.front());
    }
    vector<vector<int>> dp_logs(k, vector<int>(n + 1, INT_MAX));              //로그위치에서 뱐화되는 위치의 갑 저장을 위해서 인덱스 + 1
    dp_logs[0][gps_log[0]] = 0;                                               //초기값은 변화가 없으므로 0
    for (int i = 1; i < k; i++)                                                //로그를 차례로 확인해나간다.
        for(int j = 1; j <= n; j++){                                           //i번쨰 로그기록에서 비교할 모든 노드들 검색    
            dp_logs[i][j] =  dp_logs[i - 1][j];                                 //그전 노드에서의 현재 노드로의 변화값(최소값)을 받는다.
            for (int t = 0; t < edges[j].size(); t++){                          //j번 노드의 이웃들을 탐색
                //j번 노드의 이웃노드가 i번 로그에 기록된 노드와 다르면 
                //i - 1번째 노드에서 i 번째 노드로 이동할때 변경되었다는 뜻이므로          
                //dp기록 i 번째 에서 j 노드까지 최소 수정획수 기록
                dp_logs[i][j] = min(dp_logs[i][j], dp_logs[i - 1][edges[j][t]]); //최소 
            }
            if(gps_log[i] != j && dp_logs[i][j] != INT_MAX)
                dp_logs[i][j]++;
        }
    if(dp_logs[k - 1][gps_log[k - 1]] == INT_MAX) return -1;
    return dp_logs[k - 1][gps_log[k - 1]];
}

int main(){
    vector<vector<int>> vec = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
    int k  = 6;
    vector<int> gps_log = {1, 2, 3, 3, 6, 7};
    int ans = solution(7, 10, vec, k, gps_log);
    cout << ans << endl;
    return  0;
}