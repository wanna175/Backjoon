#include <iostream>
using namespace std;
int A, B;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B;
	int ret=1;
	while (A<B) {
		if ((B - 1) % 10 == 0)
			B = (B - 1) / 10;
		else if (B % 2 == 0)
			B /= 2;
		else
			break;
		++ret;
	}
	if (A != B)
		ret = -1;
	cout << ret;
	return 0;
}