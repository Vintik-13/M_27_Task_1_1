﻿/*Задание 1. Реализация деревни эльфов

Что нужно сделать
Лесные эльфы расположили свою деревню в лесу, прямо на деревьях.
Нужно расселить эльфов по веткам деревьев, а затем подсчитать
общее количество соседей определённого эльфа.
Всего в лесу пять деревьев, каждое из которых генерируется с
помощью случайных чисел, заданных в указанных далее диапазонах.
На каждом дереве есть 3–5 основных больших ветвей. На каждой
большой ветке расположены ещё 2-3 средние ветки. Дома эльфов
построены на больших и на средних ветках. Более мелкие ветви
не рассматриваются в этой задаче.
В начале программы пользователь размещает в каждом доме по одному
эльфу. Делается это с помощью последовательного перебора всех
имеющихся домов и запроса имени заселяемого эльфа через стандартный
ввод. Если было введено None в качестве имени, то дом пропускается
и не заселяется никем.
После этого требуется найти определённого эльфа по имени. Имя
искомого эльфа вводится через стандартный ввод. Для найденного
эльфа нужно вывести общее количество эльфов, живущих вместе с ним
на одной большой ветви. Это и будет искомое количество соседей.*/

#include "Branch.h"

int main()
{
    srand(time(NULL));

    Branch* village = new Branch();

    village->CreatVillage(3);

    village->ShowVillage(false);

    std::cout << std::endl << "Enter the name of the elf: ";

    std::string nameElf{ "" };

    std::getline(std::cin, nameElf);

    Branch* pElf{ nullptr };

    village->SearchElf(nameElf, pElf);

    Branch* nn = village->MainBranch(pElf);

    if (nn == nullptr)
        std::cout << "There is no ilf with that name in the village!" << std::endl;
    else {

        std::cout << "Elf's Neighbors - " << pElf->GetNameElf() << ":" << std::endl;

        nn->ShowVillage(true, pElf->GetNameElf());
    }        
}
