#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
//디피 풀이 연속 계산 조합 추론 동적계획법
//다른 사람 풀이 순환 함수로 함수를 함수로 실행 <- 좋은 아이디어
int solution(int N, int number) {
    int answer = 0;
    const int MAX = 8;
    //경우의 수 공식
    //N = 1 5                                          ---- 1
    //N = 2 5+5, 5-5, 5*5, 5/5, 55                      --- 4 + 1 숫자 붙였을 때 포함
    //N = 3 5 + 5 + 5, 5 - 5 - 5, 5 * 5 * 5, 5 / 5 / 5 ---- 4H2 = 16 + 1 숫자 붙였을때 포함
    //      ...... 555
    //N = 4 ...                                        ----- 4H3 = 4^3 + 1
    //이를 통해 각 단계별 공식은 그전단계 조합 완성됨을 알 수 있다.
    map<int, vector<int> > stack;
    if(N == number) return 1; //1번 케이스에 바로 나올 수 있는 경우를 고려해야한다.
    stack[1].push_back(N);
    for(int i=2; i <= MAX; i++){ //8까지
        for(int j = i - 1; j >= 1; j--)                     //A+1조합만 생각했는데 1+A, A/2 +A/2등 순서에 따라 값이 달라짐을 고려해야한다.
        for(int k = 0; k < stack[j].size(); k++)            //[j]리스트의 원소
            for(int t = 0; t < stack[i - j].size(); t++){   //[i-j]리스트의 원소 예) i= 2 [1,1], i=3 [1,2],[2,1] i =4 [1,3][2,2][3,1] ....
                int m = stack[j][k];                        //[j]번호 안에 원소
                int n = stack[i - j][t];                    //[i-j]번호 안에 원소 
                if(m + n != 0) stack[i].push_back(m + n); 
                if(m - n != 0) stack[i].push_back(m - n);
                if(n != 0) stack[i].push_back(m * n);
                if(n != 0) stack[i].push_back(m / n);
            }
        stack[i].push_back(stack[i-1].back()*10 + N);   //이부분만 마지막에 따로 넣어줘지 조합계산시 붙은 번호로 계산된다.
        if(find(stack[i].begin(), stack[i].end(), number) != stack[i].end()) return i; //8번 케이스도 검사하기위해 마지막에 검사한다.
    }
    return -1;
}

int main(){
    int ans = solution(1, 1121);
    printf("%d\n",ans);;
    return 0;
}