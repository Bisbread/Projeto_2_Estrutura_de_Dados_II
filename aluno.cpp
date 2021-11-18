#include "aluno.h"

    Aluno::Aluno()
    {
        ID = -1;
        Name = " ";
        
    }

    Aluno::Aluno(int Id, string Nm)
    {  
        ID = Id;
        Name = Nm;
        
    }

    int Aluno::obterID()
    {
        return ID;
    };

    string Aluno::obterName()
    {
      return Name;
    };