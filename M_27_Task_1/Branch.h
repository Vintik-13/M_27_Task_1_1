#pragma once

//#define _DEMONSTRATION_

#include <map>
#include <string>
#include <iostream>
#include <cassert>

class Branch;

using BranchMap = std::multimap<std::string, Branch*>;
using BranchIt = std::multimap<std::string, Branch*>::iterator;

//Константы формитрования количества деревьев, больших ветвей и остальных ветвей
const int COUNT_TREE{ 5 };
const int BIG_BRANCH_MIN{ 3 };
const int BIG_BRANCH_MAX{ 5 };
const int ANOTHER_BRANCH_MIN{ 2 };
const int ANOTHER_BRANCH_MAX{ 3 };

//Статические переменные для автоматической генерации имен ветвей и эльфов
static int prefixTree{ 1 };
static int prefixBranch{ 1 };

//Функция возвращает случайное целое число в диапазоне min - max
int CountBranch(const int min, const int max);

//Функция с 50% долей вероятности возвращает true для случайной генерации пустых домов
#ifdef _DEMONSTRATION_

bool NameNone();

#endif // !_DEMONSTRATION_

class Branch {

    std::string nameBranch; //Не обязательное поле, просто для наглядности

    std::string nameElf;

    Branch* parent;

    BranchMap childs;

    //Автоматическая генерация имени ветки для отладки и визуализации
#ifdef _DEMONSTRATION_

    void NameBranch(Branch* tmp, static int& prefixTree, static int& prefixBranch);

#endif // !_DEMONSTRATION_

#ifndef _DEMONSTRATION_

    void NameBranch(Branch* tmp, static int& prefixTree, static int& prefixBranch);

#endif // !_DEMONSTRATION_

    //Генерация отступа для визуализации веток деревни
    std::string Indent();     

public:

    Branch() : nameBranch{ "Village" }, nameElf{ "No name" }, parent{ nullptr } {}

    std::string GetNameElf();

    //Генерация деревни в режиме демонстрации
#ifdef _DEMONSTRATION_

    void CreatVillage(int level); //Через level регулируется глубина ветвления дерева

#endif // !_DEMONSTRATION_

    //Генерация деревни
#ifndef _DEMONSTRATION_

    void CreatVillage(int level);

#endif // !_DEMONSTRATION_

    //Визуализация ветки, просто для наглядности
    void ShowBranch(std::string indent, bool none, std::string mainElf = "");

    //Визуализация деревни, просто для наглядности
    void ShowVillage(bool none = false, std::string mainElf = "");

    //Поиск имени эльфа
    void SearchElf(std::string name, Branch*& tmp); 

    //Поиск большой ветки
    Branch* MainBranch(Branch* elf); 
};

