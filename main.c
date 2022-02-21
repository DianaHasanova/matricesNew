#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include <stdio.h>

/*
void test_swapRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            }, 5, 3
    );
    swapRows(m, 0, 2);
    matrix newM = createMatrixFromArray(
            (int[]) {
                    0, 0, 1,
                    0, 0, 0,
                    1, 1, 0,
                    0, 0, 0,
                    0, 1, 1,
            }, 5, 3
    );
    assert(areTwoMatricesEqual(m, newM));

    freeMemMatrix(m);
    freeMemMatrix(newM);
}

void test_swapColumns() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0, 0,
                    0, 1, 0, 0,
                    0, 1, 1, 1,
            }, 3, 4
    );
    swapColumns(m, 1, 3);
    matrix newM = createMatrixFromArray(
            (int[]) {
                    1, 0, 0, 1,
                    0, 0, 0, 1,
                    0, 1, 1, 1,
            }, 3, 4
    );

    assert(areTwoMatricesEqual(m, newM));

    freeMemMatrix(m);
    freeMemMatrix(newM);
}

void test_isSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {0}, 3, 3);
    assert(isSquareMatrix(m) == 1);
    freeMemMatrix(m);
}

void test_isNotSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {0}, 3, 4);
    assert(isSquareMatrix(m) == 0);
    freeMemMatrix(m);
}

void test_areTwoMatricesEqual_differentDimensions() {
    matrix m1 = createMatrixFromArray((int[]) {0}, 3, 4);
    matrix m2 = createMatrixFromArray((int[]) {0}, 3, 3);

    assert(!areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_areTwoMatricesEqual() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 1,
                    1, 1,
            }, 2, 2);
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    0, 1,
                    1, 1,
            }, 2, 2);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isEMatrix_notSquare() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
            }, 2, 3);

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix_squareUnit() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1,
            }, 2, 2);

    assert(isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix_squareIsNotASingle() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    1, 1,
            }, 2, 2);

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_isNotSymmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 5, 4,
                    5, 1, 3,
                    4, 7, 5,
            }, 3, 3);

    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 5, 4,
                    5, 1, 3,
                    4, 3, 5,
            }, 3, 3);

    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_transposeSquareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 5, 4,
                    6, 1, 3,
                    7, 16, 5,
            }, 3, 3);
    transposeSquareMatrix(m);
    matrix mNew = createMatrixFromArray(
            (int[]) {
                    1, 6, 7,
                    5, 1, 16,
                    4, 3, 5,
            }, 3, 3);

    assert(areTwoMatricesEqual(m, mNew));

    freeMemMatrix(m);
    freeMemMatrix(mNew);
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    12, 3,
                    0, 16,
                    5, 6,
            }, 3, 2
    );

    assert(getMinValuePos(m).rowIndex == 1);
    assert(getMinValuePos(m).colIndex == 0);

    freeMemMatrix(m);
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    12, 3,
                    0, 16,
                    32, 6,
            }, 3, 2
    );

    assert(getMaxValuePos(m).rowIndex == 2);
    assert(getMaxValuePos(m).colIndex == 0);

    freeMemMatrix(m);
}

void test_insertionSortRowsMatrixByRowCriteria() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    12, 3,
                    0, 16,
                    5, 6,
                    0, 0,
            }, 4, 2
    );
    insertionSortRowsMatrixByRowCriteria(m, getSum);
    matrix mNew = createMatrixFromArray(
            (int[]) {
                    0, 0,
                    5, 6,
                    12, 3,
                    0, 16,
            }, 4, 2
    );

    assert(areTwoMatricesEqual(m, mNew));

    freeMemMatrix(m);
    freeMemMatrix(mNew);
}

void test_insertionSortColsMatrixByRowCriteria() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    29, 3, 9, 6,
                    0, 16, 3, 6,

            }, 2, 4
    );
    insertionSortColsMatrixByRowCriteria(m, getSum);
    matrix mNew = createMatrixFromArray(
            (int[]) {
                    9, 6, 3, 29,
                    3, 6, 16, 0,
            }, 2, 4
    );

    assert(areTwoMatricesEqual(m, mNew));

    freeMemMatrix(m);
    freeMemMatrix(mNew);
}

void test_matrix() {
    test_swapRows();
    test_swapColumns();
    test_isSquareMatrix();
    test_isNotSquareMatrix();
    test_areTwoMatricesEqual_differentDimensions();
    test_areTwoMatricesEqual();
    test_isEMatrix_notSquare();
    test_isEMatrix_squareUnit();
    test_isEMatrix_squareIsNotASingle();
    test_isNotSymmetricMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByRowCriteria();
}
*/
//

// Задачи

//

//1
void swapsRowsWhithMinAndMaxElement(matrix m) {
    swapRows(m, getMinValuePos(m).rowIndex, getMaxValuePos(m).rowIndex);
}

void test_swapsRowsWhithMinAndMaxElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    29, 3,
                    9, 6,
                    16, 0,
                    3, 6,

            }, 4, 2
    );
    swapsRowsWhithMinAndMaxElement(m);
    matrix newM = createMatrixFromArray(
            (int[]) {
                    16, 0,
                    9, 6,
                    29, 3,
                    3, 6,

            }, 4, 2
    );
    assert(areTwoMatricesEqual(m, newM));

    freeMemMatrix(m);
    freeMemMatrix(newM);
}


