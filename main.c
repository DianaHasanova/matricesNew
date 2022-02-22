#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

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
                    0, 1, 1
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
    //assert(isUnique(a, 6));
    //assert(!isUnique(b, 3));
    //assert(!isUnique(c, 4));
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


//7
long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sumOfMaxesOfPseudoDiagonal = 0;
    int r = m.nRows - 1;
    int arraySize = m.nRows + m.nCols - 1;
    int a[arraySize];
    for (int i = 0; i < arraySize; i++)
        a[i] = INT_MIN;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            a[j - i + r] = max(m.values[i][j], a[j - i + r]);
    for (int i = 0; i < arraySize; i++)
        sumOfMaxesOfPseudoDiagonal += a[i];
    return sumOfMaxesOfPseudoDiagonal - a[r];
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            }, 3, 4
    );


    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);

    freeMemMatrix(m);
}


//8
int min(int a, int b) {
    return a < b ? a : b;
}

int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(m);
    int LeftPos = maxPos.colIndex - 1;
    int RightPos = maxPos.colIndex + 2;
    int minAreaElement = m.values[maxPos.rowIndex][maxPos.colIndex];

    for (int i = maxPos.rowIndex - 1; i > -1; i--) {
        for (int j = LeftPos; j < RightPos; j++)
            minAreaElement = min(m.values[i][j], minAreaElement);
        if (LeftPos > 0)
            LeftPos--;
        if (RightPos < m.nCols)
            RightPos++;
    }

    return minAreaElement;
}

void test_getMinInArea_1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2
            }, 3, 4
    );

    assert(getMinInArea(m) == 5);

    freeMemMatrix(m);
}

void test_getMinInArea_2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1
            }, 3, 4
    );

    assert(getMinInArea(m) == 6);

    freeMemMatrix(m);
}


//9
float getDistance(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * a[i];
    return sqrt(sum);
}

void sortByDistances(matrix m) {
    float criteriaRows[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        criteriaRows[i] = getDistance(m.values[i], m.nCols);
    for (int i = 0; i < m.nRows - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < m.nRows; j++)
            if (criteriaRows[j] < criteriaRows[minPos])
                minPos = j;
        swapf(&criteriaRows[i], &criteriaRows[minPos]);
        swapRows(m, i, minPos);
    }
}

void test_sortByDistances() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 12,
                    6, 8,
                    9, 2
            }, 3, 2
    );
    matrix newM = createMatrixFromArray(
            (int[]) {
                    9, 2,
                    6, 8,
                    7, 12,
            }, 3, 2
    );

    sortByDistances(m);
    assert(areTwoMatricesEqual(m, newM));

    freeMemMatrix(m);
    freeMemMatrix(newM);
}


//10
int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(long long *) pa;
    long long arg2 = *(long long *) pb;
    if (arg1 < arg2)
        return -1;
    else if (arg1 > arg2)
        return 1;
    else
        return 0;
}

int countNUnique(long long *a, int n) {
    int countUnique = 1;
    long long thisElement = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] != thisElement) {
            thisElement = a[i];
            countUnique++;
        }
    return countUnique;
}

int countEqClassesByRowsSum(matrix m) {
    long long *a = (long long *) calloc(m.nRows, sizeof(long long));
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            a[i] += m.values[i][j];
    qsort(a, m.nRows, sizeof(long long), cmp_long_long);
    int countUnique = countNUnique(a, m.nRows);
    free(a);
    return countUnique;
}

void test_countEqClassesByRowsSum() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0
            }, 6, 2
    );

    assert(countEqClassesByRowsSum(m) == 3);

    freeMemMatrix(m);
}


//11
int getNSpecialElement(matrix m) {
    int k = 0;
    for (int j = 0; j < m.nCols; j++) {
        int maxElementCols = INT_MIN;
        long long sumOfSquaresOfColElements = 0;
        for (int i = 0; i < m.nRows; i++) {
            sumOfSquaresOfColElements += m.values[i][j];
            maxElementCols = max(maxElementCols, m.values[i][j]);
        }
        if (2 * maxElementCols > sumOfSquaresOfColElements)
            k++;
    }
    return k;
}

void test_getNSpecialElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2
            }, 3, 4
    );
    assert(getNSpecialElement(m) == 2);

    freeMemMatrix(m);
}


//12
void swapPenultimateRow(matrix m) {
    if (m.nRows != m.nCols) {
        printf("matrix is not square");
        return;
    }
    int PenultimateRow = m.nCols - 2;
    int firstColMinElements = getMinValuePos(m).colIndex;
    for (int i = m.nRows - 1; i > -1; i--)
        m.values[PenultimateRow][i] = m.values[i][firstColMinElements];
}

