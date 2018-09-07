#include <iostream>
#include <string.h>

using namespace std;

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
int D[5][5];
bool deadEnd[10][5][5];
int target[10];
int targetLen;

bool probStart();
void init(){
	memset((void*)deadEnd, (int)false, sizeof(bool) * 10 * 5 * 5);
}

int main(void){
	int C;
	cin >> C;
	char data[5][6];
	for (;C--;){
		for(int row = 0; row < 5; row++){
			cin >> data[row];
			for(int col = 0; col < 5; col++){
				D[row][col] = (int)data[row][col];
			}
		}
		int wordNum;
		char word[11];
		cin >> wordNum;
		for(;wordNum--;){
			init();
            cin >> word;
            targetLen = strlen(word);
			for(int strIdx = 0; strIdx < targetLen; strIdx++){
				target[strIdx] = (int)word[strIdx];
			}
			cout << word << ' ' << (probStart() ? "YES" : "NO") << endl;
		}
	}
	return 0;
}

bool prob(int ynext, int xnext, int curLen){
	//Exceptional cases.
	if (ynext >= 5 || xnext >= 5 || ynext < 0 || xnext < 0){
		return false;
	}
	//DP
	if (deadEnd[curLen][ynext][xnext]){
		return false;
	}
	//base case
	if (D[ynext][xnext] != target[curLen]){
		//dead End, fail to find word.
		deadEnd[curLen][ynext][xnext] = true;
		return false;
	}
	else if (curLen + 1 == targetLen){
		//successful case, no more calculations needed.
		return true;
	}
	//Recursive
    for(int direction = 0; direction < 8; direction++){
		if (prob(ynext + dy[direction], xnext + dx[direction], curLen + 1)){
			return true;
		}
    }
    deadEnd[curLen][ynext][xnext] = true;
    return false;
}

bool probStart(){
	for(int Y = 0;Y < 5; Y++){
		for(int X = 0;X < 5; X++){
            if (prob(Y, X, 0)){
				return true;
            }
		}
	}
	return false;
}
