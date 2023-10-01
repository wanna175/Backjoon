#include <iostream>
int main(void) {
	int X,cnt=1;
	std::cin >> X;
	while (X!=1) {
		if (X % 2 == 1) ++cnt;
		X /= 2;
	}
	std::cout << cnt;
	return 0;
}