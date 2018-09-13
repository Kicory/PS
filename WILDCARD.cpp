#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

char w[101];
int wLen;
char s[101];
int sLen;

vector<string> output;

bool prob(int wStart, int sStart);

int main(void){
	int C;
	cin >> C;
    for(;C--;){
		cin >> w;
		wLen = strlen(w);
		int sc;
		cin >> sc;
		for(;sc--;){
			cin >> s;
			sLen = strlen(s);
			if (prob(0, 0)){
				output.push_back(string(s));
			}
		}
		sort(output.begin(), output.end());
		for(vector<string>::iterator it = output.begin(); it != output.end(); it++){
			cout << *it << endl;
		}
		output.clear();
    }
}
bool prob(int wStart, int sStart){
	if (wStart == wLen && sStart == sLen){
		return true;
    }
	int wPos = wStart;
	int sPos = sStart;
	while(w[wPos] != '*'){
		if (w[wPos] != '?' && w[wPos] != s[sPos]){
			return false;
        }
        wPos++;
        sPos++;
        // finish together.
        if (wPos == wLen && sPos == sLen){
			return true;
        }
	}
	bool ret = false;
	for(; sPos <= sLen; sPos++){
		ret = ret || prob(wPos + 1, sPos);
	}
	return ret;
}
