#ifndef OPERADOR_H
#define OPERADOR_H

#pragma once

#include "Funcionario.h"

class Operador : public Funcionario
{
    public:
        Operador();
        Operador(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco);
        ~Operador();

        std::string getDesignacao();

    private:

};

#endif