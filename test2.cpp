#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> field, int farmSize) {
    int x = 0;
    vector<int> list;
    while(x < field.size() * field[0].size()){
        int k = x%field.size();
        int t = x/field.size();
        if(k + farmSize <= field.size() && t + farmSize <= field[0].size()){
            int rock = 0;
            bool mush = false;
            for(int i = 0; i < farmSize; i++){
                for(int j = 0; j < farmSize; j++){
                    if(field[k+i][t+j] == 2){
                        mush = true;
                    }
                    else if(field[k+i][t+j] == 1){
                        rock++;
                    }
                }
            }
            if(!mush) list.push_back(rock);
        }
        x++;
    }
    int answer = (list.size() > 0)?*min_element(list.begin(), list.end()):-1;
    return answer;
}

int main(){
    vector<vector<int>> test = 
    {
    {0, 0, 1, 0},
    {1, 1, 0, 0},
    {1, 0, 2, 0},
    {0, 1, 2, 0},
    {1, 0, 1, 0},
    {0, 1, 0, 0}
    };
    int ans = solution(test, 3);
    printf("%d\n", ans);
    return 0;
}