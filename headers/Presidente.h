#ifndef PRESIDENTE_H
#define PRESIDENTE_H

#pragma once

#include "Funcionario.h"

class Presidente : public Funcionario
{
    public:
        Presidente();
        Presidente(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco);
        Presidente(int codigo, float salario, std::string nome, std::string telefone, Data data, Endereco endereco, std::string areaDeFormacao, std::string formacaoAcademicaMax);
        ~Presidente();
        
        std::string getDesignacao();
        std::string getAreaDeFormacao();
        std::string getFormacaoAcademicaMax();

        void setAreaDeFormacao(std::string areaDeFormacao);
        void setFormacaoAcademicaMax(std::string formacaoAcademicaMax);

    private:
        std::string areaDeFormacao;
        std::string formacaoAcademicaMax;

};

#endif