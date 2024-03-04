#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QListWidget>
#include <QtNetwork/QNetworkReply>

#include <QList>
#include <QString>
#include <QTextDocument>
#include <QTextCursor>
#include <QPrinter>
#include <QPrintPreviewDialog>
class Medicament
{
private:
 QString nom;
  int id,quantite;
float prix;
public:
  //constructeurs
   Medicament(){};
  Medicament(int,QString,int, float);
  //getters
  QString getNom(){return nom;}
  int getQuantite(){return quantite;}
   float getPrix(){return prix;}
  int getID (){return id;}
  //setters
  void setNom(QString n){nom=n;}
   void setQuantite(int q){this ->quantite=q;}
   void setID(int id){this ->id=id;}
    void setPrix(float prix){this ->prix=prix;}
//fonctionnalités de base relatives a l entite medicaments
   bool ajouter();
   QSqlQueryModel * afficher ();
   bool supprimer (int);
   bool modifier(int );

   bool verification_id(int);

  // void toDoList(QListWidget* toDoListWidget);
   QSqlQueryModel* trie_prix();
     QSqlQueryModel* trie_ID();
QSqlQueryModel* trie_Quantite();

 void send_sms(const QString& api_key, const QString& api_secret, const QString& from_number, const QString& to_number, const QString& message);
QSqlQueryModel* recherche_id(int ID);
QSqlQueryModel* recherche_nom(QString nom);
QSqlQueryModel*  recherche_quantite(int quantite);

void afficherCouponSomme(QList<Medicament> medicaments);
void loadInitialData();
void handleReply(QNetworkReply* reply);
int calculerNoteMoyenne() const ;
QSqlQueryModel* getModel();
/*QSqlQueryModel* getModel1();
QSqlQueryModel* getModel2();*/
/*bool ajouterNote(int note) {
      if (note < 1 || note > 5) {
          return false; // La note doit être entre 1 et 5
      }
      int nbVotes = quantite; // quantite contiendra le nombre total de votes
      float sommeNotes = prix; // prix contiendra la somme des notes
      float noteMoyenne = (sommeNotes + note) / (nbVotes + 1); // Calculer la nouvelle note moyenne
      setQuantite(nbVotes + 1); // Mettre à jour le nombre total de votes
      setPrix(noteMoyenne); // Mettre à jour la note moyenne
      return true;
  }*/

/*void ajouterTache(QString date, QString tache, bool terminee, QString deadline);
  void afficherToDoList();*/
};
#endif // MEDICAMENT_H
