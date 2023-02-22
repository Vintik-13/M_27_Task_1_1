#include "Branch.h"

int CountBranch(const int min, const int max) {

    assert(min >= 0 && max >= 0);
    return min + (rand() % (max - min + 1));
}

std::string Branch::GetNameElf() {

    return this->nameElf;
}

#ifdef _DEMONSTRATION_
bool NameNone() {

    return 0 + (rand() % 2);
}
#endif // !_DEMONSTRATION_

#ifdef _DEMONSTRATION_
void Branch::NameBranch(Branch* tmp, int& prefixTree, int& prefixBranch) {

    if (this->parent == nullptr) {
        tmp->nameBranch = "Tree " + std::to_string(prefixTree);
        prefixTree++;
    }
    else {
        tmp->nameBranch = this->nameBranch + " - " + std::to_string(prefixBranch);
        if (::NameNone())
            tmp->nameElf = "None";
        else {
            tmp->nameElf = "Elf(" + tmp->nameBranch + ")";
        }
        prefixBranch++;
    }
}

void Branch::CreatVillage(int level) {

    if(level <= 0)
        return;

    int countBranch{ 0 };

    if (this->parent == nullptr) {
        countBranch = COUNT_TREE;
    }
    else if (this->parent->parent == nullptr) {
        countBranch = ::CountBranch(BIG_BRANCH_MIN, BIG_BRANCH_MAX);
    }
    else {
        countBranch = ::CountBranch(ANOTHER_BRANCH_MIN, ANOTHER_BRANCH_MAX);
    }

    for (int i = 0; i < countBranch; i++) {

        Branch* tmp = new Branch();

        this->NameBranch(tmp, prefixTree, prefixBranch);

        tmp->parent = this;

        this->childs.insert(std::pair<std::string, Branch*>(tmp->nameElf, tmp));
    }

    level--;

    prefixBranch = 1;

    for (BranchIt it = this->childs.begin(); it != childs.end(); it++) {
        it->second->CreatVillage(level);
    }
}

#endif // !_DEMONSTRATION_

#ifndef _DEMONSTRATION_

void Branch::NameBranch(Branch* tmp, int& prefixTree, int& prefixBranch) {

    if (this->parent == nullptr) {
        tmp->nameBranch = "Tree " + std::to_string(prefixTree);
        prefixTree++;
    }
    else {
        tmp->nameBranch = this->nameBranch + " - " + std::to_string(prefixBranch);

        std::string nameElf{ "" };

        std::cout << "Branch - " << this->nameBranch << " Enter the name of the elf: ";
        std::getline(std::cin, nameElf);

        tmp->nameElf = nameElf;
    }
}

void Branch::CreatVillage(int level) {

    if (level <= 0)
        return;

    int countBranch{ 0 };    

    if (this->parent == nullptr) {
        countBranch = COUNT_TREE;
    }
    else if (this->parent->parent == nullptr) {
        countBranch = ::CountBranch(BIG_BRANCH_MIN, BIG_BRANCH_MAX);
    }
    else {
        countBranch = ::CountBranch(ANOTHER_BRANCH_MIN, ANOTHER_BRANCH_MAX);
    }    

    for (int i = 0; i < countBranch; i++) {

        Branch* tmp = new Branch();

        this->NameBranch(tmp, prefixTree, prefixBranch);

        tmp->parent = this;

        this->childs.insert(std::pair<std::string, Branch*>(tmp->nameElf, tmp));
    }

    level--;

    prefixBranch = 1;

    for (BranchIt it = this->childs.begin(); it != childs.end(); it++) {
        it->second->CreatVillage(level);
    }
}
#endif // !_DEMONSTRATION_

std::string Branch::Indent() {

    std::string sTmp{ "" };

    Branch* pTmp{ nullptr };

    pTmp = this->parent;

    while (pTmp) {
        sTmp += "|--";
        pTmp = pTmp->parent;
    }
    return sTmp;
}

void Branch::ShowBranch(std::string indent, bool none, std::string mainElf) {

    if (none) {
        if (this->nameElf == "None" || this->nameElf == mainElf)
            return;
    }

    std::cout << std::endl;

    if (this->parent == nullptr)
        std::cout << indent << "NAME BRANCH - " << this->nameBranch <<
                               ", NAME ELF - " << this->nameElf <<
                               ", (PARENT - No name)" << std::endl;
    else
        std::cout << indent << "NAME BRANCH - " << this->nameBranch << 
                               ", NAME ELF - " << this->nameElf <<
                               ", (PARENT - " << parent->nameElf << ")" << std::endl;

    //std::cout << indent << "Number of descendants: " << this->childs.size() << std::endl;
}

void Branch::ShowVillage(bool none, std::string mainElf) {

    if (this == nullptr) {

        std::cout << "There is no data to output!" << std::endl;
        return;
    }

    std::string tmp{ "" };

    this->ShowBranch(this->Indent(), none, mainElf);

    if (this->childs.size() == 0)
        return;

    for (BranchIt it = this->childs.begin(); it != this->childs.end(); it++)
        it->second->ShowVillage(none, mainElf);
}

void Branch::SearchElf(std::string name, Branch*& tmp) {    

    BranchIt it = this->childs.find(name);

    if (it != this->childs.end())
        tmp = it->second;    

    for (BranchIt it1 = this->childs.begin(); it1 != this->childs.end(); it1++) {

        it1->second->SearchElf(name, tmp);

        if (tmp != nullptr)
            break;
    }
}

Branch* Branch::MainBranch(Branch* elf) {
    
    Branch* mainBranch{ nullptr };

    if (elf == nullptr)
        return nullptr;

    if (elf->parent->parent->parent == nullptr) {
        mainBranch = elf;
        return mainBranch;
    }
    else {
        elf = elf->parent;
        mainBranch = this->MainBranch(elf);
        return mainBranch;
    }
}


