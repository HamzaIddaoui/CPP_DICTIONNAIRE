#include <string>
#include <vector>
using namespace std;

class Mot { 
   private : 
   string label;
   string definition;

   public : 
   Mot(){};
   Mot(string label, string definition)
   { 
     this->definition = definition;
     this->label = label;
   }
   string getLabel();
   string getDefinition();
   friend ostream& operator<<(ostream& os, const Mot &mot);


};


class Dictionnaire { 
    private : 
    vector<Mot> mots;

    public : 
    Dictionnaire(){};
    Dictionnaire(string file);
    void ajouterMot(Mot mot);
    void rechercherMot(string label);
    Mot* rechercherMot(int indice);
    vector<Mot> getMots();
};