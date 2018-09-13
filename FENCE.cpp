#include <iostream>
#include <algorithm>

using namespace std;

int N;
int hs[20000] = {0, };

int prob(int from, int to);

int main(void){
	int C;
	cin >> C;
	for(;C--;){
		cin >> N;
		for(int idx = 0; idx < N; idx++){
			cin >> hs[idx];
		}
		cout << prob(0, N) << endl;
	}
	return 0;
}


int prob(int from, int to){
	//base cases
    if (from + 1 == to){
        return hs[from];
    }
    if (from + 2 == to){
		return max(max(hs[from], hs[to - 1]), 2 * min(hs[from], hs[to - 1]));
    }
	int mid = (to + from) / 2;
	int prevA = prob(from, mid);
	int nextA = prob(mid, to);

	//Start setting.
	int midFrom = mid - 1;
	int midTo = mid + 1;
	int curNophi = min(hs[midFrom], hs[midTo - 1]);
	int midA = curNophi * 2;
	int addedIdx;
	while(midFrom > from || midTo < to){
		if (midFrom == from){
            midTo++;
            addedIdx = midTo - 1;
		}
		else if (midTo == to){
            midFrom--;
            addedIdx = midFrom;
		}
		else if (hs[midFrom - 1] > hs[midTo]){
            midFrom--;
            addedIdx = midFrom;
		}
		else {
            midTo++;
            addedIdx = midTo - 1;
		}
		curNophi = min(curNophi, hs[addedIdx]);
		midA = max(midA, curNophi * (midTo - midFrom));
	}
	return max(prevA, max(nextA, midA));
}
