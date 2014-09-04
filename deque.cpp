//Файл deque.cpp с определениями функций интерфейса дека

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstring>

#include "deque.hpp"

using namespace std;

namespace deque {

    size_t i;

    Deque::Deque()
    //Конструктор класса Deque, инициалзирующий начальные данные дека
        :
        wagons(nullptr),
        N_used(0),
        N_allocated(0),
        max(0)
    {}

    Deque::~Deque()
    //Деструктор класса Deque
    {
        delete[] wagons;
    }

    void Deque::ExpandMemory(size_t num)
    //расширение памяти под массив вагонов
    {
        N_used += num;
        if ((N_allocated)<(N_used))
        {
            size_t N_cap=1.5*(N_used);
            size_t *wagons1 = new size_t[N_cap];
            memcpy(wagons1, wagons,(N_used-num)*(sizeof(size_t)));
            delete[] wagons;
            wagons=wagons1;
            N_allocated=N_cap;
        }
    }

    void Deque::PushBack(size_t num)
    //добавление n вагонов в конец поезда с порядковыми номерами, последовательно назначенными по внутреннему счётчику
    {
        ExpandMemory(num);
        for(i=N_used-num;i<N_used;++i)
        {
            wagons[i]=++max;
        }
    }

    void Deque::PushFront(size_t num)
    //добавление n вагонов в начало поезда с порядковыми номерами, последовательно назначенными по внутреннему счётчику
    {
        ExpandMemory(num);
        memmove(wagons+num, wagons, N_used*sizeof(size_t));
        for(i=0;i<num;++i)
        {
            wagons[num-1-i]=++max;
        }
    }

    bool Deque::PopBack(size_t num)
    //удаление n вагонов из конца дека d
    {
        if (N_used<num)
        {
            return false;
        }
        N_used -= num;
        return true;
    }

    bool Deque::PopFront(size_t num)
    //удаление n вагонов из начала дека d
    {
        if (N_used<num)
        {
            return false;
        }
        N_used -= num;
        memmove(wagons, wagons+num, N_used*sizeof(size_t));
        return true;
    }


    void Deque::PrintResult(FILE *output) const
    //вывод дека d в поток f
    {
        for(i=0;i<(N_used);++i)
        {
            fprintf(output, "%u ", wagons[i]);
            printf("%u ", wagons[i]);
        }
        printf("\n");
        fprintf(output, "\n");
    }
}
