#ifndef Employe_H
#define Employe_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QStandardItemModel>
#include <QSqlTableModel>


class Employe
{ private:
 QString nom, prenom,role,mdp,imagePath;
  int id,age,num;
  QByteArray image;
public:
  //constructeurs
  Employe(){}
  Employe(int,QString,QString,int,int,QString,QString,QByteArray,QString);
  //getters
  int getID (){return id;}
    int getnum (){return num;}
    int getage (){return age;}
  QString getNom(){return nom;}
   QString getprenom(){return prenom;}
    QString getrole(){return role;}
      QString getmdp(){return mdp;}
      QByteArray getimage(){ return image;}
      QString getImagePath() { return imagePath; }

  //setters
    void setID(int id){this ->id=id;}
       void setnum(int num){this ->num=num;}
          void setage(int age){this ->age=age;}

  void setNom(QString n){nom=n;}
   void setPrenom(QString p){prenom=p;}
     void setrole(QString r){role=r;}
     void setmdp(QString m){mdp=m;}
     void setimage(QByteArray img) { image = img; }
        void setImagePath(QString path) { imagePath = path; }



//fonctionnalités de base relatives a l entite Employe
   bool ajouter();
QSqlTableModel *  afficher();
   bool modifier(int);
     bool verification_id(int id);
   bool supprimer (int);
  QSqlQueryModel * trie_age();
  QSqlQueryModel * trie_role();
  QSqlQueryModel * trie_nom();
QSqlQueryModel*  recherche_id(int id);
QSqlQueryModel*  recherche_nom(QString nom);
QSqlQueryModel*  recherche_prenom(QString prenom);
QSqlQueryModel* displayClause(QString cls);
int authentification(QString user,QString mdp);
};
#endif // Employe_H
