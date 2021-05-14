#include <iostream>
#include <fstream>
#include <cstring>
#include <list>
#include <iterator>
using namespace std;
ifstream f ("data.in");
ofstream g ("data.out");
class Animal
{
    static int numar_animale;
public:
    virtual ~Animal(){};
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
    Nevertebrate &operator= (Nevertebrate &nevertebrat)
    {
        strcpy(specie, nevertebrat.getspecie());
        return *this;
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
    Pesti &operator= (Pesti &peste)
    {
        strcpy(specie, peste.getspecie());
        settip("peste");
        return *this;
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
    Pasari &operator= (Pasari &pasare)
    {
        strcpy(specie, pasare.getspecie());
        settip("pasare");
        return *this;
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
    Mamifere &operator= (Mamifere &mamifer)
    {
        strcpy(specie, mamifer.getspecie());
        settip("mamifer");
        return *this;
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
    Reptile &operator= (Reptile &reptila)
    {
        strcpy(specie, reptila.getspecie());
        settip("reptila");
        return *this;
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

template <class T>
class Nod
{
    T animal;
    char fisa_animal[10001];
    Nod *next;
public:
    Nod(T ceva)
    {
        animal = ceva;
        next = nullptr;
    }
    Nod()
    {
        next = nullptr;
    }
    Nod operator= (Nod nod)
    {
        delete next;
        next = nod.next;
        animal = nod.animal;
        fisa_animal = nod.fisa_animal;
        return *this;
    }
    friend istream& operator>> (istream &in, Nod &nod)
    {
        T aminal;
        char fisa[10001];
        in >> aminal;
        in >> fisa;
        nod.Setanimal(aminal);
        nod.Setfisa_animal(fisa);
        return in;
    }
    friend ostream& operator<< (ostream &out, Nod &nod)
    {
        out<<nod.animal<<'\n'<<nod.fisa_animal<<'\n';
        return out;
    }
    Nod *Getnext(){return next;}
    T Getanimal(){return animal;}
    void Setanimal(T aux){animal = aux;}
    char *Getfisa_animal(){return fisa_animal;}
    void Setfisa_animal(char aux[10001]){strcpy(fisa_animal,aux);}
    void Setnext(Nod *ceva){next = ceva;}
};

template <class T>
class AtlasZoologic
{
    int n;
    Nod<T> *p;
    Nod<T> *u;
public:
AtlasZoologic()
{
    n = 0;
    p = new Nod<T>;
    u = p;
}
AtlasZoologic(const AtlasZoologic &atlas)
{
    n = atlas.n;
    p = atlas.p;
    u = p;
    Nod<T> *i;
    i = atlas.p;
    while(i != nullptr)
    {
        i = i -> i.Getnext();
        u -> Setnext(i);
        u = u -> u.Getnext();
    }
}
~AtlasZoologic() {
    Nod<T> *i;
    i = p;
    Nod<T> *j;
    while (n != 0) {
        j = i;
        i = i->Getnext();
        delete j;
        --n;
    }
}
friend istream& operator>>(istream &in, AtlasZoologic &atlas)
{
    Nod<T> *i;
    i = atlas.p;
    Nod<T> *j;
    while (i != nullptr && atlas.n != 0)
    {
        j = i;
        i = i -> Getnext();
        delete j;
        atlas.n --;
    }
    atlas.citire();
    return in;
}

friend ostream& operator<<(ostream &out, AtlasZoologic &atlas)
{
    atlas.afiseaza();
    return out;
}
void citire() //o problema aici
    {
        cin >> n;
        int contor;
        T animal;
        Nod<T> i;
        char fisa[10001];
        for(contor = 1; contor <= n; ++contor)
        {
            //cin >> i;
            cin >> animal;
            cin >> fisa;
            adauga(animal,fisa);
        }
    }
    void afiseaza()
    {
        Nod<T> *i;
        i = p;
        int nr = n;
        T animal;
        while(i != nullptr && nr!=0)
        {
            cout<<*i;
//            cout << i -> Getanimal() << '\n';
//            cout << i -> Getfisa_animal();
            i = i -> Getnext();
            nr--;
        }
    }

void adauga(T animal, char fisa[10001], bool creste_n = false)
    {
        Nod<T> *aux;
        aux = new Nod<T>;
        aux -> Setanimal(animal);
        aux -> Setfisa_animal(fisa);
        if(n == 0)
        {
            n = 1;
            p = aux;
            u = p;
        }
        else
        {
            u -> Setnext(aux);
            u = u -> Getnext();
        }
        if(creste_n)
            ++n;
    }

    void operator+=(Nod<T> nod)
    {
        adauga(nod.Getanimal(),nod.Getfisa_animal(),true);
    }

    Nod<T> *Getp(){return p;}
    int Getn(){return n;}
};

class PestiRapitori : public Pesti //e testat totul merge
{
    double lungime;
    static int nr_pesti_rapitori_mari;
public:
    PestiRapitori(){lungime = 0;
        Increasenumar_animale();}
    PestiRapitori(double l)
    {
        lungime = l;
        Increasenumar_animale();
        if(l > 1)
            nr_pesti_rapitori_mari++;
    }
    PestiRapitori(PestiRapitori &peste)
    {
       lungime = peste.lungime;
       if(lungime > 1)
           nr_pesti_rapitori_mari++;
       Increasenumar_animale();
    }
    PestiRapitori &operator=(PestiRapitori &peste)
    {
        lungime = peste.lungime;
        if(lungime > 1)
            nr_pesti_rapitori_mari++;
        return *this;
    }
    void citire()
    {
        Pesti :: citire();
        cin >> lungime;
        if(lungime > 1)
            nr_pesti_rapitori_mari++;
    }
    void afisare()
    {
        Pesti :: afisare();
        cout << " lumgime: " << lungime<<"\n";
        cout << "Exista " << nr_pesti_rapitori_mari <<" pesti rapitori mai mari de 1 m";
    }
    static int Getnr_pesti_rapitori_mari(){return nr_pesti_rapitori_mari;}
};
int PestiRapitori :: nr_pesti_rapitori_mari = 0;
int main() {
    int nr, i, ok;
    char tip[30], ceva[30];
    list <Animal*> lista;
    Animal *animal;

//    Nevertebrate *nevertebrat;
//    Nod<Mamifere> aminal;
//    cin>>aminal;
//    AtlasZoologic<Mamifere> atlas;
//    cin >> atlas;
//    atlas += aminal;
//    cin >> aminal;
//    atlas += aminal;
//    cout<<atlas;
    cin>>nr;
    for(i = 1; i <= nr; ++i)
    {
        ok = 1;
        try
        {
            cin >> tip;
            if(strcmp(tip,"mamifer") == 0)
                animal = new Mamifere;
            else
                throw(tip);
        }
        catch(...)
        {
            try {
                if (strcmp(tip, "pasare") == 0)
                    animal = new Pasari;
                else
                    throw (tip);
            }
            catch(...)
            {
                try{
                    if(strcmp(tip,"peste") == 0)
                        animal = new Pesti;
                    else
                        throw (tip);
                }
                catch(...)
                {
                    try{
                        if(strcmp(tip,"peste_rapitor") == 0)
                            animal = new PestiRapitori;
                        else
                            throw(tip);
                    }
                    catch(...) {
                        try {
                            if (strcmp(tip, "reptila") == 0)
                                animal = new Reptile;
                            else
                                throw (tip);
                        }
                        catch(...)
                        {
                            try {
                                if (strcmp(tip, "nevertebrat") == 0) {
                                    animal = new Nevertebrate;
                                    animal->Increasenumar_animale();
                                }
                                else
                                    throw (tip);
                            }
                            catch(...) {
                                cout << "Regn animal necunoscut!\n";
                                --i;
                                ok = 0;
                            }
                        }
                    }
                }
            }
        }
        if(ok) {
            cin >> *animal;
            lista.push_back(animal);
        }
        else
            cin >> ceva;
    }

    for (list<Animal*>::iterator it=lista.begin(); it != lista.end(); ++it)
        cout<<**it<<'\n';

    int comanda;
    cout << "0.Exit\n" << "1.Adauga un element in lista\n" <<"2.Afiseaza numarul de animale din lista \n";
    cout << "3. Afiseaza numarul de pesti rapitori!\n";
    cout << "Alege comanda dorita: ";
    while(cin >> comanda) {

        if(comanda == 0)
            break;
        else
        if (comanda == 1) {
            cout << "Elementul pe care vrei sa il adaugi este(tip si denumire separate cu space): ";
            for(i = 1; i <= 1; ++i)
            {
                ok = 1;
                try
                {
                    cin >> tip;
                    if(strcmp(tip,"mamifer") == 0)
                        animal = new Mamifere;
                    else
                        throw(tip);
                }
                catch(...)
                {
                    try {
                        if (strcmp(tip, "pasare") == 0)
                            animal = new Pasari;
                        else
                            throw (tip);
                    }
                    catch(...)
                    {
                        try{
                            if(strcmp(tip,"peste") == 0)
                                animal = new Pesti;
                            else
                                throw (tip);
                        }
                        catch(...)
                        {
                            try{
                                if(strcmp(tip,"peste_rapitor") == 0)
                                    animal = new PestiRapitori;
                                else
                                    throw(tip);
                            }
                            catch(...) {
                                try {
                                    if (strcmp(tip, "reptila") == 0)
                                        animal = new Reptile;
                                    else
                                        throw (tip);
                                }
                                catch(...)
                                {
                                    try {
                                        if (strcmp(tip, "nevertebrat") == 0) {
                                            animal = new Nevertebrate;
                                            animal->Increasenumar_animale();
                                        }
                                        else
                                            throw (tip);
                                    }
                                    catch(...) {
                                        cout << "Regn animal necunoscut!\n";
                                        --i;
                                        ok = 0;
                                    }
                                }
                            }
                        }
                    }
                }
                if(ok) {
                    cin >> *animal;
                    lista.push_back(animal);
                }
                else
                    cin >> ceva;
            }
            cout << "Acum lista este: ";
            for (list<Animal*>::iterator it=lista.begin(); it != lista.end(); ++it)
                cout<<**it<<" : ";
            cout<<'\n';
        }
        else
            if(comanda == 2)
            {
                cout << "Numarul animalelor este: " << (animal -> Getnumar_animale()) / 2<<'\n';
            }
            else
                if(comanda == 3)
                    cout<<"Numarul de pesti rapitori de lungime mai mare de 1m este: " << dynamic_cast<PestiRapitori*>(animal) -> Getnr_pesti_rapitori_mari()<<'\n';
                else
                    cout << "Comanda invalida!\n";
        cout << "Alege inca o comanda: " ;
    }
    return 0;
}
