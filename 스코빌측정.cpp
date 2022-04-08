#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//우선 순위 큐를 활용한 스코빌 측정 que 는 내림차순 이므로 꺼꾸로 비교 greater<in>사용시 큰걸로 돌려줌
struct cmp{
    bool operator() (const int &a, const int &b){
    return a > b;
    }
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, cmp> que(scoville.begin(), scoville.end());
    while(!que.empty()) 
    {
        if(!que.empty() && que.top() < K && que.size() > 1){
            int a = que.top(); que.pop();
            int b = que.top(); que.pop();
            int c = a + b + b; que.push(c);
            answer++;
        }
        else
            break;
    }
    if(que.top() < K) return -1;
    return answer;
}

int main(){
    vector<int> test = {1, 2, 3, 9, 10, 12};
    int ans = solution(test, 7);
    printf("%d\n", ans);
    return 0;
}