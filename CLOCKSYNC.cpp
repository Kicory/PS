#include <iostream>
#include <algorithm>

using namespace std;

int arr[16][10] = { 0, };
int stat[16];
void init();

bool check12(){
	for(int idx = 0; idx < 16; idx++){
		if (stat[idx] % 4 != 0){
			return false;
		}
	}
	return true;
}

int prob(int switchIdx, int pushCount);

int main(void){
	int C;
	cin >> C;
	init();
	for(;C--;){
		for(int idx = 0; idx < 16; idx++){
			int time;
			cin >> time;
			stat[idx] = time / 3;
		}
		int value = prob(0, 0);
		cout << ((value == 999999) ? -1 : value) << endl;
	}
}

int prob(int switchIdx, int pushCount){
	if (check12()){
		return pushCount;
	}
	else if (switchIdx == 10){
		//fail.
		return 999999;
	}
	int minRet = 999999;
	for(int push = 0; push < 4; push++){
		minRet = min(minRet, prob(switchIdx + 1, pushCount + push));
		for(int clockIdx = 0; clockIdx < 16; clockIdx++){
			if (arr[clockIdx][switchIdx] == 1){
				stat[clockIdx]++;
			}
		}
	}
	return minRet;
}

void init() {
	arr[0][0] = 1;
	arr[0][3] = 1;
	arr[0][5] = 1;

	arr[1][0] = 1;
	arr[1][8] = 1;

	arr[2][0] = 1;
	arr[2][5] = 1;
	arr[2][8] = 1;

	arr[3][1] = 1;
	arr[3][6] = 1;
	arr[3][8] = 1;
	arr[3][9] = 1;

	arr[4][2] = 1;
	arr[4][3] = 1;
	arr[4][7] = 1;
	arr[4][8] = 1;
	arr[4][9] = 1;

	arr[5][3] = 1;
	arr[5][7] = 1;
	arr[5][8] = 1;
	arr[5][9] = 1;

	arr[6][3] = 1;
	arr[6][4] = 1;

	arr[7][1] = 1;
	arr[7][3] = 1;
	arr[7][4] = 1;
	arr[7][7] = 1;

	arr[8][4] = 1;

	arr[9][1] = 1;
	arr[9][9] = 1;

	arr[10][2] = 1;
	arr[10][4] = 1;

	arr[11][1] = 1;

	arr[12][4] = 1;

	arr[13][9] = 1;

	arr[14][2] = 1;
	arr[14][5] = 1;
	arr[14][6] = 1;
	arr[14][7] = 1;

	arr[15][2] = 1;
	arr[15][5] = 1;
	arr[15][6] = 1;
	arr[15][7] = 1;
}
