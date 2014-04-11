#include <QDebug>
#include <QString>
#include <stdlib.h>
#include <string>

using namespace std;

//struct _pessoa{
//    char *nome;
//    unsigned int idade;
//} typedef Pessoa;

//void PessoaPrint(Pessoa *p){
//    qDebug() << "Pessoa::";
//    qDebug() << "Nome: " << p->nome;
//    qDebug() << "Idade: " << p->idade;
//}

class Pessoa{
public:
    QString nome;
    unsigned int idade;
//    void setAll(QString nome, int idade){
//        this->nome = nome;
//        this->idade = idade;
//    }
    Pessoa(QString nome, unsigned int idade){
        this->nome = nome;
        this->idade = idade;
    }

    ~Pessoa(){
        qDebug() << "Objeto deletado:" << qPrintable(this->nome);
    }

    void print(){
        qDebug() << "Pessoa::";
        qDebug() << "Nome: " << qPrintable(this->nome);
        qDebug() << "Idade: " << this->idade;
    }
};


int soma(int a, int b){
    return a+b;
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    qDebug() << "Hello world!";
    qDebug() << "Soma: " << soma(1,2);

    Pessoa cicrano("Cicrano", 150);
    Pessoa *fulano = new Pessoa("Fulano", 30);

//    fulano->setAll("Fulano", 30);

//    PessoaPrint(fulano);

    cicrano.print();
    fulano->print();

    delete fulano;
    return 0;
}
