#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct b{
    int id;
    vector<int> child;
};

int solution(int n, vector<vector<int>> results) {
    vector<b> r(n);
    for(auto v : results){
        r[v[0] - 1].child.push_back(v[1] - 1); //이긴 경기
    }
    int i = 0;
    int answer = 0;
    int s = max_element(r.begin(), r.end()) - r.begin();

    return answer;
}

int main(){
    vector<vector<int>> test = {{4,3},{4,2},{3,2},{1,2},{2,5},{2,6},{2,7}};
    // test = {{4,3},{4,2},{3,2},{1,2},{2,5}, {2,6}, {6,5}};
    test = {{1,2},{4,5},{3,4},{2,3}};
    int num = 5;
    int ans = solution(num, test);
    printf("ans = %d\n", ans);
    return 0;
}