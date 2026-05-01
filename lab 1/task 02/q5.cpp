#include <iostream>
using namespace std;

int **createMatrix(int r, int c) {
  int **m = new int *[r];
  for (int i = 0; i < r; i++) {
    m[i] = new int[c];
  }
  return m;
}

void inputMatrix(int **m, int r, int c) {
  cout << "Enter matrix elements:" << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> m[i][j];
    }
  }
}

void displayMatrix(int **m, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

void addMatrix(int **m1, int **m2, int **res, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      res[i][j] = m1[i][j] + m2[i][j];
    }
  }
}

void subtractMatrix(int **m1, int **m2, int **res, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      res[i][j] = m1[i][j] - m2[i][j];
    }
  }
}

void multiplyMatrix(int **m1, int **m2, int **res, int r1, int c1, int c2) {
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      res[i][j] = 0;
      for (int k = 0; k < c1; k++) {
        res[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
}

void freeMatrix(int **m, int r) {
  for (int i = 0; i < r; i++) {
    delete[] m[i];
  }
  delete[] m;
}

int main() {
  int r1, c1, r2, c2;

  cout << "Enter rows and columns for first matrix: ";
  cin >> r1 >> c1;

  int **m1 = createMatrix(r1, c1);
  cout << "Matrix 1:" << endl;
  inputMatrix(m1, r1, c1);

  cout << "\nEnter rows and columns for second matrix: ";
  cin >> r2 >> c2;

  int **m2 = createMatrix(r2, c2);
  cout << "Matrix 2:" << endl;
  inputMatrix(m2, r2, c2);

  if (r1 == r2 && c1 == c2) {
    int **res = createMatrix(r1, c1);

    addMatrix(m1, m2, res, r1, c1);
    cout << "\nAddition Result:" << endl;
    displayMatrix(res, r1, c1);

    subtractMatrix(m1, m2, res, r1, c1);
    cout << "\nSubtraction Result:" << endl;
    displayMatrix(res, r1, c1);

    freeMatrix(res, r1);
  } else {
    cout << "\nAddition and Subtraction not possible (different sizes)" << endl;
  }

  if (c1 == r2) {
    int **res = createMatrix(r1, c2);

    multiplyMatrix(m1, m2, res, r1, c1, c2);
    cout << "\nMultiplication Result:" << endl;
    displayMatrix(res, r1, c2);

    freeMatrix(res, r1);
  } else {
    cout << "\nMultiplication not possible (incompatible sizes)" << endl;
  }

  freeMatrix(m1, r1);
  freeMatrix(m2, r2);

  return 0;
}