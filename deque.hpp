#ifndef DEQUE_HPP
#define DEQUE_HPP

//Класс дека поезда с содержанием данных и функций-членов (методов)

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstring>

namespace deque {

    using std::size_t;

    class Deque
    {
        private:

            size_t *wagons;
            //Массив вагонов поезда

            size_t N_used;
            //Число используемой памяти

            size_t N_allocated;
            //Число выделенной памяти

            size_t max;
            //Счетчик номеров, присваимваемых новым вагонам

            void ExpandMemory(size_t num);
            //Метод расширения памяти

        public:

            Deque();
            //Конструктор класса Deque, инициализирующий начальные данные дека

            ~Deque();
            //Деструктор класса Deque, удаляющий массив вагонов

            void PushBack(size_t num);
            /*добавление n вагонов в конец поезда с порядковыми номерами,
             *последовательно назначенными по внутреннему счётчику*/

            void PushFront(size_t num);
            /*добавление n вагонов в начало поезда с порядковыми номерами,
             *последовательно назначенными по внутреннему счётчику*/

            bool PopBack(size_t num);
            //удаление n вагонов из конца поезда

            bool PopFront(size_t num);
            //удаление n вагонов из начала поезда

            void PrintResult(FILE *output) const;
            //вывод данных о последовательности вагонов поезда в консоль и файл
    };
}

#endif // DEQUE_HPP

