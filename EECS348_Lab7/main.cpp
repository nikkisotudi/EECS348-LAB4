#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  void readFromFile(ifstream& file);
  void display() const;
  Matrix operator+(const Matrix& other) const;
  Matrix operator*(const Matrix& other) const;
  int sumOfDiagonals() const;
  void swapRows(int row1, int row2);
};

void Matrix::readFromFile(ifstream& file) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      file >> data[i][j];
    }
  }
}

void Matrix::display() const {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
}

Matrix Matrix::operator+(const Matrix& other) const {
  Matrix result;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      result.data[i][j] = data[i][j] + other.data[i][j];
    }
  }
  return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
  Matrix result;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      result.data[i][j] = 0;
      for (int k = 0; k < SIZE; k++) {
        result.data[i][j] += data[i][k] * other.data[k][j];
      }
    }
  }
  return result;
}

int Matrix::sumOfDiagonals() const {
  int sum = 0;
  for (int i = 0; i < SIZE; i++) {
    sum += data[i][i];
    sum += data[i][SIZE - 1 - i];
  }
  return sum;
}

void Matrix::swapRows(int row1, int row2) {
  for (int j = 0; j < SIZE; j++) {
    int temp = data[row1][j];
    data[row1][j] = data[row2][j];
    data[row2][j] = temp;
  }
}

int main() {
  Matrix mat1;
  Matrix mat2;

  ifstream file("matrix-data.txt");

  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }

  mat1.readFromFile(file);
  mat2.readFromFile(file);

  file.close();

  cout << "Matrix 1:" << endl;
  mat1.display();

  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}