//2
int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void sortsRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void test_sortsRowsByMinElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    29, 3,
                    9, 6,
                    16, 0,
                    3, 6,

            }, 4, 2
    );
    sortsRowsByMinElement(m);
    matrix newM = createMatrixFromArray(
            (int[]) {
                    3, 6,
                    9, 6,
                    16, 0,
                    29, 3,
            }, 4, 2
    );
    assert(areTwoMatricesEqual(m, newM));

    freeMemMatrix(m);
    freeMemMatrix(newM);
}


//3
int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void sortsColsByMinElement(matrix m) {
    insertionSortColsMatrixByRowCriteria(m, getMin);
}

void test_sortsColsByMinElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 2,
                    2, 5, 1,
                    6, 1, 4,

            }, 3, 3
    );
    sortsColsByMinElement(m);
    matrix newM = createMatrixFromArray(
            (int[]) {
                    5, 2, 3,
                    5, 1, 2,
                    1, 4, 6,
            }, 3, 3
    );
    assert(areTwoMatricesEqual(m, newM));

    freeMemMatrix(m);
    freeMemMatrix(newM);
}


//4
matrix mulMatrices(matrix m1, matrix m2) {
    matrix m3 = createMatrixFromArray((int[]) {0,}, m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            m3.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++) {
                m3.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    return m3;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

void test_mulMatrices() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 4,
                    0, -2,
            }, 2, 2
    );
    matrix mNew = createMatrixFromArray(
            (int[]) {
                    1, -12,
                    0, 4,
            }, 2, 2
    );
    assert(areTwoMatricesEqual(mulMatrices(m, m), mNew));

    freeMemMatrix(m);
    freeMemMatrix(mNew);
}

void test_getSquareOfMatrixIfSymmetric_isSymmetric() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 4, 6,
                    4, -2, 0,
                    6, 0, 5,
            }, 3, 3
    );
    getSquareOfMatrixIfSymmetric(&m);
    matrix mNew = createMatrixFromArray(
            (int[]) {
                    53, -12, 24,
                    -12, 20, 24,
                    24, 24, 61,
            }, 3, 3
    );

    assert(areTwoMatricesEqual(m, mNew));

    freeMemMatrix(m);
    freeMemMatrix(mNew);
}

void test_getSquareOfMatrixIfSymmetric_isNotSymmetric() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 4, 6,
                    4, -2, 1,
                    6, 0, 5,
            }, 3, 3
    );
    getSquareOfMatrixIfSymmetric(&m);
    matrix mNew = createMatrixFromArray(
            (int[]) {
                    -1, 4, 6,
                    4, -2, 1,
                    6, 0, 5,
            }, 3, 3
    );

    assert(areTwoMatricesEqual(m, mNew));

    freeMemMatrix(m);
    freeMemMatrix(mNew);
}


//5
bool isUnique(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return true;
    return false;
}

void test_isUnique() {
    int a[6] = {2, 5, 6, 7, 8, 9};
    int b[3] = {6, 6, 7};
    int c[4] = {1, 0, 9, 1};
    assert(isUnique(a, 6));
    assert(!isUnique(b, 3));
    assert(!isUnique(c, 4));
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int sumOfRows[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        sumOfRows[i] = getSum(m.values[i], m.nCols);
    if (!isUnique(sumOfRows, m.nRows))
        transposeSquareMatrix(m);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_HasEqualSumOfRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 4, 6,
                    4, -2, 1,
                    6, 0, 3,
            }, 3, 3
    );
    transposeIfMatrixHasNotEqualSumOfRows(m);
    matrix mNew = createMatrixFromArray(
            (int[]) {
                    -1, 4, 6,
                    4, -2, 1,
                    6, 0, 3,
            }, 3, 3
    );

    assert(areTwoMatricesEqual(m, mNew));

    freeMemMatrix(m);
    freeMemMatrix(mNew);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_HasNotEqualSumOfRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, -7, 8,
                    4, -2, 1,
                    9, 0, -16
            }, 3, 3
    );
    transposeIfMatrixHasNotEqualSumOfRows(m);
    matrix mNew = createMatrixFromArray(
            (int[]) {
                    3, 4, 9,
                    -7, -2, 0,
                    8, 1, -16
            }, 3, 3
    );

    assert(areTwoMatricesEqual(m, mNew));

    freeMemMatrix(m);
    freeMemMatrix(mNew);
}


//6
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isEMatrix(mulMatrices(m1, m2)) && isEMatrix(mulMatrices(m1, m2)) && isSquareMatrix(m1) && isSquareMatrix(m2);
}

void test_isMutuallyInverseMatrices() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, -5,
                    1, -3
            }, 2, 2
    );
    matrix mNew = createMatrixFromArray(
            (int[]) {
                    3, -5,
                    1, -2
            }, 2, 2
    );

    assert(isMutuallyInverseMatrices(m, mNew));

    freeMemMatrix(m);
    freeMemMatrix(mNew);
}



void test() {
    //test_swapsRowsWhithMinAndMaxElement();
    //test_sortsRowsByMinElement();
    //test_sortsColsByMinElement();
    //test_mulMatrices();
    //test_getSquareOfMatrixIfSymmetric_isSymmetric();
    //test_getSquareOfMatrixIfSymmetric_isNotSymmetric();
    // test_isUnique();
    //test_transposeIfMatrixHasNotEqualSumOfRows_HasEqualSumOfRows();
    //test_transposeIfMatrixHasNotEqualSumOfRows_HasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
}

int main() {
    //test_matrix();
    test();

    return 0;
}

