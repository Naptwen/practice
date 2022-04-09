#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
//효율성이 계속 안돼서 찾아보다가
//스택으로 풀이하는 법을 배움 https://gurumee92.tistory.com/162
struct cmp{
    bool operator()
    (const pair<string,  unsigned int> &a, const pair<string,  unsigned int> &b){   
      return ((a.first) < (b.first))?true:false;}
};

string solution(string number, int k) {
    int t = 0;
    string stack = "";
    stack += number[0];
    for(int i = 1; i < number.length(); i++){
        int  j = stack.size() -1;
        while(j >= 0  && number[i] > stack[j] &&  t  < k){
            stack.pop_back();
            j = stack.size() -1;
            t++;
        }
        stack += number[i];
    }
    while(t < k){stack.pop_back(); t++;}
    return stack;
}
int main(){
    string ans = solution("4177252841", 4);
    cout << "answer : " <<ans << endl;
    return 0;
}