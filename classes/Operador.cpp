#include "Operador.h"

Operador::Operador() : Funcionario()
{

}

Operador::Operador(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco)
{
    setCodigo(codigo);
    setSalario(salario);
    setNome(nome);
    setTelefone(telefone);
    setData(data);
    setEndereco(endereco);
}

Operador::~Operador()
{

}

std::string Operador::getDesignacao()
{
    return "Operador";
}
