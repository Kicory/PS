#include <iostream>

using namespace std;

int elemCnt;
bool friendData[10][10];

int prob(bool[10]);

void init(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			friendData[i][j] = false;
		}
	}
}

int main(void){
    int C;
    cin >> C;
    for(;C--;){
		int pcnt;
        cin >> elemCnt >> pcnt;
		init();
		for(;pcnt--;){
			int f, s;
            cin >> f >> s;
			if (f > s){
				int tmp = f;
				f = s;
				s = tmp;
			}
			friendData[f][s] = true;
			//friendData[s][f] = true;
		}
		bool taken[10] = {false, };
        cout << prob(taken) << endl;
    }
    return 0;
}

int prob(bool taken[10]){
    //base case
    int firstFree = -1;
    for(int idx = 0; idx < elemCnt; idx++){
		if (!taken[idx]){
            firstFree = idx;
            break;
		}
    }
    if (firstFree == -1){
		//A single case found.
        return 1;
    }
    //recursive
    int sum = 0;
    for(int with = firstFree + 1; with < elemCnt; with++){
		if (friendData[firstFree][with] && !taken[with]){
			//Can be friend.
			taken[firstFree] = true;
			taken[with] = true;
			sum = sum + prob(taken);
			taken[firstFree] = false;
			taken[with] = false;
		}
    }
    return sum;
}
