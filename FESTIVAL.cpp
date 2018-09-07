#include <vector>
#include <stdio.h>

//FESTIVAL

double prob(void);

int main(void){
	int C;
	scanf("%d", &C);
	for (int i = 0; i < C; i++){
		printf("%.11f\n", prob());
	}
}

double prob(void){
	int N, teams;
	scanf("%d %d", &N, &teams);
	std::vector<int> priceAcc(N + 1, 0);
	priceAcc[0] = 0;
	for(int idx = 1; idx < N + 1; idx++){
		int curPrice;
		scanf("%d", &curPrice);
		priceAcc[idx] = priceAcc[idx - 1] + curPrice;
	}
	double minAva = 101;
	short from = 0, ends;
	for(; from <= N - teams; from++){
		for(ends = from + teams; ends <= N; ends++){
			double newAva = (priceAcc[ends] - priceAcc[from]) / (double)(ends - from);
			if (minAva > newAva){
				minAva = newAva;
			}
		}
	}
	return minAva;
}
