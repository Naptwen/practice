#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

//level 3 추석 문제 sorting, +1 using some one use sscanf("%d-%d-%d"...)
bool compare(pair<double, double> a, pair<double, double> b){return a.second < b.second;}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<double, double> > time_line;
    string time_record;
    for(string str : lines){
        stringstream ss(str);
        string txt;
        double start_time = 0, end_time = 0;
        getline(ss,txt,' '); 
        getline(ss,txt,':');
        end_time += double(stod(txt)) * 3600;
        getline(ss,txt,':');
        end_time += double(stod(txt)) * 60;
        getline(ss,txt,' '); 
        end_time += double(stod(txt));
        getline(ss,txt);
        txt.pop_back();
        start_time = end_time - double(stod(txt));
        time_line.push_back(make_pair(start_time, end_time));
    }
    
    sort(time_line.begin(), time_line.end(), compare);

    for(int i =0; i < time_line.size(); i++){
        double j = time_line[i].second;
        int collision = 0;
        for(int k = i; k < time_line.size(); k ++)
            if(time_line[k].first < time_line[i].second + 0.999){
                collision++;  
            }
        if(collision > answer)
            answer = collision;
    }
    return answer;
}



int main(){
        string str[] = {
            "2016-09-15 20:59:57.421 0.351s",
            "2016-09-15 20:59:58.233 1.181s",
            "2016-09-15 20:59:58.299 0.8s",
            "2016-09-15 20:59:58.688 1.041s",
            "2016-09-15 20:59:59.591 1.412s",
            "2016-09-15 21:00:00.464 1.466s",
            "2016-09-15 21:00:00.741 1.581s",
            "2016-09-15 21:00:00.748 2.31s",
            "2016-09-15 21:00:00.966 0.381s",
            "2016-09-15 21:00:02.066 2.62s"};
    vector<string> test(str, str + sizeof(str)/ sizeof(string));
    int max = solution(test);
    cout << max <<endl;
    return 0;
}