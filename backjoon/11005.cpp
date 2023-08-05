#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N, B;
	string answer;

	cin >> N >> B;
	while (N/B!=0) {
		if (0 <= N % B && N % B <= 9)
			answer = to_string(N % B) + answer;
		else
			answer.insert(answer.begin(), 'A' + N % B - 10);

		N /= B;
	}
	if (0 <= N && N <= 9)
		answer = to_string(N) + answer;
	else
		answer.insert(answer.begin(), 'A' + N - 10);

	cout << answer << endl;
}