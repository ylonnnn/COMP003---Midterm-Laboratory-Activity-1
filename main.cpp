#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

bool isPrime(int n) {
  if (n <= 1)
    return false;

  if (n <= 3)
    return true;

  if (!(n % 2) || !(n % 3))
    return false;

  // 6k +- 1 approach
  for (int i = 6; i < ((int)(sqrt(n)) + 1); i += 6)
    if (!(n % (i - 1)) || !(n % (i + 1)))
      return false;

  return true;
}

int main() {
  cout << "WELCOME!\n\n";

  int rowSize, colSize;

  // Read matrix size
  while (rowSize != colSize) {
    cout << "Enter the row size of an array: ";
    cin >> rowSize;

    if (rowSize < 1 || cin.fail()) {
      cout << "Please enter a valid row size!\n";
      continue;
    }

    cout << "Enter the column size of an array: ";
    cin >> colSize;

    cout << "\n";

    if (colSize < 1 || cin.fail()) {
      cout << "Please enter a valid column size!\n";
      continue;
    }

    // Square matrix check
    if (rowSize == colSize)
      break;
    else
      cout << "Oops! The size of the row and column must be equal!\n";
  }

  // Initialize the 2-Dimensional array or the matrix
  // NOTE: Only do this if the editor and compiler allows you to
  int matrix[rowSize][colSize];
  // Otherwise, use
  //   int **matrix = new int *[rowSize];
  //   for (int i = 0; i < rowSize; i++)
  //     matrix[i] = new int[colSize];
  // Or
  //   int **matrix = (int **)malloc(sizeof(int *) * rowSize);
  //   for (int i = 0; i < rowSize; i++)
  //     matrix[i] = (int *)malloc(sizeof(int) * colSize);
  // Or potentially a dynamic array or vector

  int diagonalSum = 0, antiDiagonalSum = 0, primeSum = 0, primeN = 0;

  // Read matrix cell values
  for (int i = 0; i < rowSize; i++) {

    cout << "Data entry for row " << i + 1 << "\n";

    for (int j = 0; j < colSize; j++) {
      int n;
      cout << "Enter a number for [" << i << "][" << j << "]: ";
      cin >> n;

      matrix[i][j] = n;

      if (isPrime(n)) {
        primeSum += n;
        primeN++;
      }
    }

    // Cells at every [i][i] will be part of the diagonal orientation. Hence,
    // add it to the sum
    diagonalSum += matrix[i][i];

    // Cells at [i][rowSize - i + 1] (row and column are opposite) will be part
    // of the anti-diagonal orientation. Hence, add it to the sum
    antiDiagonalSum += matrix[i][rowSize - (i + 1)];

    cout << "\n";
  }

  cout << "\n";

  // Display the array content
  cout << "Array Content\n";

  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < colSize; j++) {
      cout << matrix[i][j] << "\t";
    }

    cout << "\n";
  }

  cout << "\n";

  // Display the sum of the diagonal and anti-diagonal cells
  cout << "The sum of diagonal is: " << diagonalSum << "\n";
  cout << "The sum of anti-diagonal is: " << antiDiagonalSum << "\n";

  // Display the average of the prime numbers
  if (primeN)
    cout << "The average of prime numbers: " << (float)(primeSum) / primeN
         << "\n\n";
  else
    cout << "No prime numbers found within the matrix!";

  // Display the transposed matrix
  cout << "Transpose Matrix\n";

  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < colSize; j++) {
      cout << matrix[j][i] << "\t";
    }

    cout << "\n";
  }

  return 0;
}