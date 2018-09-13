#include <iostream>
#include <vector>

using namespace std;

vector<int> L;
vector<int> cache;
int len;

int prob(int start);

int main(void){
	int C;
	cin >> C;
	for(;C--;){
		cin >> len;
		L.clear();
		cache.clear();
		L.resize(len);
		cache.resize(len);

		for(int idx = 0; idx < len; idx++){
			cin >> L[idx];
			cache[idx] = -1;
		}
		int output = -1;
		for(int idx = 0; idx < len; idx++){
			output = max(output, prob(idx));
		}
		cout << output << endl;
	}
}

//N^2 algorithm...
int prob(int start){
	if (start == len - 1){
        return 1;
	}

	int& ret = cache[start];
	if (ret != -1){
		return ret;
	}

	int cur = L[start];
	ret = 1;
	for(int idx = start + 1; idx < len; idx++){
		if (cur < L[idx]){
			ret = max(ret, 1 + prob(idx));
		}
	}
	return ret;
}
