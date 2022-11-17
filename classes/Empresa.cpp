#include "Empresa.h"

using namespace std;

Empresa::Empresa()
{

}

Empresa::~Empresa()
{
    for(int i = 0; i < getNumDeFuncionarios(); i++){
        delete funcionarios.at(i);
    }
    
    funcionarios.clear();
}

Funcionario* Empresa::getFuncionario(int index)
{
    return funcionarios.at(index);
}

Funcionario* Empresa::getFuncionarioPorCodigo(int codigo)
{
    Funcionario *func;

    for(int i = 0; i < getNumDeFuncionarios(); i++){
        if(getFuncionario(i)->getCodigo() == codigo){
            func = funcionarios.at(i);
            break;  //pois não há dois funcionários com o mesmo código
        }
    }

    return func;
}

void Empresa::addFuncionario(Funcionario* func)
{
    funcionarios.push_back(func);
}

void Empresa::removeFuncionario(Funcionario* func)
{
    for(int i = 0; i < getNumDeFuncionarios(); i++){
        if(funcionarios.at(i) == func){
            delete funcionarios.at(i);
            funcionarios.erase(funcionarios.begin() + i);
            break;
        }
    }
}

void Empresa::removeFuncionario(int codigo)
{
    for(int i = 0; i < getNumDeFuncionarios(); i++){
        if(funcionarios.at(i)->getCodigo() == codigo){
            delete funcionarios.at(i);
            funcionarios.erase(funcionarios.begin() + i);
            break;
        }
    }
}

vector<Funcionario*> Empresa::filtrarPorDesignacao(string designacao)
{
    vector<Funcionario*> funcsFiltrado;

    for(int i = 0; i < getNumDeFuncionarios(); i++){
        if(funcionarios.at(i)->getDesignacao() == designacao){
            funcsFiltrado.push_back(funcionarios.at(i));
        }
    }

    return funcsFiltrado;
}

vector<Funcionario*> Empresa::filtrarPorNome(std::string nome)
{
    vector<Funcionario*> funcs;

    for(int i = 0; i < getNumDeFuncionarios(); i++){
        if(funcionarios.at(i)->getNome().find(nome) != string::npos){
            funcs.push_back(funcionarios.at(i));
        }
    }

    return funcs;
}

int Empresa::getNumDeFuncionarios()
{
    return (int)funcionarios.size();
}

void Empresa::importaArquivo(string nomeArquivo)
{
    fstream fp;
    string strCodigo, nome, strSalario, telefone, designacao, areaSup, areaForm, formAcadMax; 
    string cidade, bairro, rua, strNumero;
    string strDia, strMes, strAno;
    float salario;
    int codigo, numero, dia, mes, ano;
    Data data;
    Endereco endereco;
    Funcionario *func;

    Empresa::~Empresa();

    if(nomeArquivo.find(".csv") == string::npos){
        nomeArquivo += ".csv";
    }

    nomeArquivo = "out/" + nomeArquivo;

    fp.open(nomeArquivo, fstream::in);

    if(!fp.is_open()){
        return;
    }

    fp.ignore(127, '\n');

    while(true){

        if(fp.eof()){
            break;
        }
        
        getline(fp, strCodigo, ';');
        getline(fp, nome, ';');
        getline(fp, strSalario, ';');
        getline(fp, telefone, ';');

        getline(fp, cidade, ',');
        getline(fp, bairro, ',');
        getline(fp, rua, ',');
        getline(fp, strNumero, ';');

        getline(fp, strDia, '/');
        getline(fp, strMes, '/');
        getline(fp, strAno, ';');
        getline(fp, designacao, ';');

        codigo = stoi(strCodigo);
        salario = stof(strSalario);
        numero = stoi(strNumero);
        dia = stoi(strDia);
        mes = stoi(strMes);
        ano = stoi(strAno);

        data = Data(dia, mes, ano);
        endereco = Endereco(cidade, bairro, rua, numero);

        if(designacao == "Diretor"){
            getline(fp, areaSup, ';');
            getline(fp, areaForm, ';');
            fp.ignore(4, '\n');
            func = new Diretor(codigo, salario, nome, telefone, data, endereco, areaSup, areaForm);
        }
        if(designacao == "Gerente"){
            getline(fp, areaSup, ';');
            fp.ignore(8, '\n');
            func = new Gerente(codigo, salario, nome, telefone, data, endereco, areaSup);
        }
        if(designacao == "Presidente"){
            fp.ignore(4, ';');
            getline(fp, areaForm, ';');
            getline(fp, formAcadMax);

            func = new Presidente(codigo, salario, nome, telefone, data, endereco, areaForm, formAcadMax);
        }
        if(designacao == "Operador"){
            fp.ignore(12, '\n');
            func = new Operador(codigo, salario, nome, telefone, data, endereco);
        }
        fp >> ws;
        funcionarios.push_back(func);
    }
}

void Empresa::exportaArquivo(string nomeArquivo)
{
    fstream fp;

    if(nomeArquivo.find(".csv") == string::npos){
        nomeArquivo += ".csv";
    }

    nomeArquivo = "out/" + nomeArquivo;

    fp.open(nomeArquivo, fstream::out);
    if(!fp.is_open()){
        return;
    }
    
    fp << "Codigo;Nome;Salario;Telefone;Endereco;Data De Ingresso;Designacao;Area de Supervisao;Area de Formacao;Formacao Academica Maxima\n";
    for(int i = 0; i < getNumDeFuncionarios(); i++){
        fp << getFuncionario(i)->getCodigo() << ';' << getFuncionario(i)->getNome() << ';' 
           << getFuncionario(i)->getSalario() << ';' << getFuncionario(i)->getTelefone() << ';'
           << getFuncionario(i)->getEndereco().toString() << ';' << getFuncionario(i)->getData().toString() << ';'
           << getFuncionario(i)->getDesignacao() << ';';

        if(getFuncionario(i)->getDesignacao() == "Gerente"){
            fp << ((Gerente*)getFuncionario(i))->getAreaDeSupervisao() << "; - " << "; - " << endl;

        }else if(getFuncionario(i)->getDesignacao() == "Diretor"){
            fp << ((Diretor*)getFuncionario(i))->getAreaDeSupervisao() << ';' << ((Diretor*)getFuncionario(i))->getAreaDeFormacao()
               << "; - " << endl;
       
        }else if(getFuncionario(i)->getDesignacao() == "Presidente"){
            fp << " - ;" << ((Presidente*)getFuncionario(i))->getAreaDeFormacao() << ';' << ((Presidente*)getFuncionario(i))->getFormacaoAcademicaMax()
               << endl;
        
        }else{
            fp << " - ; - ; - " << endl;
        }
    }

    fp.close();
}

void Empresa::substituirFuncionario(int codigo, Funcionario* funcSubstituto)
{
    for(int i = 0; i < getNumDeFuncionarios(); i++){
        if(funcionarios.at(i)->getCodigo() == codigo){
            delete funcionarios.at(i);
            funcionarios.at(i) = funcSubstituto;
            break;
        }
    }
}

vector<Funcionario*> Empresa::getTodosOsFuncionarios()
{
    return funcionarios;
}

bool Empresa::funcionarioExiste(int codigo)
{
    for(int i = 0; i < getNumDeFuncionarios(); i++){
        if(getFuncionario(i)->getCodigo() == codigo){
            return true;
        }
    }
    return false;
}

bool Empresa::funcionarioExiste(std::string designacao)
{
    for(int i = 0; i < getNumDeFuncionarios(); i++){
        if(getFuncionario(i)->getDesignacao() == designacao){
            return true;
        }
    }
    return false;
}
