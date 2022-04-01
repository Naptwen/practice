#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//사천성 처음에는 BDF DFS로 풀려고 했지만 꺽임 횟수 확인에서 방향전환에 의한 값성정에 애를 먹음
//너무 간단하게 그냥 for문으로 품
struct node
{
    char txt = '.';
    int pos[2];
    int parent[2];
    int direction = 0;
    int u[2] = {-1,-1}; //1
    int d[2] = {-1,-1}; //2
    int l[2] = {-1,-1}; //3
    int r[2] = {-1,-1}; //4
};

bool BFS(int x, int y, int pp, int qq, vector<vector<node>>* grid, vector<node*>* stack){
    // printf("%c-----\n", (*grid)[pp][qq].txt);
    // for(int i =0; i < grid->size(); i++)
    //     {
    //     for(int j =0; j < grid->front().size(); j++)
    //     {
    //        if(x == i && y == j) printf("@   ");
    //        else if(pp == i && qq == j) printf("#   ");
    //        else printf("%d   ",(*grid)[i][j].direction);
    //     }
    //     printf("\n");
    // }
    if(x == pp && y == qq) return true;
    else{
        node* cur_node = &(*grid)[x][y];
        bool a = false, b = false, c= false, d= false;
        if(cur_node->u[0] != -1 && ((*grid)[cur_node->u[0]][cur_node->u[1]].txt == '.' 
            || (cur_node->u[0]== pp && cur_node->u[1]==qq))){
            (*grid)[cur_node->u[0]][cur_node->u[1]].parent[0] = cur_node->pos[0];
            (*grid)[cur_node->u[0]][cur_node->u[1]].parent[1] = cur_node->pos[1];
            (*grid)[cur_node->u[0]][cur_node->u[1]].direction = 1;
            (*grid)[cur_node->u[0]][cur_node->u[1]].txt = 'x';
            stack->push_back(&(*grid)[cur_node->u[0]][cur_node->u[1]]);
        }
        else if(cur_node->r[0] != -1 && ((*grid)[cur_node->r[0]][cur_node->r[1]].txt == '.'
            || (cur_node->r[0] == pp && cur_node->r[1]==qq))){
            (*grid)[cur_node->r[0]][cur_node->r[1]].parent[0] = cur_node->pos[0];
            (*grid)[cur_node->r[0]][cur_node->r[1]].parent[1] = cur_node->pos[1];
            (*grid)[cur_node->r[0]][cur_node->r[1]].direction = 2;
            (*grid)[cur_node->r[0]][cur_node->r[1]].txt = 'x';
            stack->push_back(&(*grid)[cur_node->r[0]][cur_node->r[1]]);
        } 
        else if(cur_node->d[0] != -1 && ((*grid)[cur_node->d[0]][cur_node->d[1]].txt == '.'
            || (cur_node->d[0]== pp &&cur_node->d[1]==qq))){
            (*grid)[cur_node->d[0]][cur_node->d[1]].parent[0] = cur_node->pos[0];
            (*grid)[cur_node->d[0]][cur_node->d[1]].parent[1] = cur_node->pos[1];
            (*grid)[cur_node->d[0]][cur_node->d[1]].direction = 3;
            (*grid)[cur_node->d[0]][cur_node->d[1]].txt = 'x';
            stack->push_back(&(*grid)[cur_node->d[0]][cur_node->d[1]]);
        } 
        else if(cur_node->l[0] != -1 && ((*grid)[cur_node->l[0]][cur_node->l[1]].txt == '.'
            || (cur_node->l[0] == pp && cur_node->l[1]==qq))){
            (*grid)[cur_node->l[0]][cur_node->l[1]].parent[0] = cur_node->pos[0];
            (*grid)[cur_node->l[0]][cur_node->l[1]].parent[1] = cur_node->pos[1];
            (*grid)[cur_node->l[0]][cur_node->l[1]].direction = 4;
            (*grid)[cur_node->l[0]][cur_node->l[1]].txt = 'x';
            stack->push_back(&(*grid)[cur_node->l[0]][cur_node->l[1]]);
        } 
        if(stack->size() > 0){            
            node* z = (node*)(stack->back());
            x = z->pos[0];
            y = z->pos[1];
            stack->pop_back();
            // stack->erase(stack->begin());
            return(BFS(x,y,pp,qq, grid, stack));
        }
    }
    return false;
}


