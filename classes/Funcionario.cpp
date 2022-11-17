#include "Funcionario.h"

using namespace std;

Funcionario::Funcionario()
{
    setCodigo(0);
    setSalario(0.0);
}

Funcionario::~Funcionario()
{

}

int Funcionario::getCodigo()
{
    return this->codigo;
}

float Funcionario::getSalario()
{
    return this->salario;
}

std::string Funcionario::getNome()
{
    return this->nome;
}

std::string Funcionario::getTelefone()
{
    return this->telefone;
}

Data Funcionario::getData()
{
    return this->data;
}

Endereco Funcionario::getEndereco()
{
    return this->endereco;
}

void Funcionario::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void Funcionario::setSalario(float salario)
{
    this->salario = salario;
}

void Funcionario::setNome(std::string nome)
{
    this->nome = nome;
}

void Funcionario::setTelefone(std::string telefone)
{
    this->telefone = telefone;
}

void Funcionario::setData(Data data)
{
    this->data = data;
}

void Funcionario::setEndereco(Endereco endereco)
{
    this->endereco = endereco;
}