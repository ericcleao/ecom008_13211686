//#include <iostream>
//#include <QDebug>
#include <QString>
#include "matrixadt.h"
#include "matriz.h"

using namespace std;

Matriz::Matriz(){
    this->rows = 0;
    this->columns = 0;
    this->determinante = 0;
}

void Matriz::create(int rows, int columns){
    this->rows = rows;
    this->columns = columns;
    this->matriz = new double*[rows];
    for(int i = 0; i < rows; ++i){
        this->matriz[i] = new double[columns];
    }
}

void Matriz::setElementAt(int rows, int columns, double value){
    this->matriz[rows][columns] = value;
}

double Matriz::elementAt(int rows, int columns) const{
    return this->matriz[rows][columns];
}

void Matriz::sub(const MatrixADT & other){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            setElementAt(i, j, elementAt(i,j) - other.elementAt(i,j));
        }
    }
}

void Matriz::multiplyBy(double k){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            setElementAt(i, j, elementAt(i,j)*k);
        }
    }
}

Matriz* Matriz::temporaria(int m, int n, int size){
    if(this->columns <= size){
        return this;
    }
    int k = 0, l = 0;
    Matriz *temp = new Matriz;
    temp->create(this->columns-1, this->rows-1);
    for(int i = 0; i < this->rows; ++i){
        for(int j = 0; j < this->columns; ++j){
            if(j != m && i != n){
                temp->setElementAt(k,l,this->elementAt(i,j));
                ++l;
            }
        }
        if(l == temp->columns){
            ++k;
        }
        l = 0;
    }
    if(temp->columns > size){
        return temp->temporaria(0,0,size);
    } else{
        return temp;
    }
}

double Matriz::determinant(){
    if(this->columns != this->rows){
//        qDebug() << "The matrix must be square!";
        return 0;
    }
    for(int j = this->columns; j > 2; --j){
        for(int i = this->columns-1; i >= 0; --i){
            if(i == j){
                return this->determinante;
            }
     //       qDebug() << i << j;
     //       qDebug() << "elemento" << this->temporaria(i,0,j)->elementAt(0,i);
     //       qDebug () << qPrintable(this->temporaria(i,0,j-1)->toString());
     //       qDebug() <<  "               " << this->temporaria(i,0,j-1)->determinant();
            if(i%2 == 0){
                this->determinante += this->temporaria(i,0,j)->elementAt(0,i)*this->temporaria(i,0,j-1)->determinant();
     //           qDebug() << "par" << this->determinante << i;
            } else{
                this->determinante -= this->temporaria(i,0,j)->elementAt(0,i)*this->temporaria(i,0,j-1)->determinant();
     //           qDebug() << "impar" << this->determinante << i;
            }
        }
    }
    if(columns == 2){
        return (this->temporaria(0,0,2)->elementAt(0,0)*this->temporaria(0,0,2)->elementAt(1,1)) - (this->temporaria(0,0,2)->elementAt(0,1)*this->temporaria(0,0,2)->elementAt(1,0));
    }

    return this->determinante;
}

MatrixADT* Matriz::transpose(){
    Matriz *transposed = new Matriz;

    transposed->create(this->columns,this->rows);

    for(int i = 0; i < transposed->rows; ++i){
        for(int j = 0; j < transposed->columns; ++j){
            transposed->setElementAt(i,j,this->elementAt(j,i));
        }
    }
    return (MatrixADT*)transposed;
}

QString Matriz::toString(){
    QString print = "";
    int j;
    for(int i = 0; i < rows; ++i){
        for(j = 0; j < columns - 1; ++j){
            print += QString::number(this->elementAt(i,j)) + " ";
        }
        print += QString::number(this->elementAt(i,j)) + "\n";
    }
    return print;
}

void Matriz::square(int size){
    this->create(size, size);
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            setElementAt(i,j,(int)rand()/10000);
        }
    }
}

/*
void Matriz::print(){
    for(int j =0; j < rows; ++j){
        for(int i = 0; i < columns; ++i){
            cout << this->elementAt(j,i) << " ";
        }
        cout << endl;
    }
}
*/
