//
// Created by Дианочка on 19.02.2022.
//

#include "matrix.h"
#include "malloc.h"
#include "stdbool.h"
#include "stdio.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swapf(float *a, float *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, int i1, int i2) {
    int *pi1 = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = pi1;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        int element = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = element;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int criteriaRows[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        criteriaRows[i] = criteria(m.values[i], m.nCols);
    for (int i = 0; i < m.nRows - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < m.nRows; j++)
            if (criteriaRows[j] < criteriaRows[minPos])
                minPos = j;
        swap(&criteriaRows[i], &criteriaRows[minPos]);
        swapRows(m, i, minPos);
    }
}

void insertionSortColsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int arrayCols[m.nRows];
    int criteriaCols[m.nCols];
    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++)
            arrayCols[j] = m.values[j][i];
        criteriaCols[i] = criteria(arrayCols, m.nCols);
    }
    for (int i = 0; i < m.nCols - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < m.nCols; j++)
            if (criteriaCols[j] < criteriaCols[minPos])
                minPos = j;
        swap(&criteriaCols[i], &criteriaCols[minPos]);
        swapColumns(m, i, minPos);
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if ((m1.nRows != m2.nRows) || (m1.nCols != m2.nCols))
        return false;
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m1.nCols; j++)
            if (m1.values[i][j] != m2.values[i][j])
                return false;
    return true;
}

bool isEMatrix(matrix m) {
    if (m.nRows != m.nCols)
        return false;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nRows; j++)
            if (!((i != j) && (m.values[i][j] == 0) || (i == j) && (m.values[i][j] == 1)))
                return false;
    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (int i = 0; i < m.nRows; i++)
        for (int j = i; j < m.nCols; j++)
            if (m.values[i][j] != m.values[j][i])
                return false;
    return true;
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = i + 1; j < m.nCols; j++)
            swap(&m.values[i][j], &m.values[j][i]);
}

position getMinValuePos(matrix m) {
    int min = m.values[0][0];
    int minI = 0, minJ = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                minI = i;
                minJ = j;
            }
    return (position) {minI, minJ};
}

position getMaxValuePos(matrix m) {
    int max = m.values[0][0];
    int maxI = 0, maxJ = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > max) {
                max = m.values[i][j];
                maxI = i;
                maxJ = j;
            }
    return (position) {maxI, maxJ};
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *creatArrayOfMatrixFromArray(const int *value, int nMatrices, int nRows, int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = value[l++];

    return ms;
}

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices, int nRows, int nCols) {
    matrix *matrices = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                matrices[k].values[i][j] = values[l++];
    return matrices;
}