#include <iostream>
#include <vector>

using namespace std;

vector<int> A;
vector<int> B;
vector< vector<int> > cache;
int Alen;
int Blen;

int prob(int Astart, int Bstart);

int main(void){
	int C;
	cin >> C;
	for(;C--;){
        cin >> Alen >> Blen;
        A.clear();
        B.clear();
        A.resize(Alen);
        B.resize(Blen);
        cache.clear();
        cache.resize(Alen + 1);
        for(int idx = 0; idx < Alen; idx++){
			cin >> A[idx];
			cache[idx].clear();
			cache[idx].resize(Blen + 1, -1);
        }
        cache[Alen].resize(Blen + 1, -1);
        for(int idx = 0; idx < Blen; idx++){
			cin >> B[idx];
        }

		int output = -1;
        for(int Adx = 0; Adx <= Alen; Adx++){
			for(int Bdx = 0; Bdx <= Blen; Bdx++){
				output = max(output, prob(Adx, Bdx));
			}
        }
        cout << output << endl;
	}
}

int prob(int Astart, int Bstart){

    if (Astart == Alen && Bstart == Blen){
		return 0;
	}


    int& ret = cache[Astart][Bstart];
    if (ret != -1){
		return ret;
    }

    ret = 1;

	int newBdx = Bstart;
	for(; newBdx < Blen; newBdx++){
		if (B[newBdx] > A[Astart]){
			break;
		}
	}
	int newAdx = Astart;
	for(; newAdx < Alen; newAdx++){
		if (A[newAdx] > B[Bstart]){
			break;
		}
	}
    for(int Adx = Astart + 1; Adx <= Alen; Adx++){
        if (Adx == Alen || A[Adx] > A[Astart]){

			ret = max(ret, 1 + prob(Adx, newBdx));
        }
    }
    for(int Bdx = Bstart + 1; Bdx <= Blen; Bdx++){
		if (Bdx == Blen || B[Bdx] > B[Bstart]){

			ret = max(ret, 1 + prob(newAdx, Bdx));
        }
    }
    return ret;
}
