#include "Diretor.h"

Diretor::Diretor() : Funcionario()
{

}

Diretor::Diretor(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco)
{
    setCodigo(codigo);
    setSalario(salario);
    setNome(nome);
    setTelefone(telefone);
    setData(data);
    setEndereco(endereco);
}

Diretor::Diretor(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco, std::string areaDeSupervisao, std::string areaDeFormacao)
{
    setCodigo(codigo);
    setSalario(salario);
    setNome(nome);
    setTelefone(telefone);
    setData(data);
    setEndereco(endereco);
    setAreaDeSupervisao(areaDeSupervisao);
    setAreaDeFormacao(areaDeFormacao);
}

Diretor::~Diretor()
{

}

std::string Diretor::getAreaDeSupervisao()
{
    return areaDeSupervisao;
}

std::string Diretor::getAreaDeFormacao()
{
    return areaDeFormacao;
}

std::string Diretor::getDesignacao()
{
    return "Diretor";
}

void Diretor::setAreaDeSupervisao(std::string areaDeSupervisao)
{
    this->areaDeSupervisao = areaDeSupervisao;
}

void Diretor::setAreaDeFormacao(std::string areaDeFormacao)
{
    this->areaDeFormacao = areaDeFormacao;
}
