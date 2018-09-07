#include <iostream>

using namespace std;

string data;

string prob(string data);

int main(void){
	int C;
	cin >> C;
	for(;C--;){
		cin >> data;
		cout << prob(data) << endl;
	}
	return 0;
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
