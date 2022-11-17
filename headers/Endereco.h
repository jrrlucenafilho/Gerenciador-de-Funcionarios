#ifndef ENDERECO_H
#define ENDERECO_H

#pragma once

#include <string>

class Endereco
{
    public:
        Endereco();
        Endereco(std::string cidade, std::string bairro, std::string rua, int numero);
        ~Endereco();

        std::string getCidade();
        std::string getBairro();
        std::string getRua();
        int getNumero();

        void setCidade(std::string cidade);
        void setBairro(std::string bairro);
        void setRua(std::string rua);
        void setNumero(int numero);

        std::string toString();


    private:
        std::string cidade, bairro, rua;
        int numero;

};

#endif