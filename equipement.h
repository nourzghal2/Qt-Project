#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H


#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>



class Equipement
{
private:
 int id;
 QString nom ;
 int quantite;
 float prix;

public:
  //constructeurs
  Equipement(){};
  Equipement(int,QString,int,float);
  //getters
  QString getNom(){return nom;}
  int getQuantite (){return quantite;}
  int getID (){return id;}
  float getPrix(){return prix;}

  //setters
  void setNom(QString n){nom=n;}
  void setQuantite(int n){quantite=n;}
   void setID(int id){this ->id=id;}
   void setPrix(float prix){this->prix=prix;}
//fonctionnalités de base relatives a l entite etudiant
   bool ajouter();
   QSqlQueryModel * afficher ();
   bool supprimer (int);
   bool modifier(int );
   bool verification_id(int);
   void genererPDF();
   bool supprimerf(int);
    QSqlQueryModel * rechercherf (const QString &aux);
};
void on_le_ID_3_textChanged();


#endif // EQUIPEMENT_H
