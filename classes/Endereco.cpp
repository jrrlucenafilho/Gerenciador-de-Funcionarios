#include "Endereco.h"

Endereco::Endereco()
{
    setNumero(0);
}

Endereco::Endereco(std::string cidade, std::string bairro, std::string rua, int numero)
{
    setCidade(cidade);
    setBairro(bairro);
    setRua(rua);
    setNumero(numero);
}

Endereco::~Endereco()
{

}

std::string Endereco::getCidade()
{
    return cidade;
}

std::string Endereco::getBairro()
{
    return bairro;
}

std::string Endereco::getRua()
{
    return rua;
}

int Endereco::getNumero()
{
    return numero;
}

void Endereco::setCidade(std::string cidade)
{
    this->cidade = cidade;
}

void Endereco::setBairro(std::string bairro)
{
    this->bairro = bairro;
}

void Endereco::setRua(std::string rua)
{
    this->rua = rua;
}

void Endereco::setNumero(int numero)
{
    this->numero = numero;
}

std::string Endereco::toString()
{
    return getCidade() + ',' + getBairro() + ',' + getRua() + ',' + std::to_string(getNumero());
}
