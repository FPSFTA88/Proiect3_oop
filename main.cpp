#include <iostream>
#include <fstream>
#include <cstring>
#include <list>
using namespace std;
ifstream f ("ex.in");
ofstream g ("ex.out");
class Animal
{
    static int numar_animale;
public:
    virtual void afisare() = 0;
    virtual void citire() = 0;
    friend ostream& operator << (ostream &out, Animal &aux)
    {
        aux.afisare();
        return out;
    }
    friend istream& operator >> (istream &in, Animal &aux)
    {
        aux.citire();
        return in;
    }
    static int const Getnumar_animale(){return numar_animale;}
    static void Increasenumar_animale(){numar_animale++;}
};

int Animal :: numar_animale = 0;

class Vertebrate: public Animal
{
    char tip[10];
public:
    Vertebrate()
    {
        tip[0] = '\0';
        Increasenumar_animale();
    }
    Vertebrate(char string[10])
    {
        strcpy(tip,string);
        Increasenumar_animale();
    }
    Vertebrate(Vertebrate &vertebrat)
    {
        strcpy(tip,vertebrat.gettip());
        Increasenumar_animale();
    }
    char const *gettip(){return tip;}
    void settip(char string[10]){strcpy(tip,string);}
    void afisare()
    {
        cout << tip <<" ";
    }
    void citire()
    {
        cin >> tip;
    }

    Vertebrate &operator= (Vertebrate &vertebrat)
    {
        strcpy(tip,vertebrat.gettip());
        return *this;
    }
};

class Nevertebrate: public Animal
{
    char specie[30];
public:
    Nevertebrate()
    {
        specie[0] = '\0';
        Increasenumar_animale();
    }
    Nevertebrate(char aux[30])
    {
        strcpy(specie,aux);
        Increasenumar_animale();
    }
    Nevertebrate(Nevertebrate &nevertebrat)
    {
        strcpy(specie, nevertebrat.getspecie());
        Increasenumar_animale();
    }

    char const *getspecie(){return specie;}

    void afisare()
    {
        cout << specie;
    }
    void citire()
    {
        cin >> specie;
    }
};

class Pesti: public Vertebrate
{
    char specie[30];
public:
    Pesti ()
    {
        specie[0] = '\0';
        Increasenumar_animale();
        settip("peste");
    }
    Pesti (char aux[30])
    {
        strcpy(specie, aux);
        settip("peste");
        Increasenumar_animale();
    }
    Pesti (Pesti &peste)
    {
        strcpy(specie,peste.getspecie());
        settip("peste");
        Increasenumar_animale();
    }
    char const *getspecie(){return specie;}
    void afisare()
    {
        Vertebrate::afisare();
        cout << specie;
    }
    void citire()
    {
        cin >> specie;
    }
};

class Pasari: public Vertebrate
{
    char specie[30];
public:
    Pasari ()
    {
        specie[0] = '\0';
        settip("pasare");
        Increasenumar_animale();
    }
    Pasari (char aux[30])
    {
        strcpy(specie,aux);
        settip("pasare");
        Increasenumar_animale();
    }
    Pasari (Pasari &pasare)
    {
        strcpy(specie,pasare.getspecie());
        settip("pasare");
        Increasenumar_animale();
    }

    char const *getspecie() { return specie;}

    void afisare()
    {
        Vertebrate::afisare();
        cout << specie;
    }

    void citire()
    {
        cin >> specie;
    }
};

class Mamifere: public Vertebrate
{
    char specie[30];
public:
    Mamifere ()
    {
        specie[0] = '\0';
        settip("mamifer");
        Increasenumar_animale();
    }
    Mamifere (char aux[30])
    {
        strcpy(specie, aux);
        settip("mamifer");
        Increasenumar_animale();
    }
    Mamifere (Mamifere &mamifer)
    {
        strcpy(specie, mamifer.getspecie());
        settip("mamifer");
        Increasenumar_animale();
    }
    char const *getspecie(){ return specie;}
    void afisare()
    {
        Vertebrate::afisare();
        cout << specie;
    }
    void citire()
    {
        cin >> specie;
    }
};

class Reptile: public Vertebrate
{
    char specie[30];
public:
    Reptile ()
    {
        specie[0] = '\0';
        settip("reptila");
        Increasenumar_animale();
    }
    Reptile (char aux[30])
    {
        strcpy(specie,aux);
        settip("reptila");
        Increasenumar_animale();
    }
    Reptile (Reptile &reptila)
    {
        strcpy(specie, reptila.getspecie());
        settip("reptila");
        Increasenumar_animale();
    }
    char const *getspecie(){return specie;}

    void afisare()
    {
        Vertebrate::afisare();
        cout << specie;
    }
    void citire()
    {
        cin >> specie;
    }
};

int main() {
    int n, i;
    list <Animal*> lista;
    Mamifere *mamifer;
    Nevertebrate *nevertebrat;
    cin>>n;
    for(i = 1; i <= n; ++i)
    {
        mamifer = new Mamifere;
        cin>>*mamifer;
        lista.push_back(mamifer);
    }
    for (auto const &i: lista)
        cout<<*i<<'\n';


    return 0;
}
