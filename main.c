#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>

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

void isEMatrix_notSquare() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
            }, 2, 3);

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void isEMatrix_squareUnit() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1,
            }, 2, 2);

    assert(isEMatrix(m));

    freeMemMatrix(m);
}

void isEMatrix_squareIsNotASingle() {
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

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
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
    isEMatrix_notSquare();
    isEMatrix_squareUnit();
    isEMatrix_squareIsNotASingle();
    test_isNotSymmetricMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByRowCriteria();
}


int main() {
    test_matrix();
    /*   matrix m = createMatrixFromArray(
               (int[]) {
                       29, 3, 9, 6,
                       0, 16, 3, 6,

               }, 2, 4
       );

       // swap(&m.values[2][1], &m.values[3][0]);
       //printf("%d",)
       insertionSortColsMatrixByRowCriteria(m, getSum);

       outputMatrix(m);
       freeMemMatrix(m);
   */
    return 0;
}

