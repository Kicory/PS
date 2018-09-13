#include <iostream>

using namespace std;

string data;

string prob(string data);
string prob_lin(string data, int& pos);

int main(void){
	int C;
	cin >> C;
	for(;C--;){
		cin >> data;
		//pos is -1, like 'head' in linkedlist.
		int pos = -1;
		cout << prob_lin(data, pos) << endl;
	}
	return 0;
}

string prob_lin(string data, int& pos){
    pos++;
    if (data[pos] != 'x'){
		return data.substr(pos, 1);
    }
	string Q[4];
	Q[0] = prob_lin(data, pos);
	Q[1] = prob_lin(data, pos);
	Q[2] = prob_lin(data, pos);
	Q[3] = prob_lin(data, pos);
	return "x" + Q[2] + Q[3] + Q[0] + Q[1];
}

string prob(string data){
	if (data.length() == 1){
		return data;
	}
    string quads[4];
    int offset = 1;
	for (int quadIdx = 0; quadIdx < 4; quadIdx++){
		int quadLen = 1;
		int counter = 1;
		for(int pos = offset; pos < data.length(); pos++){
			if (data[pos] == 'x'){
                counter += 4;
                quadLen += 4;
			}
			counter--;
			if (counter == 0){
				break;
			}
		}
		quads[quadIdx] = data.substr(offset, quadLen);
		offset += quadLen;
	}

	return "x" + prob(quads[2]) + prob(quads[3]) + prob(quads[0]) + prob(quads[1]);
}
