#include <iostream>
using namespace std;

class Aluno{
    private:
    int ID;
    string Name;

    public:
    Aluno();
    Aluno(int Id, string Nm);

    int obterID();
    string obterName();
};