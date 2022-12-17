#include <vector> 
#include <string>
#include <cstring>
#include <bits/stdc++.h>
#include <fstream>
#include <algorithm>
#include <iostream>
#include "Mot.h"
using namespace std;


string Mot::getDefinition() { 
    return this->definition;
}

string Mot::getLabel() { 
    return this->label;
}

ostream& operator<<(ostream& os, Mot &mot)
{
    cout << mot.getLabel() << " = " << mot.getDefinition() << endl;   
    return os;
}

Dictionnaire::Dictionnaire(string file) { 
    string ligne;
    string unused_data; // Pour stocker les donnees non utilisees.
    string label,definition;
    Mot *mot_tmp;
    ifstream fichiersource(file);
    // Elimination de la prmeiere ligne qui contient que la structure du fichier.
    getline(fichiersource,ligne);
    while(getline(fichiersource,ligne))
    { 
        stringstream check(ligne);
        // Eliminer word_id, non utilisee
        getline(check,unused_data,',');
        // Stockage de "word"
        getline(check,label,',');
        // Elimination de up_votes, down_votes, author
        getline(check,unused_data,',');
        getline(check,unused_data,',');
        getline(check,unused_data,',');
        // Stockage de definition
        getline(check,definition,',');
        mot_tmp = new Mot(label,definition);
        this->mots.push_back(*mot_tmp);
    }

}

void Dictionnaire::ajouterMot(Mot mot) { 
    this->mots.push_back(mot);
}

vector<Mot> Dictionnaire::getMots(){
    vector<Mot> tmp;
    for(vector<Mot>::iterator i = this->mots.begin() ; i != this->mots.end() ; i++)
        tmp.push_back(*i);
    return tmp;
}

void Dictionnaire::rechercherMot(string label){ 
    for (int i = 0; i < this->mots.size() ; i++)
    {
        if(this->mots[i].getLabel() == label)
        { 
            cout << this->mots[i] << endl;
            return;
        }
    } 
}

Mot* Dictionnaire::rechercherMot(int indice) { 
    Mot *tmp = new Mot(this->mots[indice].getLabel(),this->mots[indice].getDefinition());
    return tmp;
}

int main() 
{  
    Dictionnaire *mondictionnaire = new Dictionnaire("source1.txt");
    Mot *nvmot = mondictionnaire->rechercherMot(0);
    cout << *nvmot;
    mondictionnaire->rechercherMot("yayeeyay");
    
}