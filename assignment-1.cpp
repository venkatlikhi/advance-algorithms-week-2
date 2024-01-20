#include <iostream>
using namespace std;

int main() {
    int rows, cols, nonZero = 0;
    cout << "Input the matrix dimensions: ";
    cin >> rows >> cols;

    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] != 0) {
                nonZero++;
            }
        }
    }

    int** sparseMatrix = new int*[3];
    for(int i = 0; i < 3; i++) {
        sparseMatrix[i] = new int[nonZero];
    }

    int index = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparseMatrix[0][index] = i;
                sparseMatrix[1][index] = j;
                sparseMatrix[2][index] = matrix[i][j];
                index++;
            }
        }
    }

    cout << "Resulting Sparse Matrix: " << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < nonZero; j++) {
            cout << sparseMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for(int i = 0; i < 3; i++) {
        delete[] sparseMatrix[i];
    }
    delete[] sparseMatrix;

    return 0;
}
