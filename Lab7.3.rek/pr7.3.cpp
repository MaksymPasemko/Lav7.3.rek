#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int sumOfRowsWithoutNegatives(int matrix[MAX_SIZE][MAX_SIZE], int n, int row, int col) {
    if (row == n) {
        return 0;
    }

    int sum = 0;
    bool hasNegative = false;

    for (int j = col; j < n; j++) {
        if (matrix[row][j] < 0) {
            hasNegative = true;
            break;
        }
    }

    if (!hasNegative) {
        for (int j = col; j < n; j++) {
            sum += matrix[row][j];
        }
    }

    return sum + sumOfRowsWithoutNegatives(matrix, n, row + 1, col);
}

int findMinOfParallelDiagonalSums(int matrix[MAX_SIZE][MAX_SIZE], int n, int i, int j, int minSum) {
    if (i == n) {
        return minSum;
    }

    int sum = 0;
    for (int k = j; k < n - i; k++) {
        sum += matrix[i + k][k];
    }

    if (i == 0 || sum < minSum) {
        minSum = sum;
    }

    return findMinOfParallelDiagonalSums(matrix, n, i + 1, j, minSum);
}

int main() {
    int n;
    cout << "Enter the size of the square matrix (n): ";
    cin >> n;

    int matrix[MAX_SIZE][MAX_SIZE];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matrix[i][j];
        }
    }

    cout << "Your matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int sum = sumOfRowsWithoutNegatives(matrix, n, 0, 0);
    cout << "Sum of rows without negatives: " << sum << endl;

    int minDiagonalSum = findMinOfParallelDiagonalSums(matrix, n, 1, 0, matrix[0][0]);
    cout << "Minimum sum of parallel diagonal elements: " << minDiagonalSum << endl;

    return 0;
}
