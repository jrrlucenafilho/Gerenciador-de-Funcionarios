#ifndef DIRETOR_H
#define DIRETOR_H

#pragma once

#include "Funcionario.h"

class Diretor : public Funcionario
{
    public:
        Diretor();
        Diretor(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco);
        Diretor(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco, std::string areaDeSupervisao, std::string areaDeFormacao);
        ~Diretor();
        
        std::string getDesignacao();
        std::string getAreaDeSupervisao();
        std::string getAreaDeFormacao();

        void setAreaDeSupervisao(std::string areaDeSupervisao);
        void setAreaDeFormacao(std::string areaDeFormacao);

    private:
        std::string areaDeSupervisao;
        std::string areaDeFormacao;

};

#endif