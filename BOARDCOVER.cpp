#include <iostream>
#include <vector>

using namespace std;

vector< vector<bool> > field;
int nophi;
int width;

const int bType[4][3][2] = {
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, -1} },
	{ {0, 0}, {0, 1}, {1, 0} }
};

bool isValid(int y, int x){
    if (y >= nophi || y < 0 || x >= width || x < 0){
		return false;
    }
    return true;
}

bool isFit(int y, int x, int type){
	for(int blk = 0; blk < 3; blk++){
        int newY = y + bType[type][blk][0];
        int newX = x + bType[type][blk][1];
        if (!isValid(newY, newX)){
			return false;
        }
        if (field[newY][newX]){
			return false;
        }
	}
	return true;
}

void blockSet(int y, int x, int type){
	for(int blk = 0; blk < 3; blk++){
		int newY = y + bType[type][blk][0];
		int newX = x + bType[type][blk][1];
		field[newY][newX] = !field[newY][newX];
	}
}

int prob();

int main(void){
	int C;
	cin >> C;
	for(;C--;){
        cin >> nophi >> width;
        field.clear();
        field.resize(nophi);
        for(int N = 0; N < nophi; N++){
			char data[21];
			cin >> data;
			field[N].clear();
			for(int W = 0; W < width; W++){
				if (data[W] == '#'){
					field[N].push_back(true);
				}
				else{
					field[N].push_back(false);
				}
			}
        }
        cout << prob() << endl;
	}
}

void printField(){
	for(int N = 0; N < nophi; N++){
		cout << endl;
		for(int W = 0; W < width; W++){
			cout << field[N][W];
		}
	}
	cout << endl;
}

int prob(){

    int y = -1, x = -1;
    //find upper-leftmost blank position.
    for (int yy = 0; yy < nophi; yy++){
		for  (int xx = 0; xx < width; xx++){
			if (!field[yy][xx]){
				y = yy;
				x = xx;
				goto OUT;
			}
		}
    }
    OUT:
    //base case
    if (y == -1 && x == -1){
        return 1;
    }
    int sum = 0;
    for(int T = 0; T < 4; T++){
		if (isFit(y, x, T)){
			blockSet(y, x, T);
			sum = sum + prob();
			blockSet(y, x, T);
		}
    }
    return sum;
}