void test_swapPenultimateRow_1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1
            }, 3, 3
    );
    swapPenultimateRow(m);
    matrix newM = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1
            }, 3, 3
    );

    assert(areTwoMatricesEqual(m, newM));

    freeMemMatrix(m);
    freeMemMatrix(newM);
}

void test_swapPenultimateRow_2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    4, 5
            }, 2, 2
    );
    swapPenultimateRow(m);
    matrix newM = createMatrixFromArray(
            (int[]) {
                    1, 4,
                    4, 5
            }, 2, 2
    );

    assert(areTwoMatricesEqual(m, newM));

    freeMemMatrix(m);
    freeMemMatrix(newM);
}


//13
bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int n) {
    int countMatrices = 0;
    for (int i = 0; i < n; i++)
        if (hasAllNonDescendingRows(ms[i]))
            countMatrices++;
    return countMatrices;
}

void test_countNonDescendingRowsMatrices_1() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    3, 4, 5,
                    6, 7, 8,

                    9, 10, 11,
                    12, 14, 15,
                    16, 17, 0
            }, 2, 3, 3
    );

    assert(countNonDescendingRowsMatrices(ms, 2) == 1);

    freeMemMatrices(ms, 2);
}

void test_countNonDescendingRowsMatrices_2() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    9, 4, 5,

                    22, 10, 11,
                    12, 14, 15
            }, 2, 3, 3
    );

    assert(countNonDescendingRowsMatrices(ms, 2) == 0);

    freeMemMatrices(ms, 2);
}


//14
int countZeroRows(matrix m) {
    int countRows = 0;
    for (int i = 0; i < m.nRows; i++) {
        int r = 0;
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] != 0)
                r = 1;
        if (r == 0)
            countRows++;
    }
    return countRows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int a[nMatrix];
    int maxCountZero = 0;
    for (int i = 0; i < nMatrix; i++) {
        int countZero = countZeroRows(ms[i]);
        a[i] = countZero;
        maxCountZero = max(maxCountZero, countZero);
    }
    for (int i = 0; i < nMatrix; i++) {
        if (a[i] == maxCountZero)
            outputMatrix(ms[i]);
    }
}

void test_countZeroRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    3, 1,
                    0, 0,
                    0, 7,
                    0, 0
            }, 5, 2
    );

    assert(countZeroRows(m) == 2);

    freeMemMatrix(m);
}


//15
int getALargeValueModuloTheElement(matrix m) {
    int norma = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            norma = max(norma, abs(m.values[i][j]));
    return norma;
}

void printMatrixWithMinFromMaxModuloTheElement(matrix *ms, int nMatrix) {
    int a[nMatrix];
    int minModuloTheElement = INT_MAX;
    for (int i = 0; i < nMatrix; i++) {
        int maxModuloElementsFromMatrix = getALargeValueModuloTheElement(ms[i]);
        a[i] = maxModuloElementsFromMatrix;
        minModuloTheElement = min(minModuloTheElement, maxModuloElementsFromMatrix);
    }
    for (int i = 0; i < nMatrix; i++) {
        if (a[i] == minModuloTheElement)
            outputMatrix(ms[i]);
    }
}


void test_getALargeValueModuloTheElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 2,
                    4, -5
            }, 2, 2
    );

    assert(getALargeValueModuloTheElement(m) == 5);

    freeMemMatrix(m);
}

void test() {
    test_swapsRowsWhithMinAndMaxElement();
    test_sortsRowsByMinElement();
    test_sortsColsByMinElement();
    test_mulMatrices();
    test_getSquareOfMatrixIfSymmetric_isSymmetric();
    test_getSquareOfMatrixIfSymmetric_isNotSymmetric();
    test_isUnique();
    test_transposeIfMatrixHasNotEqualSumOfRows_HasEqualSumOfRows();
    test_transposeIfMatrixHasNotEqualSumOfRows_HasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea_1();
    test_getMinInArea_2();
    test_sortByDistances();
    test_getNSpecialElement();
    test_swapPenultimateRow_1();
    test_swapPenultimateRow_2();
    test_countEqClassesByRowsSum();
    test_countNonDescendingRowsMatrices_1();
    test_countNonDescendingRowsMatrices_2();
    test_countZeroRows();
    test_getALargeValueModuloTheElement();
}

int main() {
    test_matrix();
    test();

    return 0;
}

