#include <string>
#include <vector>
#include <iostream>

using namespace std;
//인형뽀기
int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
    vector<int> stack;
    for(int vec : moves){
        for(int i =0; i< board.size(); i++){
            cout << " pick " << vec << " : "<< board[i][vec-1];
            if(board[i][vec-1] > 0){
                cout << " grab " << board[i][vec-1] <<endl;
                stack.push_back(board[i][vec-1] );
                board[i][vec-1]  = 0;
                break;
            }   
        }
        cout << endl;
    }
    int i = 1;
    for(auto vec : stack) cout <<vec <<endl;
    while(i < stack.size()){
        if(stack[i] == stack[i-1]){
            answer++;
            stack.erase(stack.begin() + i - 1, stack.begin() + i + 1); //end 미만이라서 +1
            i = 0;
        }
        for(auto vec : stack) cout <<vec;
        cout << endl;
        i++;

    }
    return answer;
}


int main(){
    int val[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
    int mov[8] = {1, 5, 3, 5, 1, 2, 1, 4};
    vector<vector<int> > test(5,vector<int>(5,0));
    vector<int> move(mov, mov+sizeof(mov)/sizeof(int));
    for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
        test[i][j] = val[i][j];
    int asw = solution(test, move);
    cout << asw <<endl;
}