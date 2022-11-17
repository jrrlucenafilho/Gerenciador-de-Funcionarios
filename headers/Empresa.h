#ifndef EMPRESA_H
#define EMPRESA_H

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "Funcionario.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Operador.h"

class Empresa
{
    public:
        Empresa();
        virtual ~Empresa();

        Funcionario* getFuncionario(int index);
        Funcionario* getFuncionarioPorCodigo(int codigo);
        int getNumDeFuncionarios();
        void addFuncionario(Funcionario* func);
        void removeFuncionario(Funcionario* func);
        void removeFuncionario(int codigo);
        void substituirFuncionario(int codigo, Funcionario* funcSubstituto);
        std::vector<Funcionario*> getTodosOsFuncionarios();
        std::vector<Funcionario*> filtrarPorDesignacao(std::string designacao);
        std::vector<Funcionario*> filtrarPorNome(std::string nome);
        bool funcionarioExiste(int codigo);
        bool funcionarioExiste(std::string designacao);

        void exportaArquivo(std::string nomeArquivo);
        void importaArquivo(std::string nomeArquivo);

    private:
        std::vector<Funcionario*> funcionarios;
};

#endif