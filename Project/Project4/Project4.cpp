#include <iostream>
#include <queue>
#include <functional>

using namespace std;
priority_queue<int, vector<int>, greater<int>> heap;

int main(void) {
	int loop = 0;
	int test_count = 0;
	int temp = 0;
	int num1 = 0, num2 = 0;
	int result = 0;

	cin >> loop;

	for (int i = 0; i < loop; i++) {
		test_count = 0;
		cin >> test_count;

		
		for (int j = 0; j < test_count; j++) {
			cin >> temp;
			heap.push(temp);
		}

		
		while (true) {
			num1 = heap.top();
			heap.pop();
			if (heap.empty()) {
				break;
			}
			num2 = heap.top();
			heap.pop();
			heap.push(num1 + num2);
			result += (num1 + num2);
		}

		cout << result << endl;
		result = 0;
	}

	return 0;
}