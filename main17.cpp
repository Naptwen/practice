#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

using namespace std;
//작업 처리 우선순위 설정
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};
 
int solution2(vector<vector<int>> jobs) {
    int answer = 0, j = 0, time = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    while (j < jobs.size() || !pq.empty()) {
        if (jobs.size() > j && time >= jobs[j][0]) {
            pq.push(jobs[j++]);
            continue;
        }
        if (!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
            time = jobs[j][0];
    }
    return answer / jobs.size();
}

struct compare{
    bool operator()(const vector<int> &a, const vector<int> &b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curtime = 0;
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), 
        [](const vector<int> &a, const vector<int> &b){ //람다식
            return (a.front() != b.front()) ? a.front() < b.front() : a.back() < b.back();}); //시간 순서 및 작업시간순으로
    priority_queue<vector<int>, vector<vector<int>>, compare> heap;
    while(!jobs.empty() || !heap.empty()){ //전체 검사를 완료했을 경우 힙에 남은 작업 요청들을 작업시간순으로 차례로 처리한다.
        if(curtime >= jobs[0][0] && !jobs.empty()){ //작업할당이 남아있으며 현재 시간이하 요청 저장 
            heap.push(jobs[0]);     //힙에 값 deep copy
            jobs.erase(jobs.begin()); //사이즈 줄이기
            continue; //작업 시간 순 이하를 모두 저장 할때 까지 다시 반복
        }
        if(!heap.empty()){ //현재 시간 이하 요청이 존재한다면
            curtime += heap.top()[1]; //처리시간
            answer += curtime - heap.top()[0]; //대기시간 + 처리시간
            heap.pop();
        }
        else
            curtime = jobs[0][0]; //작업시간이 현재시간보다 작은게 없으면 현재시간을 제일 처음 작업시간으로 바꿔준다.
    }
    return answer/n;
}

int main(){
    vector<vector<int>> test = {{0,3},{1,9},{2,6}};
    test = {{1,3}, {2,6}, {1,9}}; //9
    test = {{24, 10}, {28, 39}, {43, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 2}, {15, 34}, {35, 43}, {26, 1}};//72
    // test = {{0,3}, {4,1}};//2
    // test = {{0,5}, {1,2}, {5,5}};
    test = {{0,0}, {0,1}};
    int ans = solution(test);
    std::printf("sol %d\n", ans);
    return 0;
}