#ifndef DATA_H
#define DATA_H

#pragma once

#include <string>

class Data
{
    public:
        Data();
        Data(int dia, int mes, int ano);
        ~Data();

        int getDia();
        int getMes();
        int getAno();

        void setDia(int novoDia);
        void setMes(int novoMes);
        void setAno(int novoAno);

        std::string toString();

    private:
        int dia, mes, ano;

};

#endif