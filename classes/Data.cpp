#include "Data.h"

Data::Data()
{
    setDia(0);
    setMes(0);
    setAno(0);
}

Data::Data(int dia, int mes, int ano)
{
    setDia(dia);
    setMes(mes);
    setAno(ano);
}

Data::~Data()
{

}

int Data::getDia()
{
    return dia;
}

int Data::getMes()
{
    return mes;
}

int Data::getAno()
{
    return ano;
}

void Data::setDia(int novoDia)
{
    if((novoDia <= 31) && (novoDia >= 1)){
        dia = novoDia;
    }else{
        dia = -1;
    }
}

void Data::setMes(int novoMes)
{
    if((novoMes <= 12) && (novoMes >= 1)){
        mes = novoMes;
    }else{
        mes = -1;
    }
}

void Data::setAno(int novoAno)
{
    if(novoAno > 0){
        ano = novoAno;
    }else{
        ano = -1;
    }
}

std::string Data::toString()
{
    return std::to_string(getDia()) + '/' + std::to_string(getMes()) + '/' + std::to_string(getAno());
}
