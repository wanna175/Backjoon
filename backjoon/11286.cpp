#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> heap;
void add(int x) {
	heap.push_back(x);
	int i = heap.size() - 1;
	while (i != 1) {
		if (abs(heap[i / 2]) > abs(heap[i])
			|| (abs(heap[i/2]) == abs(heap[i]) && heap[i/2] > heap[i])) {
			swap(heap[i / 2], heap[i]);
			i /= 2;
		}
		else
			break;
	}
}
void del() {
	if (heap.size() == 1) {
		cout << 0 << '\n';
		return;
	}
	cout << heap[1] << '\n';
	heap[1] = heap[heap.size() - 1];
	heap.pop_back();
	int i = 1;
	while (true) {
		if (i * 2 > heap.size() - 1)
			break;
		if (i * 2 == heap.size() - 1) {
			if (abs(heap[i * 2]) < abs(heap[i])
				|| (abs(heap[i * 2]) == abs(heap[i])&& heap[i * 2] < heap[i])) {
				swap(heap[i * 2], heap[i]);
				i *= 2;
			}
			else break;
		}
		else {
			int j = i * 2;
			if (abs(heap[i * 2]) > abs(heap[i * 2 + 1])
				||((abs(heap[i * 2]) == abs(heap[i*2+1]) && heap[i * 2] > heap[i*2+1])))
				j += 1;
			if (abs(heap[i]) > abs(heap[j])
				|| (abs(heap[i]) == abs(heap[j]) && heap[i] > heap[j])) {
				swap(heap[i], heap[j]);
				i = j;
			}
			else break;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	heap.push_back(-1);
	int N, op;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> op;
		if (op == 0)
			del();
		else
			add(op);
	}
	return 0;
}