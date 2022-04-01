#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//2분 알고리즘
//다름사람의 비트연산자 활용 >>1 <<1 2로 나누거나 2 로 곱한다.

long solution2(int n, vector<int> times) {
    int tSize=times.size();
    long answer = 0, s=0, e=1e9*n, mid, doneN; //e= Max takeTime * peopleNum

    while(s<e) { // 오픈 인터발
        mid=(s+e)>>1; //비트연산자를 활용한 2나누기
        doneN=0;
        for(int i=0; i<tSize; i++) doneN += mid/times[i]; //여기까지는 같고
        if(doneN>=n) e=mid; //
        else s=mid+1; //최소값을 찾는 문제이므로 처리인원 부족시 인원 중간값 버림에서 연산자 +1
    }

    return answer=s;
}
long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;   
    sort(times.begin(), times.end());
    vector<unsigned long long> time(times.begin(), times.end());
    unsigned long long max = times.back() * n; //최대 걸리는 시간
    unsigned long long min = 1; //추정 최소치
    answer = max;
    while(min <= max){ //추정최소치가 최대걸리는 시간과 같거나 범위를 초과할시
        unsigned long long mid  = (max + min)>>1; //중간값 - 추정되는 시간에 인원을 처리 할 수 있는지 확인하기 위한 요소 
        unsigned long long total = 0;
        for(unsigned long long vec : time) 
            total += mid / vec; //주어진 중간값에 처리 할 수 있는 인원수들의 합을 구한다
        if(total >= n) answer = (answer > mid)?mid:answer, max = mid - 1; //처리인원수가 주어진 인원수보다 많을 경우, 최대걸리는 시간을 중간값으로 수정 홀수 처리를 위하여 -1을 해줌
        else min = mid + 1; //처리인원수가 주어진 인원수보다 적을경우, 추정최소치를 중간값으로 수정,홀수 처리를 위하여 +1을 더해줌
        
    }
    return answer;
}

int main(){
    int a[] = {7,10};
    vector<int> test(a, a + sizeof(a)/sizeof(int));
    long long ans = solution(6, test);
    printf("%llu\n", ans);
    return 0;
}
