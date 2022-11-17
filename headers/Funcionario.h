#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#pragma once

#include <string>
#include "Data.h"
#include "Endereco.h"

class Funcionario
{
    public:
        Funcionario();
        virtual ~Funcionario();
        
        virtual std::string getDesignacao() = 0;
        int getCodigo();
        float getSalario();
        std::string getNome();
        std::string getTelefone();
        Data getData();
        Endereco getEndereco();

        void setDesignacao(std::string designacao);
        void setCodigo(int codigo);
        void setSalario(float salario);
        void setNome(std::string nome);
        void setTelefone(std::string telefone);
        void setData(Data data);
        void setEndereco(Endereco endereco);
        
    protected:
        int codigo;
        float salario;
        std::string nome, telefone;
        Data data;
        Endereco endereco;
};

#endif