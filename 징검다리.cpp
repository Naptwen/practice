#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//이분 탐색 결정문
//왼쪽 오른쪽 선택 문제 이해 하기
//조건 찾기
template<typename t>
bool check(vector<t> list, t condition, int n){
    int num = 0;
    unsigned long long dis = condition;
    unsigned long long prev = list[0];
    for(int i = 1; i < list.size(); i++)
        ((list[i] - prev) < condition) ? num++: prev = list[i]; 
        //돌사이의 거리가 조건미만 만족하면 제거++, 만족하지않으면 전의돌을 현재돌로 바꿔준다 (주어진 돌보다 거리가 길어졌으므로 새로 거리조절을 한다)
        //미만으로 둚으로써 중간값이 최대값이 된다.
    return (num <= n)?true:false;  //주어진 갯수이하로 제거시 늘림, 주어진 갯수 이상으로 제거시 줄임
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    vector<unsigned long long> rock(rocks.begin(), rocks.end()); //타입 변환
    sort(rock.begin(), rock.end()); //돌 사이의 거리를 제기위해서 오름차순 정렬을 해준다 예) 254 일경우 잘못된 돌사이거리값이 나오므로
    rock.insert(rock.begin(),0); //출발 지점
    rock.push_back(distance); //도착 지점
    unsigned long long r = distance; //출발 점과 도착점 사이에 돌이 놓여있으므로 가장 긴 거리는 출발점에서 도착점 까지의 길이이다.
    unsigned long long l = 1; //최소거리는 1 이므로
    while(l + 1 < r){ //r==l 과 같은 경계값 에러를 방지하기위하여
        unsigned long long m = (l + r)>>1; //오버플로우 방지
        if(check(rock, m, n)) l = m; //check문에서 <= 로 둚으로써 내가 구할mid값을 포함하게된다.
        else r = m;                       
    }
    return answer = l;//내가 구할 값이 mid값보다 낮으므로 l
}
//23, [3, 6, 9, 10, 14, 17], 2 out put 3
//16, [4, 8, 11], 2 out pu 8
int main(){
    int test[] = {3, 6, 9, 10, 14, 17}; //out put 3
    vector<int> rocks(test, test + sizeof(test)/ sizeof(int));
    int answ = solution(23, rocks, 2);
    printf("%d\n", answ);
    int test2[] = {2, 14, 11, 21, 17}; //out put 4
    vector<int> rocks2(test2, test2 + sizeof(test2)/ sizeof(int));
    answ = solution(25, rocks2, 2);
    printf("%d\n", answ);
    int test3[] = {4, 8, 11}; //out put 8
    vector<int> rocks3(test3, test3 + sizeof(test3)/ sizeof(int));
    answ = solution(16, rocks3, 2);
    printf("%d\n", answ);
    return 0;
}