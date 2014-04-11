#include "veiculo.h"
#include <QDebug>

Veiculo::Veiculo(int rodas)
{
    m_rodas = rodas;
}

int Veiculo::rodas(){
    return this->m_rodas;
}

void Veiculo::setRodas(int nRodas){
    m_rodas = nRodas;
}

void Veiculo::ligar(){
    qDebug() << "Veículo ligado!" << endl;
}
