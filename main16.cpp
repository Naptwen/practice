#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//BFS 가장먼 노드
bool cmp (const pair<int, pair<int, vector<int>>> &a, const pair<int, pair<int, vector<int>>> &b){
    return a.second.first < b.second.first;
}

int solution(int n, vector<vector<int>> edge) {
    map<int, pair<int, vector<int>>> tree;
    for(int i=0;i < edge.size(); i++){
        tree[edge[i][0]].second.push_back(edge[i][1]);
        tree[edge[i][0]].first = 0;
        tree[edge[i][1]].second.push_back(edge[i][0]);
        tree[edge[i][1]].first = 0;
    }
    vector<int> que;
    que.push_back(1);
    tree[1].first = 1;
    while(!que.empty()){
        int first = que.front();
        que.erase(que.begin());
        for(int i=0; i < tree[first].second.size(); i++){
            int ng = tree[first].second[i];
            if(tree[ng].first == 0){ //dis
                tree[ng].first += tree[first].first + 1;
                que.push_back(ng);
            }
        }
    }
    int answer = 0;
    int max = max_element(tree.begin(), tree.end(), cmp)->second.first;
    for(auto branch : tree){
        (branch.second.first == max)? answer+=1: false;
    }
    return answer;
}

int main(){
    vector<vector<int>> test = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    int ans = solution(6, test);
    printf("%d\n", ans);
    return 0;
}