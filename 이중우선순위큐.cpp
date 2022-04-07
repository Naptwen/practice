#include <string>
#include <vector>
#include <queue>
#include <sstream>

#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int, vector<int>, less<int>> max_que;
    priority_queue<int, vector<int>, greater<int>> min_que;
    int num = 0;
    for(auto str : operations){
        stringstream ss(str);
        string order;
        string detail;
        getline(ss, order, ' ');
        getline(ss, detail);
        if(order.compare("I") == 0) max_que.push(stoi(detail)), min_que.push(stoi(detail)), ++num;
        else if(order.compare("D") == 0 && detail.compare("1") == 0 && num) max_que.pop(), --num;
        else if(order.compare("D") == 0 && detail.compare("-1") == 0 && num) min_que.pop(), --num;
        if(!num){while(!max_que.empty()){max_que.pop();} while(!min_que.empty()){min_que.pop();}}
    }
    vector<int> answer;
    if(max_que.size() <= 0 || min_que.size() <= 0) return {0,0};
    answer.push_back(max_que.top());
    answer.push_back(min_que.top());
    return answer;
}

int main(){
    vector<string> test = {"I 16","D 1"};
    vector<int> ans = solution(test);
    printf("%d %d\n", ans[0], ans[1]);
    return 0;
}