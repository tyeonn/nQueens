#include<iostream>
#include <cmath>
using namespace std;

bool backtrack(int &col) {
	col--;
	if (col == -1) return false;
	return true;
}
bool isOk(int x[], int col) {
	for (int i = 0; i < col; i++) {
		if (x[i] == x[col] || (col = i) == abs(x[col] - x[i])) {
			return false;
		}
	}
	return true;
}
int qSoln(int x) {
	int *q = new int[x];
	q[0] = 0;
	int counter = 0, col = 0;
	while (true) {
		col++;
		q[col] = -1;
		q[col]++;
		if (col == x) {
			counter++;
			if (backtrack(col)) {
				q[col]++;
			}
			else {
				return counter;
				delete[]q;
			}
		}
		while (q[col] == x) {
			if (backtrack(col)) {
				q[col]++;
			}
			else {
				return counter;
				delete[]q;
			}
		}
		while (!isOk(q, col)) {
			q[col]++;
			while (q[col] == x) {
				if (backtrack(col)) {
					q[col]++;
				}
				else {
					return counter;
					delete[]q;
				}
			}
		}
	}

}

int main()
{
	int soln;
	cout << "How many board solutions do you want to see: ";
	cin >> soln;
	for (int i = 1; i <= soln; i++) {
		cout << "There are " << qSoln(i) << " solutions in the " << i << "*" << i << " board." << endl;
	}
	return 0;
}

