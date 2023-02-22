#pragma once

//#define _DEMONSTRATION_

#include <map>
#include <string>
#include <iostream>
#include <cassert>

class Branch;

using BranchMap = std::multimap<std::string, Branch*>;
using BranchIt = std::multimap<std::string, Branch*>::iterator;

//��������� ������������� ���������� ��������, ������� ������ � ��������� ������
const int COUNT_TREE{ 5 };
const int BIG_BRANCH_MIN{ 3 };
const int BIG_BRANCH_MAX{ 5 };
const int ANOTHER_BRANCH_MIN{ 2 };
const int ANOTHER_BRANCH_MAX{ 3 };

//����������� ���������� ��� �������������� ��������� ���� ������ � ������
static int prefixTree{ 1 };
static int prefixBranch{ 1 };

//������� ���������� ��������� ����� ����� � ��������� min - max
int CountBranch(const int min, const int max);

//������� � 50% ����� ����������� ���������� true ��� ��������� ��������� ������ �����
#ifdef _DEMONSTRATION_

bool NameNone();

#endif // !_DEMONSTRATION_

class Branch {

    std::string nameBranch; //�� ������������ ����, ������ ��� �����������

    std::string nameElf;

    Branch* parent;

    BranchMap childs;

    //�������������� ��������� ����� ����� ��� ������� � ������������
#ifdef _DEMONSTRATION_

    void NameBranch(Branch* tmp, static int& prefixTree, static int& prefixBranch);

#endif // !_DEMONSTRATION_

#ifndef _DEMONSTRATION_

    void NameBranch(Branch* tmp, static int& prefixTree, static int& prefixBranch);

#endif // !_DEMONSTRATION_

    //��������� ������� ��� ������������ ����� �������
    std::string Indent();     

public:

    Branch() : nameBranch{ "Village" }, nameElf{ "No name" }, parent{ nullptr } {}

    std::string GetNameElf();

    //��������� ������� � ������ ������������
#ifdef _DEMONSTRATION_

    void CreatVillage(int level); //����� level ������������ ������� ��������� ������

#endif // !_DEMONSTRATION_

    //��������� �������
#ifndef _DEMONSTRATION_

    void CreatVillage(int level);

#endif // !_DEMONSTRATION_

    //������������ �����, ������ ��� �����������
    void ShowBranch(std::string indent, bool none, std::string mainElf = "");

    //������������ �������, ������ ��� �����������
    void ShowVillage(bool none = false, std::string mainElf = "");

    //����� ����� �����
    void SearchElf(std::string name, Branch*& tmp); 

    //����� ������� �����
    Branch* MainBranch(Branch* elf); 
};

