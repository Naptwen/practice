#include "stdlib.h"
#include  "stdio.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <iostream>
using namespace std;

//아이디 신고와 신고자에게 이메일 발송하기
vector<string> split(string str, char deli);
vector<int> solution(vector<string> id_list, vector<string> report, int k);

vector<string> split(string str, char deli){
    //split string
    vector<string> txt;
    stringstream ss(str); 
    string temp;
    while(getline(ss,temp, deli)){
        txt.push_back(temp);
    }
    return txt;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, vector<int> > criminal_reporter;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    for(string record : report){
        vector<string> txt = split(record, ' ');
        for(int j =0; j <id_list.size(); j++){
            if(txt[1].compare(id_list[j]) == 0){
                for(int t = 0; t <id_list.size(); t++){
                    if(txt[0].compare(id_list[t]) == 0){
                        criminal_reporter[txt[1]].push_back(t);
                        break;
                    }
                }
            break;
            }
        }       
    }
    map<string, vector<int> >::iterator it;
    for(string id : id_list){
        if(criminal_reporter[id].size() >= k){
             for(int t = 0; t < criminal_reporter[id].size(); t++){
                answer[criminal_reporter[id][t]] += 1;
            }
        }
    }
    return answer;
}

int main(){
    vector<string> id_list;
    vector<string> report;
    string test1[] = { "muzi", "frodo", "apeach", "neo"};
    string test2[] = {  "muzi frodo",
                        "apeach frodo",
                        "frodo neo",
                        "muzi neo",
                        "apeach muzi", 
                        "ryan con", 
                        "ryan con", 
                        "ryan con", 
                        "ryan con"};
    for(int i =0; i <4; i++){
        id_list.push_back(test1[i]);
    }
    for(int i =0; i <9; i++){
        report.push_back(test2[i]);
    }
    vector<int> test = solution(id_list, report, 2);
    for(int i =0; i < test.size(); i++){
        printf("%d = %d\n", i, test[i]);
    }
    return 0;
}