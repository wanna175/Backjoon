#include <iostream>
#include <vector>
using namespace std;
void swap_arr(vector<int>& heap, int idx1, int idx2) {
	int tmp = heap[idx1];
	heap[idx1] = heap[idx2];
	heap[idx2] = tmp;
}
void add_heap(vector<int>& heap,int value) {
	heap.push_back(value);
	int cur = heap.size() - 1;
	while (cur!=0) {
		if (value < heap[(cur - 1) / 2]) {
			swap_arr(heap, cur, (cur - 1) / 2);
			cur = (cur - 1) / 2;
		}
		else {
			break;
		}
	}
}
int delete_heap(vector<int>& heap) {
	int ret = 0,cur=0;
	if (heap.size() == 0)
		return ret;
	ret = heap[0];
	heap[0] = heap[heap.size() - 1];
	while (true) {
		if (cur * 2 + 1 > heap.size()-1)
			break;
		else if (cur * 2 + 2 > heap.size()-1) {
			if (heap[cur] > heap[cur * 2 + 1]) {
				swap_arr(heap, cur, cur * 2 + 1);
				cur = cur * 2 + 1;
			}
			else
				break;
		}
		else {
			if (heap[cur] <= min(heap[cur * 2 + 1], heap[cur * 2 + 2]))
				break;
			if (heap[cur * 2 + 1] > heap[cur * 2 + 2]) {
				swap_arr(heap, cur * 2 + 2, cur);
				cur = cur * 2 + 2;
			}
			else{
				swap_arr(heap, cur * 2 + 1, cur);
				cur = cur * 2 + 1;
			}
		}
	}
	heap.pop_back();
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> answer;
	vector<int> heap;
	int N,tmp;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		if (tmp != 0)
			add_heap(heap, tmp);
		else
			answer.push_back(delete_heap(heap));
	}
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << '\n';

	return 0;
}