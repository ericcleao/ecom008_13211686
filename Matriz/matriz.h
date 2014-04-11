#ifndef MATRIZADT_H
#define MATRIZADT_H
#include "matrixadt.h"

class Matriz : public MatrixADT{
    int columns;
    int rows;
    int determinante;
    double **matriz;
public:

    // Construtor default
    Matriz();
    // Criar nova matriz
    virtual void create(int columns, int rows);
    // Setar valor do elemento
    virtual void setElementAt(int column, int row, double value);
    // Retorn: elemento
    virtual double elementAt(int column, int row) const;
    // Subtrai da matriz
    virtual void sub(const MatrixADT & other);
    // Multiplicar a matriz
    virtual void multiplyBy(double k);
    // Retorn: determinante
    virtual double determinant();
    // Retorna uma matriz menor ou igual a atual(de tamanho igual a size), retirando a linha m e a coluna n
    //size podendo variar do tamanho da matriz até 2
    Matriz* temporaria(int m, int n, int size);
    // Retorn: matriz transposta
    virtual MatrixADT * transpose();
    // Imprimir a matriz
    virtual QString toString();

    void square(int size);

};

#endif // MATRIZADT_H
