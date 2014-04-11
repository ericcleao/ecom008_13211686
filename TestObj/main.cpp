#include "veiculo.h"
#include "carro.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    Carro *c = new Carro(1923);
    Veiculo *v = c;

    c->ligar();
    v->ligar();

    return 0;
}
