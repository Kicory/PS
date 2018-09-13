#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > triData;
vector< vector<int> > cache;
int triSize;

int prob(int y, int x);

int main(void){
	int C;
	cin >> C;
	for(;C--;){
		//init.
		triData.clear();
		cache.clear();
		cin >> triSize;
		triData.resize(triSize);
		cache.resize(triSize);

		for(int row = 0; row < triSize; row++){
			triData[row].resize(row + 1);
			cache[row].resize(row + 1);
			for(int col = 0; col <= row; col++){
				cin >> triData[row][col];
				cache[row][col] = -1;
			}
		}
		cout << prob(0, 0) << endl;
	}
}

int prob(int y, int x){
	if (cache[y][x] != -1){
		return cache[y][x];
	}
    if (y == (triSize - 1)){
		cache[y][x] = triData[y][x];
		return triData[y][x];
    }
	int ret = triData[y][x] + max(prob(y + 1, x), prob(y + 1, x + 1));
	cache[y][x] = ret;
	return ret;
}
