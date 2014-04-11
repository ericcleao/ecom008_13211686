#ifndef VEICULO_H
#define VEICULO_H

class Veiculo
{
    int m_rodas;
public:
    Veiculo(int rodas);
    int rodas();
    void setRodas(int nRodas);
    virtual void ligar();
};

#endif // VEICULO_H
