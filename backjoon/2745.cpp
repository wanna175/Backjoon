#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	string N;
	int B;
	int sum = 0;
	cin >> N >> B;
	for (int i = 0; i < N.size(); i++) {
		int temp = N[N.size() - 1 - i];
		if ('0' > temp || temp > '9')
			temp += 10 - 'A';
		else
			temp -= '0';
		sum += temp * pow(B, i);
	}
	cout << sum;
}