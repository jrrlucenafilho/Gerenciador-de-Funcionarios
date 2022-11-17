#include <fstream>

#define SEC_COMB 13

void EasterEgg()
{
    std::ifstream fp;
    std::string line;

    fp.open("img/easterEgg.txt");

    while(true){

        if(fp.eof()){
            break;
        }

        getline(fp, line);
        std::cout << line << '\n';
    }
}