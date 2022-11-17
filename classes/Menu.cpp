#include "Menu.h"

using namespace std;

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::menuPrincipal()
{
    cout << "#############################################################################\n";
    cout << "##   _____                          _           _                  _       ##\n";
    cout << "##  / ____|                        (_)         | |                | |      ##\n";
    cout << "## | |  __  ___ _ __ ___ _ __   ___ _  __ _  __| | ___  _ __    __| | ___  ##\n";
    cout << "## | | |_ |/ _ \\ \'__/ _ \\ \'_ \\ / __| |/ _` |/ _` |/ _ \\| \'__|  / _` |/ _ \\ ##\n";
    cout << "## | |__| |  __/ | |  __/ | | | (__| | (_| | (_| | (_) | |    | (_| |  __/ ##\n";
    cout << "##  \\_____|\\___|_|  \\___|_| |_|\\___|_|\\__,_|\\__,_|\\___/|_|     \\__,_|\\___| ##\n";
    cout << "## |  ____|              (_)                      (_)                      ##\n";
    cout << "## | |__ _   _ _ __   ___ _  ___  _ __   __ _ _ __ _  ___  ___             ##\n";
    cout << "## |  __| | | | \'_ \\ / __| |/ _ \\| \'_ \\ / _` | \'__| |/ _ \\/ __|            ##\n";
    cout << "## | |  | |_| | | | | (__| | (_) | | | | (_| | |  | | (_) \\__ \\            ##\n";
    cout << "## |_|   \\__,_|_| |_|\\___|_|\\___/|_| |_|\\__,_|_|  |_|\\___/|___/            ##\n";
    cout << "##                                                                         ##\n";
    cout << "#############################################################################\n";
    cout << "#############################################################################\n";
    cout << "##                                                                         ##\n";
    cout << "##       1 - Adicionar Funcionário      4 - Editar um Registro             ##\n";
    cout << "##       2 - Remoção de Registros       5 - Importar/Exportar Arquivo      ##\n";
    cout << "##       3 - Exibição de Registros      0 - Sair                           ##\n";
    cout << "##                                                                         ##\n";
    cout << "#############################################################################\n";
}

