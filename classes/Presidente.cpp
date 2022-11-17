#include "Presidente.h"

Presidente::Presidente() : Funcionario()
{

}

Presidente::Presidente(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco)
{
    setCodigo(codigo);
    setSalario(salario);
    setNome(nome);
    setTelefone(telefone);
    setData(data);
    setEndereco(endereco);
}

Presidente::Presidente(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco, std::string areaDeFormacao, std::string formacaoAcademicaMax)
{
    setCodigo(codigo);
    setSalario(salario);
    setNome(nome);
    setTelefone(telefone);
    setData(data);
    setEndereco(endereco);
    setAreaDeFormacao(areaDeFormacao);
    setFormacaoAcademicaMax(formacaoAcademicaMax);
}

Presidente::~Presidente()
{

}

std::string Presidente::getAreaDeFormacao()
{
    return areaDeFormacao;
}

std::string Presidente::getFormacaoAcademicaMax()
{
    return formacaoAcademicaMax;
}

std::string Presidente::getDesignacao()
{
    return "Presidente";
}

void Presidente::setAreaDeFormacao(std::string areaDeFormacao)
{
    this->areaDeFormacao = areaDeFormacao;
}

void Presidente::setFormacaoAcademicaMax(std::string formacaoAcademicaMax)
{
    this->formacaoAcademicaMax = formacaoAcademicaMax;
}
