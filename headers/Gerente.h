#ifndef GERENTE_H
#define GERENTE_H

#pragma once

#include "Funcionario.h"

class Gerente : public Funcionario
{
    public:
        Gerente();
        Gerente(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco);
        Gerente(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco, std::string areaDeSupervisao);
        ~Gerente();
        
        std::string getDesignacao();
        std::string getAreaDeSupervisao();

        void setAreaDeSupervisao(std::string areaDeSupervisao);

    private:
        std::string areaDeSupervisao; 

};

#endif