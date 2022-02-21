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

void test() {
    // test_swapsRowsWhithMinAndMaxElement();
    //test_sortsRowsByMinElement();
    test_sortsColsByMinElement();
}

int main() {
    //test_matrix();
    test();

    return 0;
}

