#include <iostream>
#include "EasterEgg.h"
#include "Funcionario.h"
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Empresa.h"
#include "Menu.h"

using namespace std;

enum opcoes {ADD_FUNC = 1, REMOCAO_FUNCS = 2, EXIBICAO_REGISTROS = 3, EDIT_FUNCS = 4, IMPORT_E_EXPORT_ARQ = 5};

int main(void)
{
    Empresa empresa;
    Empresa *empresaPtr = &empresa;
    Menu menu;
    int opcao;

    system("cls");
    while(true)
    {
        menu.menuPrincipal();
        cin >> opcao;
        cin.ignore();
        system("cls");

        if(!opcao){
            break;
        }

        switch(opcao)
        {
        case ADD_FUNC:
            menu.menuAddFuncionario(empresaPtr);    //ULD
            break;

        case REMOCAO_FUNCS:
            menu.menuRemoverFuncionarios(empresaPtr);   //ANA
            break;
        
        case EXIBICAO_REGISTROS:
            menu.menuExibirRegistros(empresaPtr);   //ANA
            break;
        
        case EDIT_FUNCS:
            menu.menuEditarFuncionarios(empresaPtr);    //JR
            break;
        
        case IMPORT_E_EXPORT_ARQ:
            menu.menuExportarImportarArquivo(empresaPtr);   //ULD
            break;
        
        case SEC_COMB:
            EasterEgg();
            cin.get();
            break;

        default:
            break;
        }

        system("cls");
    }

    return 0;
}