void Menu::menuExibirRegistros(Empresa* empresa)
{
    //primeiro checa se há funcionarios
    if(empresa->getNumDeFuncionarios() == 0){
        cout << "(!)---> Ainda não há registros salvos, a lista está vazia.\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }

    int opcao;

    cout << "########################################\n";
    cout << "##        Exibição de Registros       ##\n";
    cout << "########################################\n";
    cout << "##                                    ##\n";
    cout << "##    1 - Exibir um registro          ##\n";
    cout << "##    2 - Exibir por designação       ##\n";
    cout << "##    3 - Exibir todos os registros   ##\n";
    cout << "##    4 - Exibir por nome             ##\n";
    cout << "##                                    ##\n";
    cout << "########################################\n";
    cin >> opcao;
    cin.ignore();
    system("cls");

    switch (opcao)
    {
    case 1:
    {
        int codigoFunc;

        cout << "#################################\n";
        cout << "##      Exibir um registro     ##\n";
        cout << "#################################\n";
        cout << "---> Insira o código do funcionário: ";
        cout << ">>> Código: ";
        cin >> codigoFunc;
        cin.ignore();

        if(!empresa->funcionarioExiste(codigoFunc)){
            cout << "\n(!)---> Não há funcionários com esse código no registro, tente novamente.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }

        printRegistroFuncionario(empresa, codigoFunc);

        cout << "\n---> Registro impresso com êxito!\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    case 2:
    {
        string designacao;

        cout << "#######################################\n";
        cout << "##  Exibir Registros por Designação  ##\n";
        cout << "#######################################\n";
        cout << "---> Insira a designação desejada: \n";
        cout << ">>> Designação: ";
        getline(cin, designacao);
        
        if(!validaDesignacao(designacao)){
            cout << "\n(!)---> Designacao Inválida, exibição cancelada\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }

        //conversão para uppercase do 1° char da designacao, caso seja lowercase
        capitalizaDesignacao(designacao);

        if(!empresa->funcionarioExiste(designacao)){
            cout << "\n(!)---> Não há registros com essa designação, a lista está vazia.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }

        vector<Funcionario*> funcionarios = empresa->filtrarPorDesignacao(designacao);

        cout << "\n######################################################################################################################################################################################\n";
        cout << "##                                                                               Lista de Registros Por Designação                                                                  ##\n";
        cout << "######################################################################################################################################################################################\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "|  Codigo     |  Nome    |  Salario    |  Telefone    |  Endereco    |  Data de Ingresso   |  Designacao   |  Area de Supervisao   | Area de Formacao   | Formacao Academica Maxima  |\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

        for(int i = 0; i < (int)funcionarios.size(); i++){
            cout << "| " << funcionarios.at(i)->getCodigo() << " | "  << funcionarios.at(i)->getNome() << " | " << "R$ " << funcionarios.at(i)->getSalario();
            cout << " | " << funcionarios.at(i)->getTelefone() << " | " << funcionarios.at(i)->getEndereco().toString() << " | " << funcionarios.at(i)->getData().toString();
            cout << " | " << funcionarios.at(i)->getDesignacao() << " | ";

            if(funcionarios.at(i)->getDesignacao() == "Gerente"){
                cout << ((Gerente*)funcionarios.at(i))->getAreaDeSupervisao() << " | - | - |\n";

            }else if(funcionarios.at(i)->getDesignacao() == "Diretor"){
                cout << ((Diretor*)funcionarios.at(i))->getAreaDeSupervisao() << " | " << ((Diretor*)funcionarios.at(i))->getAreaDeFormacao();
                cout << " | - |\n";

            }else if(funcionarios.at(i)->getDesignacao() == "Presidente"){
                cout << "- | " << ((Presidente*)funcionarios.at(i))->getAreaDeFormacao() << " | ";
                cout << ((Presidente*)funcionarios.at(i))->getFormacaoAcademicaMax() << " |\n";

            }else{
                cout << "- | - | - |\n";
            }
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        }
        cout << "######################################################################################################################################################################################\n";
        
        cout << "\n---> Lista de registros por designação impressa com êxito!\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    case 3:
    {
        vector<Funcionario*> funcionarios = empresa->getTodosOsFuncionarios();

        cout << "\n######################################################################################################################################################################################\n";
        cout << "##                                                                               Lista de Registros                                                                                 ##\n";
        cout << "######################################################################################################################################################################################\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "|  Codigo     |  Nome    |  Salario    |  Telefone    |  Endereco    |  Data de Ingresso   |  Designacao   |  Area de Supervisao   | Area de Formacao   | Formacao Academica Maxima  |\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

        for(int i = 0; i < (int)funcionarios.size(); i++){
            cout << "| " << funcionarios.at(i)->getCodigo() << " | "  << funcionarios.at(i)->getNome() << " | " << "R$ " <<  funcionarios.at(i)->getSalario();
            cout << " | " << funcionarios.at(i)->getTelefone() << " | " << funcionarios.at(i)->getEndereco().toString() << " | " << funcionarios.at(i)->getData().toString();
            cout << " | " << funcionarios.at(i)->getDesignacao() << " | ";

            if(funcionarios.at(i)->getDesignacao() == "Gerente"){
                cout << ((Gerente*)funcionarios.at(i))->getAreaDeSupervisao() << " | - | - |\n";
            }else if(funcionarios.at(i)->getDesignacao() == "Diretor"){
                cout << ((Diretor*)funcionarios.at(i))->getAreaDeSupervisao() << " | " << ((Diretor*)funcionarios.at(i))->getAreaDeFormacao();
                cout << " | - |\n";
            }else if(funcionarios.at(i)->getDesignacao() == "Presidente"){
                cout << "- | " << ((Presidente*)funcionarios.at(i))->getAreaDeFormacao() << " | ";
                cout << ((Presidente*)funcionarios.at(i))->getFormacaoAcademicaMax() << " |\n";
            }else{
                cout << "- | - | - |\n";
            }
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        }
        cout << "######################################################################################################################################################################################\n";
        
        cout << "\n---> Lista de registros impressa com êxito!\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    case 4:
    {
        string nome;
        vector<Funcionario*> funcs;

        cout << "#######################################\n";
        cout << "##     Exibir Registros por nome     ##\n";
        cout << "#######################################\n";
        cout << "---> Insira o nome a ser pesquisado: \n";
        cout << ">>> Nome: ";
        getline(cin, nome);

        if(empresa->filtrarPorNome(nome).size() == 0){
            cout << "\n(!)---> Não há funcionários registrados com esse nome.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }

        funcs = empresa->filtrarPorNome(nome);
        printRegistrosFuncionarios(funcs);
        
        cout << "\n---> Lista de registros por nome impressa com êxito!\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    default:
    {
        cout << "\n(!)---> Entrada inválida.\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    }
}

void Menu::menuAddFuncionario(Empresa* empresa)
{
    int codigo, numRua, dia, mes, ano;
    float salario;
    string nome, telefone, designacao, areaDeSup, areaDeForm, formAcadMax;
    string cidade, bairro, rua;
    Endereco endereco;
    Data data;
    Funcionario *func;

    cout << "#################################\n";
    cout << "##    Adicionar Funcionario    ##\n";
    cout << "#################################\n";
    cout << "---> Insira os Devidos Atributos Para o Funcionario:\n";
    cout << ">>> Codigo: ";
    cin >> codigo;
    cin.ignore();

    if(empresa->funcionarioExiste(codigo)){
        cout << "\n(!)---> Já existe um funcionário com esse código, tente novamente.\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }

    cout << ">>> Nome: ";
    getline(cin, nome);
    cout << ">>> Designacao: ";
    getline(cin, designacao);

    if(!validaDesignacao(designacao)){
        cout << "\n(!)---> Designacao Inválida, adesão cancelada\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }

    cout << ">>> Salario: ";
    cin >> salario;
    cin.ignore();
    cout << ">>> Número de Telefone: ";
    getline(cin, telefone);
    system("cls");

    cout << "---> Informacoes Sobre o Endereco: \n";
    cout << ">>> Cidade: ";
    getline(cin, cidade);
    cout << ">>> Bairro: ";
    getline(cin, bairro);
    cout << ">>> Rua: ";
    getline(cin, rua);
    cout << ">>> Numero: ";
    cin >> numRua;
    system("cls");

    endereco = Endereco(cidade, bairro, rua, numRua);

    cout << "---> Informacoes Sobre a Data de Ingresso: \n";
    cout << ">>> Dia: ";
    cin >> dia;
    cout << ">>> Mês (número): ";
    cin >> mes;
    cout << ">>> Ano: ";
    cin >> ano;
    cin.ignore();

    data = Data(dia, mes, ano);

    if(!((designacao == "Operador") || (designacao == "operador"))){
        system("cls");
        cout << "---> Informacoes Relacionadas à Designacao: \n";
    }

    if((designacao == "Diretor") || (designacao == "diretor")){
        cout << ">>> Area de Supervisao: ";
        getline(cin, areaDeSup);
        cout << ">>> Area De Formacao: ";
        getline(cin, areaDeForm);

        func = new Diretor(codigo, salario, nome, telefone, data, endereco, areaDeSup, areaDeForm); 
    }
    if((designacao == "Presidente") || (designacao == "presidente")){
        cout << ">>> Area de Formacao: ";
        getline(cin, areaDeForm);
        cout << ">>> Formacao Academica Maxima: ";
        getline(cin, formAcadMax);

        func = new Presidente(codigo, salario, nome, telefone, data, endereco, areaDeForm, formAcadMax);
    }
    if((designacao == "Gerente") || (designacao == "gerente")){
        cout << ">>> Area de Supervisao: ";
        getline(cin, areaDeSup);
        
        func = new Gerente(codigo, salario, nome, telefone, data, endereco, areaDeSup);
    }
    if((designacao == "Operador") || (designacao == "operador")){
        func = new Operador(codigo, salario, nome, telefone, data, endereco);
    }

    empresa->addFuncionario(func);
    cout << "\n---> Funcionário adicionado com êxito!\n";
    cout << "---> Pressione enter para continuar.\n";
    cin.get();
}

void Menu::menuRemoverFuncionarios(Empresa* empresa)
{
    if(empresa->getNumDeFuncionarios() == 0){
        cout << "(!)---> Ainda não há registros salvos, sem funcionários para remover.\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }

    int opcao;

    cout << "########################################\n";
    cout << "##        Remoção de Registros        ##\n";
    cout << "########################################\n";
    cout << "##                                    ##\n";
    cout << "##    1 - Remover um registro         ##\n";
    cout << "##    2 - Remover todos os registros  ##\n";
    cout << "##                                    ##\n";
    cout << "########################################\n";
    cin >> opcao;
    cin.ignore();
    system("cls");

    switch (opcao)
    {
    case 1:
    {
        int codigoFunc, confirmacao;

        cout << "#################################\n";
        cout << "##      Remover Registro       ##\n";
        cout << "#################################\n";
        cout << "---> Insira o Código do Funcionário a ser Removido: \n";
        cout << "---> (Presidentes e Diretores não podem ser removidos)\n";
        cout << ">>> Código: ";
        cin >> codigoFunc;
        cin.ignore();

        if(!empresa->funcionarioExiste(codigoFunc)){
            cout << "\n(!)---> Não há funcionários com esse código no registro, tente novamente.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }

        printRegistroFuncionario(empresa, codigoFunc);

        if((empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() == "Presidente") ||
        (empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() == "Diretor")){
            cout << "\n(!)---> Esse funcionário não pode ser removido.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }

        cout << "\n---> Funcionário encontrado.\n\n";
        cout << "###################################\n";
        cout << "##   Realmente deseja excluir?   ##\n";
        cout << "###################################\n";
        cout << "##         1 - Confirmar         ##\n";
        cout << "##         2 - Cancelar          ##\n";
        cout << "###################################\n";
        cin >> confirmacao;
        cin.ignore();
        
        switch (confirmacao)
        {
        case 1:
            cout << "\n---> Remoção confirmada.\n";
            empresa->removeFuncionario(codigoFunc);
            cout << "\n---> Funcionário removido com êxito!\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        
        case 2:
            cout << "\n---> Remoção cancelada.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;

        default:
            cout << "\n(!)---> Entrada inválida, remoção cancelada\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }
    }
    case 2:
    {
        int confirmacao;
        cout << "###################################\n";
        cout << "##  Excluir todos os registros?  ##\n";
        cout << "###################################\n";
        cout << "##         1 - Confirmar         ##\n";
        cout << "##         2 - Cancelar          ##\n";
        cout << "###################################\n";
        cin >> confirmacao;
        cin.ignore();

        switch (confirmacao)
        {
        case 1:
            if((empresa->funcionarioExiste("Diretor") || (empresa->funcionarioExiste("Presidente")))){
                cout << "---> Há funcionários que não podem ser excluídos dos registros.\n";
                cout << "---> Retornando ao menu principal.\n";
                cout << "---> Pressione enter para continuar.\n";
                cin.get();
                return;
            }

            cout << "---> Excluindo todos os registros...\n";
            empresa->~Empresa();
            cout << "---> Registros excluídos com êxito.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        
        case 2:
            cout << "\n---> Remoção cancelada.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;

        default:
            cout << "\n(!)---> Entrada inválida, remoção cancelada\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }
    }
    default:
    {
        cout << "(!)---> Entrada inválida, remoção cancelada\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    }
}

void Menu::menuEditarFuncionarios(Empresa* empresa)
{   //primeiro checa se há registros
    if(empresa->getNumDeFuncionarios() == 0){
        cout << "(!)---> Ainda não há registros salvos, sem funcionários para editar.\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }

    int codigoFunc;
    cout << "#################################\n";
    cout << "##       Editar Registro       ##\n";
    cout << "#################################\n";
    cout << "---> Insira o Código do registro a ser editado: \n";
    cout << ">>> Código: ";
    cin >> codigoFunc;
    cin.ignore();
    system("cls");

    if(!empresa->funcionarioExiste(codigoFunc)){
        cout << "(!)---> Não há funcionários com esse código no registro, tente novamente.\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }

    cout << "---> Funcionário Encontrado.\n";
    printRegistroFuncionario(empresa, codigoFunc);
    cout << '\n';
    
    int opcao;
    cout << "######################################\n";
    cout << "##       Qual Atributo Editar?      ##\n";
    cout << "######################################\n";
    cout << "##     1 - Código                   ##\n";
    cout << "##     2 - Data de ingresso         ##\n";
    cout << "##     3 - Nome do Funcionário      ##\n";
    cout << "##     4 - Endereço                 ##\n";
    cout << "##     5 - Telefone do Funcionário  ##\n";
    cout << "##     6 - Designação               ##\n";
    cout << "##     7 - Salário                  ##\n";
    cout << "##     8 - Atributos da designação  ##\n";
    cout << "######################################\n";
    cin >> opcao;
    cin.ignore();
    system("cls");

    printRegistroFuncionario(empresa, codigoFunc);  //pós-cls
    cout << '\n';

    switch (opcao)
    {
    case 1:
    {
        int novoCodigo;

        cout << "######################################\n";
        cout << "##           Editar Código          ##\n";
        cout << "######################################\n";
        cout << "---> Insira o novo código: \n";
        cout << ">>> Código: ";
        cin >> novoCodigo;
        cin.ignore();

        if(empresa->funcionarioExiste(novoCodigo)){
            cout << "\n---> Já existe um funcionário com esse código nos registros, edição cancelada.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }

        empresa->getFuncionarioPorCodigo(codigoFunc)->setCodigo(novoCodigo);
        cout << "\n---> Edição do código feita com sucesso!\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    case 2:
    {
        Data novaData;
        int dia, mes, ano;

        cout << "######################################\n";
        cout << "##      Editar Data de Ingresso     ##\n";
        cout << "######################################\n";
        cout << "---> Insira a nova data de ingresso: \n";
        cout << ">>> Dia: ";
        cin >> dia;
        cout << ">>> Mês (Número): ";
        cin >> mes;
        cout << ">>> Ano: ";
        cin >> ano;
        cin.ignore();

        novaData = Data(dia, mes, ano);
        empresa->getFuncionarioPorCodigo(codigoFunc)->setData(novaData);
        
        cout << "\n---> Edição da data feita com sucesso!\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    case 3:
    {
        string novoNome;

        cout << "######################################\n";
        cout << "##    Editar Nome do Funcionário    ##\n";
        cout << "######################################\n";
        cout << "---> Insira o novo nome: \n";
        cout << ">>> Nome: ";
        getline(cin, novoNome);

        empresa->getFuncionarioPorCodigo(codigoFunc)->setNome(novoNome);
        cout << "\n---> Edição do nome feita com sucesso!\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    case 4:
    {
        Endereco novoEndereco;
        string cidade, bairro, rua;
        int numero;

        cout << "######################################\n";
        cout << "##          Editar Endereço         ##\n";
        cout << "######################################\n";
        cout << "---> Insira o novo endereço: \n";
        cout << ">>> Cidade: ";
        getline(cin, cidade);
        cout << ">>> Bairro: ";
        getline(cin, bairro);
        cout << ">>> Rua: ";
        getline(cin, rua);
        cout << ">>> Número: ";
        cin >> numero;
        cin.ignore();

        novoEndereco = Endereco(cidade, bairro, rua, numero);
        empresa->getFuncionarioPorCodigo(codigoFunc)->setEndereco(novoEndereco);
        cout << "\n---> Edição do endereço feita com sucesso!\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    case 5:
    {
        string novoTelefone;

        cout << "######################################\n";
        cout << "##          Editar Telefone         ##\n";
        cout << "######################################\n";
        cout << "---> Insira o novo telefone: \n";
        cout << ">>> Telefone: ";
        getline(cin, novoTelefone);

        empresa->getFuncionarioPorCodigo(codigoFunc)->setTelefone(novoTelefone);
        cout << "\n---> Edição do telefone feita com sucesso!\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    case 6:
    {
        int copiaCodigo;
        float copiaSalario;
        Data copiaData;
        Endereco copiaEndereco;
        string copiaNome, copiaTelefone;
        string novaDesignacao;

        cout << "######################################\n";
        cout << "##         Editar Designação        ##\n";
        cout << "######################################\n";
        cout << "---> Insira a nova designação do funcionário: \n";
        cout << ">>> Nova designação: ";
        getline(cin, novaDesignacao);

        //validações
        if(!validaDesignacao(novaDesignacao)){
            cout << "\n(!)---> Designacao inserida é inválida, edição cancelada\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }

        //uppercase na designação inserida pelo usuário, necessário caso seja inserida uma em lowercase
        capitalizaDesignacao(novaDesignacao);

        if(novaDesignacao == empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao()){
            cout << "\n(!)---> Funcionário já é dessa designação, edição cancelada.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }

        Funcionario *funcSubstituto;

        //salva os atributos comuns do func com o codigo escolhido
        copiaCodigo = empresa->getFuncionarioPorCodigo(codigoFunc)->getCodigo();
        copiaSalario = empresa->getFuncionarioPorCodigo(codigoFunc)->getSalario();
        copiaData = empresa->getFuncionarioPorCodigo(codigoFunc)->getData();
        copiaEndereco = empresa->getFuncionarioPorCodigo(codigoFunc)->getEndereco();
        copiaNome = empresa->getFuncionarioPorCodigo(codigoFunc)->getNome();
        copiaTelefone = empresa->getFuncionarioPorCodigo(codigoFunc)->getTelefone();

        cout << "\n------> Funcionário... \n";
        //mudança de diretor para outras designações
        if(empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() == "Diretor"){
            string copiaAreaDeSup, copiaAreaDeForm;

            //salva os atributos exclusivos de diretor
            copiaAreaDeSup = ((Diretor*)empresa->getFuncionarioPorCodigo(codigoFunc))->getAreaDeSupervisao();
            copiaAreaDeForm = ((Diretor*)empresa->getFuncionarioPorCodigo(codigoFunc))->getAreaDeFormacao();

            //aqui avalia perda ou ganho de atributos e os preenchem, dependendo da transição feita
            if(novaDesignacao == "Presidente"){
                string formAcadMax;

                cout << "---> Perdeu um atributo: Área de supervisão.\n";
                cout << "---> Ganhou um atributo: Formação acadêmica máxima.\n";
                cout << "\n---> Insira a formação acadêmica máxima: \n";
                cout << ">>> Formação Acadêmica Máxima: ";
                getline(cin, formAcadMax);

                funcSubstituto = new Presidente(copiaCodigo, copiaSalario, copiaNome, copiaTelefone, copiaData, copiaEndereco, copiaAreaDeForm, formAcadMax);
            }
            if(novaDesignacao == "Gerente"){
                cout << "---> Perdeu um atributo: Área de Formação.\n";
                funcSubstituto = new Gerente(copiaCodigo, copiaSalario, copiaNome, copiaTelefone, copiaData, copiaEndereco, copiaAreaDeSup);
            }
            if(novaDesignacao == "Operador"){
                cout << "---> Perdeu dois atributos: Área de Formação e Área de supervisão.\n";
                funcSubstituto = new Operador(copiaCodigo, copiaSalario, copiaNome, copiaTelefone, copiaData, copiaEndereco);
            }
        }

        //mudança de presidente para outras designações
        if(empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() == "Presidente"){
            string copiaAreaDeForm;

            //não precisa copiar formAcadMax
            copiaAreaDeForm = ((Presidente*)empresa->getFuncionarioPorCodigo(codigoFunc))->getAreaDeFormacao();

            if(novaDesignacao == "Diretor"){
                string areaDeSup;

                cout << "---> Perdeu um atributo: Formação Academica Máxima.\n";
                cout << "---> Ganhou um atributo: Área de supervisão.\n";
                cout << "\n---> Insira a área de supervisão: \n";
                cout << ">>> Área de supervisão: ";
                getline(cin, areaDeSup);

                funcSubstituto = new Diretor(copiaCodigo, copiaSalario, copiaNome, copiaTelefone, copiaData, copiaEndereco, areaDeSup, copiaAreaDeForm);
            }
            if(novaDesignacao == "Gerente"){
                string areaDeSup;

                cout << "---> Perdeu dois atributos: Formação Academica Máxima e Área de Formação.\n";
                cout << "---> Ganhou um atributo: Área de supervisão.\n";
                cout << "\n---> Insira a área de supervisão: \n";
                cout << ">>> Área de supervisão: ";
                getline(cin, areaDeSup);

                funcSubstituto = new Gerente(copiaCodigo, copiaSalario, copiaNome, copiaTelefone, copiaData, copiaEndereco, areaDeSup);
            }
            if(novaDesignacao == "Operador"){
                cout << "---> Perdeu dois atributos: Área de Formação e Formação acadêmica máxima.\n";
                funcSubstituto = new Operador(copiaCodigo, copiaSalario, copiaNome, copiaTelefone, copiaData, copiaEndereco);
            }
        }

        //mudança de gerente para outras designações
        if(empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() == "Gerente"){
            string areaDeSup;

            areaDeSup = ((Gerente*)empresa->getFuncionarioPorCodigo(codigoFunc))->getAreaDeSupervisao();

            if(novaDesignacao == "Diretor"){
                string areaDeForm;

                cout << "---> Ganhou um atributo: Área de formação.\n";
                cout << "\n---> Insira a área de formação: \n";
                cout << ">>> Área de formação: ";
                getline(cin, areaDeForm);

                funcSubstituto = new Diretor(copiaCodigo, copiaSalario, copiaNome, copiaTelefone, copiaData, copiaEndereco, areaDeSup, areaDeForm);
            }
            if(novaDesignacao == "Presidente"){
                string areaDeForm, formAcadMax;

                cout << "---> Perdeu um atributo: Área de supervisão.\n";
                cout << "---> Ganhou dois atributos: Área de formação e formação acadêmica máxima.\n";
                cout << "\n---> Insira a área de formação: \n";
                cout << ">>> Área de formação: ";
                getline(cin, areaDeForm);
                cout << "---> Insira a formação acadêmica máxima: \n";
                cout << ">>> Formação acadêmica máxima: ";
                getline(cin, formAcadMax);

                funcSubstituto = new Presidente(copiaCodigo, copiaSalario, copiaNome, copiaTelefone, copiaData, copiaEndereco, areaDeForm, formAcadMax);
            }
            if(novaDesignacao == "Operador"){
                cout << "---> Perdeu um atributo: Área de supervisão.\n";
                funcSubstituto = new Operador(copiaCodigo, copiaSalario, copiaNome, copiaTelefone, copiaData, copiaEndereco);
            }
        }
        
        //mudança de operador para outras designações, não há atributos exclusivos para salvar
        if(empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() == "Operador"){
            if(novaDesignacao == "Diretor"){
                string areaDeSup, areaDeForm;

                cout << "---> Ganhou dois atributos: Área de supervisão e área de formação.\n";
                cout << "\n---> Insira a área de supervisão: \n";
                cout << ">>> Área de Supervisão: ";
                getline(cin, areaDeSup);
                cout << "---> Insira a área de formação: \n";
                cout << ">>> Área de Supervisão: ";
                getline(cin, areaDeForm);

                funcSubstituto = new Diretor(copiaCodigo, copiaSalario, copiaNome, copiaTelefone, copiaData, copiaEndereco, areaDeSup, areaDeForm);
            }
            if(novaDesignacao == "Presidente"){
                string areaDeForm, formAcadMax;

                cout << "---> Ganhou dois atributos: Área de formação e formação acadêmica máxima.\n";
                cout << "\n---> Insira a área de formação: \n";
                cout << ">>> Área de formação: ";
                getline(cin, areaDeForm);
                cout << "---> Insira formação acadêmica máxima: \n";
                cout << ">>> formação acadêmica máxima: ";
                getline(cin, formAcadMax);

                funcSubstituto = new Presidente(copiaCodigo, copiaSalario, copiaNome, copiaTelefone, copiaData, copiaEndereco, areaDeForm, formAcadMax);
            }
            if(novaDesignacao == "Gerente"){
                string areaDeSup;

                cout << "---> Ganhou um atributo: Área de supervisão.\n";
                cout << ">>> Área de Supervisão: ";
                getline(cin, areaDeSup);

                funcSubstituto = new Gerente(copiaCodigo, copiaSalario, copiaNome, copiaTelefone, copiaData, copiaEndereco, areaDeSup);
            }
        }

        empresa->substituirFuncionario(codigoFunc, funcSubstituto);

        cout << "\n---> Edição de designação feita com sucesso!\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    case 7:
    {
        float novoSalario;

        cout << "######################################\n";
        cout << "##          Editar Salario          ##\n";
        cout << "######################################\n";
        cout << "---> Insira o novo salario: \n";
        cout << ">>> Salario: ";
        cin >> novoSalario;
        cin.ignore();

        empresa->getFuncionarioPorCodigo(codigoFunc)->setSalario(novoSalario);
        cout << "\n---> Edição do salário feita com sucesso!\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    case 8:
    {
        int opcao2;

        cout << "############################################\n";
        cout << "##     Editar Atributos da Designação     ##\n";
        cout << "############################################\n";

        //caso func seja diretor
        if(empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() == "Diretor"){
            string areaDeSup, areaDeForm;
            cout << "##          Qual Atributo editar?         ##\n";
            cout << "############################################\n";
            cout << "##          1 - Área de supervisão        ##\n";
            cout << "##          2 - Área de formação          ##\n";
            cout << "############################################\n";
            cin >> opcao2;
            cin.ignore();

            switch (opcao2)
            {
            case 1:
                cout << "\n---> Insira a nova área de supervisão: \n";
                cout << ">>> Nova área de supervisão: ";
                getline(cin, areaDeSup);

                ((Diretor*)empresa->getFuncionarioPorCodigo(codigoFunc))->setAreaDeSupervisao(areaDeSup);
                cout << "\n---> Edição da área de supervisão feita com sucesso!\n";
                cout << "---> Retornando ao menu principal.\n";
                cout << "---> Pressione enter para continuar.\n";
                cin.get();
                return;
            
            case 2:
                cout << "\n---> Insira a nova área de formação: \n";
                cout << ">>> Nova área de formação: ";
                getline(cin, areaDeForm);

                ((Diretor*)empresa->getFuncionarioPorCodigo(codigoFunc))->setAreaDeFormacao(areaDeForm);
                cout << "\n---> Edição da área de formação feita com sucesso!\n";
                cout << "---> Retornando ao menu principal.\n";
                cout << "---> Pressione enter para continuar.\n";
                cin.get();
                return;
            
            default:
                cout << "\n(!)---> Entrada inválida, edição cancelada\n";
                cout << "---> Retornando ao menu principal.\n";
                cout << "---> Pressione enter para continuar.\n";
                cin.get();
                return;
            }
        }

        //caso func seja presidente
        if(empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() == "Presidente"){
            string areaDeForm, formAcadMax;
            cout << "##          Qual Atributo editar?         ##\n";
            cout << "############################################\n";
            cout << "##      1 - Área de formação              ##\n";
            cout << "##      2 - Formação acadêmica máxima     ##\n";
            cout << "############################################\n";
            cin >> opcao2;
            cin.ignore();

            switch (opcao2)
            {
            case 1:
                cout << "\n---> Insira a nova área de formação: \n";
                cout << ">>> Nova área de formação: ";
                getline(cin, areaDeForm);

                ((Presidente*)empresa->getFuncionarioPorCodigo(codigoFunc))->setAreaDeFormacao(areaDeForm);
                cout << "\n---> Edição da área de formação feita com sucesso!\n";
                cout << "---> Retornando ao menu principal.\n";
                cout << "---> Pressione enter para continuar.\n";
                cin.get();
                return;
            
            case 2:
                cout << "\n---> Insira a nova formação acadêmica máxima: \n";
                cout << ">>> Nova formação acadêmica máxima: ";
                getline(cin, formAcadMax);

                ((Presidente*)empresa->getFuncionarioPorCodigo(codigoFunc))->setFormacaoAcademicaMax(formAcadMax);
                cout << "\n---> Edição da área de formação feita com sucesso!\n";
                cout << "---> Retornando ao menu principal.\n";
                cout << "---> Pressione enter para continuar.\n";
                cin.get();
                return;
            default:
                cout << "\n(!)---> Entrada inválida, edição cancelada\n";
                cout << "---> Retornando ao menu principal.\n";
                cout << "---> Pressione enter para continuar.\n";
                cin.get();
                return;
            }
        }

        //caso func seja gerente
        if(empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() == "Gerente"){
            string areaDeSup;
            cout << "##             Editar Atributo            ##\n";
            cout << "############################################\n";
            cout << "##            Área de supervisão          ##\n";
            cout << "############################################\n";

            cout << "\n---> Insira a nova área de supervisão: \n";
            cout << ">>> Nova área de supervisão: ";
            getline(cin, areaDeSup);

            ((Gerente*)empresa->getFuncionarioPorCodigo(codigoFunc))->setAreaDeSupervisao(areaDeSup);
            cout << "\n---> Edição da área de supervisão feita com sucesso!\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }

        //caso func seja operador
        cout << "##         Funcionário é Operador         ##\n";
        cout << "############################################\n";
        cout << "##    (!) Não há atributos exclusivos     ##\n";
        cout << "############################################\n";
        cout << "\n---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    default:
    {
        cout << "\n(!)---> Entrada inválida, edição cancelada\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
    }
}

void Menu::menuExportarImportarArquivo(Empresa* empresa)
{
    int opcao, confirmacao;
    string nomeArquivo;

    cout << "########################################\n";
    cout << "##      Importar/Exportar arquivo     ##\n";
    cout << "########################################\n";
    cout << "##                                    ##\n";
    cout << "##      1 - Importar arquivo CSV      ##\n";
    cout << "##      2 - Exportar arquivo CSV      ##\n";
    cout << "##                                    ##\n";
    cout << "########################################\n";
    cin >> opcao;
    cin.ignore();

    switch (opcao)
    {
    case 1:
        cout << "#############################################################################\n";
        cout << "##   Os registros atuais do programa serão excluídos antes da importação   ##\n";
        cout << "#############################################################################\n";
        cout << "##                               1 - Confirmar                             ##\n";
        cout << "##                               2 - Cancelar                              ##\n";
        cout << "#############################################################################\n";
        cin >> confirmacao;
        cin.ignore();

        switch (confirmacao)
        {
        case 1:
            cout << "\n---> Importação confirmada.\n";
            break;
        
        case 2:
            cout << "\n---> Importação cancelada.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;

        default:
            cout << "\n(!)---> Entrada Inválida.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }

        cout << "\n---> Insira o nome do arquivo a ser importado:\n";
        cout << ">>> Nome do arquivo: ";
        getline(cin, nomeArquivo);

        empresa->importaArquivo(nomeArquivo);
        cout << "\n---> Arquivo importado com êxito.\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        break;

    case 2:
        //primeiro checa se há funcionarios
        if(empresa->getNumDeFuncionarios() == 0){
            cout << "\n(!)---> Ainda não há registros para exportar.\n";
            cout << "---> Retornando ao menu principal.\n";
            cout << "---> Pressione enter para continuar.\n";
            cin.get();
            return;
        }
        cout << "\n---> Insira o nome do arquivo a ser exportado: \n";
        cout << ">>> Nome do arquivo: ";
        getline(cin, nomeArquivo);

        empresa->exportaArquivo(nomeArquivo);
        cout << "\n---> Arquivo exportado com êxito.\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    
    default:
        cout << "(!)---> Entrada Inválida.\n";
        cout << "---> Retornando ao menu principal.\n";
        cout << "---> Pressione enter para continuar.\n";
        cin.get();
        return;
    }
}

void Menu::printRegistroFuncionario(Empresa* empresa, int codigoFunc)
{
    cout << "\n######################################################################################################################################################################################\n";
    cout << "##                                                                              Registro do Funcionário                                                                             ##\n";
    cout << "######################################################################################################################################################################################\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "|  Codigo     |  Nome    |  Salario    |  Telefone    |  Endereco    |  Data de Ingresso   |  Designacao   |  Area de Supervisao   | Area de Formacao   | Formacao Academica Maxima  |\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "| " << empresa->getFuncionarioPorCodigo(codigoFunc)->getCodigo() << " | " << empresa->getFuncionarioPorCodigo(codigoFunc)->getNome() << " | ";
    cout << "R$ " << empresa->getFuncionarioPorCodigo(codigoFunc)->getSalario() << " | " << empresa->getFuncionarioPorCodigo(codigoFunc)->getTelefone() << " | ";
    cout << empresa->getFuncionarioPorCodigo(codigoFunc)->getEndereco().toString() << " | " << empresa->getFuncionarioPorCodigo(codigoFunc)->getData().toString();
    cout << " | " << empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() << " | ";

    if(empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() == "Gerente"){
        cout << ((Gerente*)empresa->getFuncionarioPorCodigo(codigoFunc))->getAreaDeSupervisao() << " | - | - |\n";

    }else if(empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() == "Diretor"){
        cout << ((Diretor*)empresa->getFuncionarioPorCodigo(codigoFunc))->getAreaDeSupervisao() << " | ";
        cout << ((Diretor*)empresa->getFuncionarioPorCodigo(codigoFunc))->getAreaDeFormacao() << " | - |\n";

    }else if(empresa->getFuncionarioPorCodigo(codigoFunc)->getDesignacao() == "Presidente"){
        cout << "- | " << ((Presidente*)empresa->getFuncionarioPorCodigo(codigoFunc))->getAreaDeFormacao() << " | ";
        cout << ((Presidente*)empresa->getFuncionarioPorCodigo(codigoFunc))->getFormacaoAcademicaMax() << " |\n";
    }else{
        cout << "- | - | - |\n";
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "######################################################################################################################################################################################\n";
}

void Menu::printRegistrosFuncionarios(vector<Funcionario*> funcs)
{
    cout << "\n######################################################################################################################################################################################\n";
    cout << "##                                                                        Registro do Funcionário por nome                                                                          ##\n";
    cout << "######################################################################################################################################################################################\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "|  Codigo     |  Nome    |  Salario    |  Telefone    |  Endereco    |  Data de Ingresso   |  Designacao   |  Area de Supervisao   | Area de Formacao   | Formacao Academica Maxima  |\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    for(int i = 0; i < (int)funcs.size(); i++){
        cout << "| " << funcs.at(i)->getCodigo() << " | " << funcs.at(i)->getNome() << " | ";
        cout << "R$ " << funcs.at(i)->getSalario() << " | " << funcs.at(i)->getTelefone() << " | ";
        cout << funcs.at(i)->getEndereco().toString() << " | " << funcs.at(i)->getData().toString();
        cout << " | " << funcs.at(i)->getDesignacao() << " | ";

        if(funcs.at(i)->getDesignacao() == "Gerente"){
            cout << ((Gerente*)funcs.at(i))->getAreaDeSupervisao() << " | - | - |\n";

        }else if(funcs.at(i)->getDesignacao() == "Diretor"){
            cout << ((Diretor*)funcs.at(i))->getAreaDeSupervisao() << " | ";
            cout << ((Diretor*)funcs.at(i))->getAreaDeFormacao() << " | - |\n";

        }else if(funcs.at(i)->getDesignacao() == "Presidente"){
            cout << "- | " << ((Presidente*)funcs.at(i))->getAreaDeFormacao() << " | ";
            cout << ((Presidente*)funcs.at(i))->getFormacaoAcademicaMax() << " |\n";
        }else{
            cout << "- | - | - |\n";
        }
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    cout << "######################################################################################################################################################################################\n";
}

std::string Menu::capitalizaDesignacao(std::string& designacao)
{
    switch(designacao[0])
    {
    case 'd':
        designacao[0] = 'D';
        break;
    case 'p':
        designacao[0] = 'P';
        break;
    case 'g':
        designacao[0] = 'G';
        break;
    case 'o':
        designacao[0] = 'O';
        break;
    default:
        break;
    }
    return designacao;
}

bool Menu::validaDesignacao(string designacao)
{
    if(((designacao == "Diretor") || (designacao == "diretor")) 
    || ((designacao == "Presidente") || (designacao == "presidente")) 
    || ((designacao == "Gerente") || (designacao == "gerente")) 
    || ((designacao == "Operador") || (designacao == "operador"))){
        return true;
    }

    return false;
}