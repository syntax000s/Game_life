#include <fstream> 
#include <string> 



void nul_mas(bool mass[9][9])
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            mass[i][j] = 0;
        }
    }
}
void out_mas(bool mass[9][9])
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            std::cout << ' ' << mass[i][j];
        }
        std::cout << '\n';
    }
}
void zap_mas(bool mass[9][9], std::string name)
{
    std::string buf{};
    std::ifstream ifs;
    ifs.open(name);
    if (ifs.is_open())
    {
        std::cout << "open file\n";
        ifs >> buf;
        ifs.close();
    }
    else {
        std::cout << "error file\n";
        return;
    }

    for (size_t i = 0, b = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            if (buf[b] == '1')
            {
                mass[i][j] = true;
            }
            else {
                mass[i][j] = false;
            }
            if (buf[b] != '|') { b++; }
        }
    }
}

void live(bool mass[9][9])
{
    bool secondmass[9][9]{};
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            secondmass[i][j] = mass[i][j];
        }
    }

    size_t soseds = 0;
    for (size_t i = 1; i < 8; i++)
    {
        for (size_t j = 1; j < 8; j++)
        {
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    if (secondmass[i + x][j + y])
                    {

                        soseds++;
                    }
                    
                }
                
            }
            std::cout << soseds;
            if (soseds==3)
            {
                
                mass[i][j] = true;
                soseds = 0;
            }
            else if(soseds != 2 && soseds != 3)
            {
                mass[i][j] = false;
                soseds = 0;
                
            }
            soseds = 0;
            
        }
        std::cout << '\n';
    }
}


int main()
{
    char name_file[]{ "test.txt" };
    bool mass[9][9]{};
    nul_mas(mass);
    zap_mas(mass, name_file);
    bool end = 0;

    while (!end) {
        out_mas(mass);
        std::cout << "\n\n";
        live(mass);
        std::string ch;
        std::getline(std::cin, ch,' ');
    }

    return 0;
}
