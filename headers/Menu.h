#ifndef MENU_H
#define MENU_H

#pragma once

#include <iostream>
#include <vector>
#include "Empresa.h"

class Menu
{
    public:
        Menu();
        virtual ~Menu();

        void menuPrincipal();
        void menuAddFuncionario(Empresa* empresa);
        void menuRemoverFuncionarios(Empresa* empresa);
        void menuExibirRegistros(Empresa* empresa);
        void menuEditarFuncionarios(Empresa* empresa);
        void menuExportarImportarArquivo(Empresa* empresa);

    private:
        void printRegistroFuncionario(Empresa* empresa, int codigoFunc);
        void printRegistrosFuncionarios(std::vector<Funcionario*> funcs);
        std::string capitalizaDesignacao(std::string& designacao);
        bool validaDesignacao(std::string designacao);
};

#endif