#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//로또 번호 가능경우의수
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<bool> num_list(45, 0);
    int board[] = {6,5,4,3,2,1};
    int score = 0;
    int empty = 0;
    for(auto num : lottos) {
        (find(win_nums.begin(), win_nums.end(), num) != win_nums.end()) ? num_list[num] = 1, score++: 
                                                            ((num != 0) ? num_list[num] = 1: empty++);}
    int suggest = 0;
    for(auto check : num_list){(check == 0 && suggest < empty)? suggest++: false;}
    int min = (score > 0) ? score - 1 : 0, max = (score + suggest - 1 >= 0) ? score + suggest - 1: 0;
    answer.push_back(board[max]), answer.push_back(board[min]);
    return answer;
}

int main(){
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    vector<int> temp2;
    temp2.push_back(31);
    temp2.push_back(10);
    temp2.push_back(45);
    temp2.push_back(1);
    temp2.push_back(6);
    temp2.push_back(19);
    solution(temp , temp2);
    return 0;
}