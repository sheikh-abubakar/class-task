#include <iostream>
using namespace std;

int main() {
	int r;
	int c;
	cout << "enter number of rows: ";
	cin >> r;

	cout << "enter number of columns: ";
	cin >> c;
	int** matrix = new int* [r];
	for( int i = 0; i < r; i++) {
		matrix[i] = new int[c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			matrix[i][j] = i * j;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < r; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}