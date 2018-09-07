#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > field;

int main(void){
	field.resize(5);
	for (int c = 5; c--;){
		field[c].push_back(c);
	}
	vector<int>::iterator it;
	for(int o = 5; o--;){
		for(it = field[o].begin(); it != field[o].end(); it++){
			cout << *it << endl;
		}
	}
}
