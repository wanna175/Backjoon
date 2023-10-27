#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
struct Node {
	char left;
	char right;
};
void preorder_traversal(int cur,string& str,const vector<Node>& nodes) {
	str.push_back(cur + 'A');
	if (nodes[cur].left != '.')
		preorder_traversal(nodes[cur].left - 'A', str, nodes);
	if (nodes[cur].right != '.')
		preorder_traversal(nodes[cur].right - 'A', str, nodes);
}
void inorder_traversal(int cur, string& str, const vector<Node>& nodes) {
	if (nodes[cur].left != '.')
		inorder_traversal(nodes[cur].left - 'A', str, nodes);
	str.push_back(cur + 'A');
	if (nodes[cur].right != '.')
		inorder_traversal(nodes[cur].right - 'A', str, nodes);
}
void postorder_traversal(int cur, string& str, const vector<Node>& nodes) {
	if (nodes[cur].left != '.')
		postorder_traversal(nodes[cur].left - 'A', str, nodes);
	if (nodes[cur].right != '.')
		postorder_traversal(nodes[cur].right - 'A', str, nodes);
	str.push_back(cur + 'A');
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<Node> nodes(N);
	for (int i = 1; i <= N; ++i) {
		char parent, right, left;
		cin >> parent >> left >> right;
		nodes[parent - 'A'].left = left;
		nodes[parent - 'A'].right = right;
	}
	string pre, in, post;
	preorder_traversal(0, pre, nodes);
	inorder_traversal(0, in, nodes);
	postorder_traversal(0, post, nodes);
	cout << pre << '\n';
	cout << in << '\n';
	cout << post << '\n';
	return 0;
}