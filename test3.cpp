#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

constexpr double BallDiameter = 2;

int solution(vector<vector<double>> objectBallPosList, vector<double> hitVector) {
    int answer = -1;
    double a = -hitVector[1];
    double b = hitVector[0];

    vector<pair<double, int>> list;
    for(int i = 0; i < objectBallPosList.size(); i++){
        double x = objectBallPosList[i][0];
        double y = objectBallPosList[i][1];
        //점과 직선사이의 거리 a, b c= 0 x, y is point
        double k = (a * x + b * y) * (a * x + b * y)/(a * a + b * b); // 최적화를 위해서 제곱
        //점은 고려하지 않는다. 충돌 감지 두 구체사이니까 반지름 * 2= 지름 
        //음수일 경우 거리 공식의 방향성을 부여한다.
        double normal1 = 1, normal2 = 1;
        if(a != 0 || b != 0) normal1 = (a*a + b*b);
        if(x != 0 || y != 0) normal2 = (x*x + y*y);
        double n_a = a/normal1;
        double n_b = b/normal1;
        double n_x = x/normal2;
        double n_y = y/normal2;
        if((k < BallDiameter) || (n_a == n_x && n_b == n_y))
        {
            double dis = x * x + y * y;//가장 가까운 것을 구하기 위해 시작점에서 거리, 최적화를 위한 제곱
            list.push_back(make_pair(dis,i));
        }
    }
    if(!list.empty())
        answer = min_element(list.begin(), list.end(),
        [](const pair<double, int> &a, const pair<double, int> &b)
        {return (a.first != b.first)? a.first < b.first : a.second < b.second;})->second;
    return answer;
}

int main(){
    vector<vector<double>> test = {  {5.0, 5.0}, {3.0, 3.0}, {6.0, 1.0}};
    vector<double> shoot = {-1, -1};
    int ans = solution(test,shoot);
    printf("%d\n", ans);
}