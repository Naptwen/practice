#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

//문자열 압축
int solution(string s) {
    int answer = 0;
	vector<int> possible;
	for(int i =1; i<= s.size(); i++){
		string text;
		string slice = s;
		string sub1 = slice.substr(0,i);
		int total = 1;
		while(slice.size() && i <= slice.size()){
			slice = slice.substr(i, slice.size());
			string sub2 = slice.substr(0,i);
			if(sub1.compare(sub2)==0)total++;
			else{
				if(total > 1) text += to_string(total);
				text += sub1;
				sub1 = slice.substr(0,i);
				total = 1;
			}
		}
		text += slice;
		possible.push_back(text.size());
	}
	sort(possible.begin(), possible.end());
	answer = possible[0];
    return answer;
}

int main(){
	solution("aabbaccc");
	return 0;
}