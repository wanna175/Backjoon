#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N, M;
	int min_set_price = 1000;
	int min_price = 1000;
	int answer = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int set_price, price;
		cin >> set_price >> price;
		if (min_set_price > set_price)
			min_set_price = set_price;
		if (min_price > price)
			min_price = price;
	}//입력 다 받음,최소값 찾음..

	if (6 * min_price < min_set_price)
		answer = N * min_price;
	else {
		int set = N / 6;
		int num = N % 6;

		answer = set * min_set_price;
		if (num * min_price < min_set_price)
			answer += num * min_price;
		else
			answer += min_set_price;
	}
	cout << answer;

	return 0;
}