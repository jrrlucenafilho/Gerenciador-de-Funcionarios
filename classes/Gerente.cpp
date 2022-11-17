#include "Gerente.h"

Gerente::Gerente() : Funcionario()
{

}

Gerente::Gerente(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco)
{
    setCodigo(codigo);
    setSalario(salario);
    setNome(nome);
    setTelefone(telefone);
    setData(data);
    setEndereco(endereco);
}

Gerente::Gerente(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco, std::string areaDeSupervisao)
{
    setCodigo(codigo);
    setSalario(salario);
    setNome(nome);
    setTelefone(telefone);
    setData(data);
    setEndereco(endereco);
    setAreaDeSupervisao(areaDeSupervisao);
}

Gerente::~Gerente()
{

}

std::string Gerente::getDesignacao()
{
    return "Gerente";
}

std::string Gerente::getAreaDeSupervisao()
{
    return areaDeSupervisao;
}

void Gerente::setAreaDeSupervisao(std::string areaDeSupervisao)
{
    this->areaDeSupervisao = areaDeSupervisao;
}