string solution(int m, int n, vector<string> board)
{
    string answer = "";
    map<char, vector<pair<int,int>>> alpha;
    for(int i =0; i < m; i++)
        for(int j =0; j < n; j++)
            if(isalpha(board[i][j])) alpha[board[i][j]].push_back(make_pair(i,j)); //맵에 의한 알파벳 정렬
    int k = 0;
    while(k <alpha.size()){
        auto key = alpha.begin();
        advance(key,k);
        int start[2] = {alpha[key->first].back().first, alpha[key->first].back().second};
        int goal[2] = {alpha[key->first].front().first, alpha[key->first].front().second};
        bool find = false;

        board[start[0]][start[1]] = '.';

        //------------------------------------------
        if(find == false &&  start[1] <= goal[1]){
        for(int j = 0; j < abs(goal[1] - start[1]) + 1; j++){
            // printf("1. 오른쪽으로\n");
                int x = start[0];
                int y = start[1] + j;                   
                if(board[x][y] != '.' && board[x][y] != key->first)
                    break;             
                if(x == goal[0] && y == goal[1]){
                    find = true;
                    break;
                }else if(y == goal[1]){
                    start[1] = y;
                    break;
                }
            }
        }

        if(find == false &&  start[1] > goal[1]){
        for(int j = 0; j < abs(goal[1] - start[1]) + 1; j++){
            // printf("1. 왼쪽으로\n");
                int x = start[0];
                int y = start[1] - j;     
                if(board[x][y] != '.' && board[x][y] != key->first)
                    break;                
                if(x == goal[0] && y == goal[1]){
                    find = true;
                    break;
                }else if(y == goal[1]){
                    start[1] = y;
                    break;
                }
            }
        }

        if(find == false &&  start[0] > goal[0]){
        for(int i= 0; i< abs(goal[0] - start[0]) + 1; i++){
            // printf("1. 위로 \n");
                int x = start[0] - i;
                int y = start[1];
                if(board[x][y] != '.'&& board[x][y] != key->first)
                    break;     
                if(x == goal[0] && y == goal[1]){
                    find = true;
                    break;
                }else if(x == goal[0]){
                    start[0] = x;
                    break;
                }
            }
        }      

        if(find == false &&  start[0] <= goal[0]){
        for(int i= 0; i< abs(goal[0] - start[0]) + 1; i++){
            // printf("1. 아래로\n");
                int x = start[0] + i;
                int y = start[1];
                if(board[x][y] != '.' && board[x][y] != key->first)
                    break;
                if(x == goal[0] && y == goal[1]){
                    find = true;
                    break;
                }else if(x == goal[0]){
                    start[0] = x;
                    break;
                }

            }
        }
        //------------------------------------------
        start[0] = alpha[key->first].back().first;
        start[1] = alpha[key->first].back().second;
        if(find == false &&  start[0] > goal[0]){
        for(int i= 0; i< abs(goal[0] - start[0]) + 1; i++){
            // printf("2. 위로 \n");
                int x = start[0] - i;
                int y = start[1];
                if(board[x][y] != '.'&& board[x][y] != key->first)
                    break;     
                if(x == goal[0] && y == goal[1]){
                    find = true;
                    break;
                }else if(x == goal[0]){
                    start[0] = x;
                    break;
                }
            }
        }
        if(find == false &&  start[0] <= goal[0]){
        for(int i= 0; i< abs(goal[0] - start[0]) + 1; i++){
            // printf("2. 아래로\n");
                int x = start[0] + i;
                int y = start[1];
                if(board[x][y] != '.' && board[x][y] != key->first)
                    break;
                if(x == goal[0] && y == goal[1]){
                    find = true;
                    break;
                }else if(x == goal[0]){
                    start[0] = x;
                    break;
                }

            }
        }
        if(find == false &&  start[1] <= goal[1]){
        for(int j = 0; j < abs(goal[1] - start[1]) + 1; j++){
            // printf("2. 오른쪽으로\n");
                int x = start[0];
                int y = start[1] + j;                   
                if(board[x][y] != '.' && board[x][y] != key->first)
                    break;             
                if(x == goal[0] && y == goal[1]){
                    find = true;
                    break;
                }else if(y == goal[1]){
                    start[1] = y;
                    break;
                }
            }
        }
        if(find == false &&  start[1] > goal[1]){
        for(int j = 0; j < abs(goal[1] - start[1]) + 1; j++){
            // printf("2.왼쪽으로\n");
                int x = start[0];
                int y = start[1] - j;     
                if(board[x][y] != '.'&& board[x][y] != key->first)
                    break;                
                if(x == goal[0] && y == goal[1]){
                    find = true;
                    break;
                }else if(y == goal[1]){
                    start[1] = y;
                    break;
                }
            }
        }
        
        start[0] = alpha[key->first].back().first;
        start[1] = alpha[key->first].back().second; 
        if(find == true){
            answer += key->first;
            alpha.erase(key->first);
            board[start[0]][start[1]] = '.';
            board[goal[0]][goal[1]] = '.';
            k = 0;
        }else{
            board[start[0]][start[1]] = key->first;
            k++;
        }
    }
    if(alpha.size() > 0) return "IMPOSSIBLE";
    return answer;
}

// DBA
// C*A
// CDB
// . Z *.
// * . **
// * Z *.
// . * *.
int main()
{
    vector<string> board = {".ZI.", "M.**", "MZU.", ".IU."};
    // printf("%s\n", solution(4, 4, board).c_str());//MUZI
    // board = {"NRYN", "ARYA"};
    // printf("%s\n", solution(2, 4, board).c_str()); //RYAN
    // board = {"DBA", "C*A", "CDB"};
    // printf("%s\n", solution(3, 3, board).c_str()); //ABCD
    // board = {"AB", "BA"};
    // printf("%s\n", solution(2, 2, board).c_str()); //IMPOSSIBLE
    // board = {"M...M...DU", "....AR...R", "...E..OH.H", ".....O....", ".E..A..Q..", "Q....LL.*.", ".D.N.....U", "GT.T...F..", "....FKS...", "GN....K..S"};
    // printf("%s\n", solution(10, 10, board).c_str()); //"AEFGHKLMDOQRSTNU"
    board = {"FGHEI", "BAB..", "D.C*.", "CA..I", "DFHGE"};
    printf("%s\n", solution(5, 5, board).c_str()); //"ABCDFHGIE"
    return 0;
}