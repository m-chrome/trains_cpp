#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstring>

#include "utilities.hpp"

using namespace std;

namespace utilities {

    bool CheckFile(FILE *filename)
    //проверка файла на успешное открытие
    //при ошибке вернуть false
    {
        if (!filename)
        {
            fputs("Failed to open file!", stderr);
            return false;
        }
        return true;
    }
}
