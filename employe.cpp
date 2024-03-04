#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QImage>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QLabel>
#include<QSqlRecord>
#include<QBuffer>
#include <QSqlTableModel>
#include <QTableView>
#include <QItemDelegate>
#include <QSqlError>
#include <QMessageBox>
Employe::Employe(int id,QString nom, QString prenom,int age,int num,QString role,QString mdp,QByteArray image,QString imagePath )
{
   this->id=id;
   this->num=num;
    this->age=age;
    this->nom=nom;
    this->prenom=prenom;
    this->role=role;
    this->mdp=mdp;
    this->image=image;
    this->imagePath = imagePath;

}

bool Employe::ajouter()
{
    QSqlQuery query;

    QByteArray byteArray;
        // Charger l'image en mémoire
        if (!imagePath.isEmpty()) {
            QImage image(imagePath);
            if (image.isNull()) {
                qDebug() << "Impossible de charger l'image.";
                return false;
            }
            QBuffer buffer(&byteArray);
            buffer.open(QIODevice::WriteOnly);
            image.save(&buffer, "PNG");
            buffer.open(QIODevice::WriteOnly);
            image.save(&buffer, "PNG");
        }

        QString res= QString::number(id);
        QString ages= QString::number(age);
        QString numer= QString::number(num);

        query.prepare("INSERT INTO EMPLOYES3(id, nom, prenom, age, num, role, mdp, image) "
                      "VALUES (:id, :nom, :prenom, :age, :num, :role, :mdp, :image)");
        query.bindValue(":id", res);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":age", ages);
        query.bindValue(":num", numer);
        query.bindValue(":role", role);
        query.bindValue(":mdp", mdp);
        query.bindValue(":image", image);

        return query.exec();
    }


bool Employe::modifier(int id)
 {
     QString res=QString::number(id);
     QString numer=QString::number(num);
     QString ages=QString::number(age);
     QSqlQuery query;
           query.prepare("UPDATE EMPLOYES3 SET nom=:nom,prenom=:prenom,age=:age,num=:num,role=:role,mdp=:mdp WHERE id=:id");
           query.bindValue(":id",res);
           query.bindValue(":nom",nom);
           query.bindValue(":prenom", prenom);
           query.bindValue(":age",ages);
           query.bindValue(":num",numer);
           query.bindValue(":ROLE",role);
           query.bindValue(":mdp",mdp);
     if(id!=0 || num !=0 || age!=0 || prenom!="" || nom!="" )
          return query.exec();
     return 0;

 }
bool Employe::verification_id(int id)
 {
     QSqlQuery query;
         QString n;
         QString  numid = QString::number(id);
                 query.exec("SELECT ID from EMPLOYES3");
                 while (query.next())
                 {
                     n=query.value("ID").toString();
                     if (n==numid)
                     {
                         return true;
                     }
                 }
         return false;


 }

QSqlTableModel * Employe ::afficher()
{
   QSqlTableModel* model=new QSqlTableModel();
   model->setTable("EMPLOYES3");
   model->select();
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("mdp"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Image"));
       QTableView* view = new QTableView;
       view->setModel(model);
       view->setColumnHidden(6, true); // masquer la colonne MDP
       view->resizeColumnsToContents();
       QItemDelegate* delegate = new QItemDelegate();
       view->setItemDelegateForColumn(7, delegate);
  return model;
}




bool Employe ::supprimer(int id)
{
   QSqlQuery query;
   QString res=QString::number(id);
   query.prepare("Delete from EMPLOYES3 where id= :id");
   query.bindValue(":id",res);
   return query.exec();
}
QSqlQueryModel* Employe ::trie_age()
{
  QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("SELECT * FROM EMPLOYES3 ORDER BY AGE " );
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("num"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("role"));
  return  model;

}
QSqlQueryModel* Employe ::trie_role()
{
  QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("SELECT * FROM EMPLOYES3 ORDER BY ROLE " );
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("num"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("role"));
  return  model;

}
QSqlQueryModel* Employe ::trie_nom()
{
  QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("SELECT * FROM EMPLOYES3 ORDER BY NOM " );
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("num"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("role"));
  return  model;

}
QSqlQueryModel* Employe :: recherche_id(int id)
{

QSqlQuery query;
QString k=QString::number(id);
 query.prepare("SELECT * FROM EMPLOYES3 where id= :id");
 query.bindValue(":id",k);
 query.exec();
 QSqlQueryModel *model=new QSqlQueryModel();
 query.bindValue(":id", k);
     if (!query.exec()) {
         qDebug() << "Failed to execute query: " << query.lastError().text();
         return model;
     }
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("mdp"));
 model->setHeaderData(7, Qt::Horizontal, QObject::tr("Image"));
    return  model;

}
QSqlQueryModel* Employe :: recherche_nom(QString nom)
{

QSqlQuery query;
 query.prepare("SELECT * FROM EMPLOYES3 where nom = :nom");
 query.bindValue(":nom",nom);
 query.exec();
 QSqlQueryModel *model=new QSqlQueryModel();

 if (!query.exec()) {
     qDebug() << "Failed to execute query: " << query.lastError().text();
     return model;
 }
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("mdp"));
 model->setHeaderData(7, Qt::Horizontal, QObject::tr("Image"));
    return  model;

}
QSqlQueryModel* Employe :: recherche_prenom(QString prenom)
{

QSqlQuery query;
 query.prepare("SELECT * FROM EMPLOYES3 where prenom = :prenom");
 query.bindValue(":prenom",prenom);
 query.exec();
 QSqlQueryModel *model=new QSqlQueryModel();
 if (!query.exec()) {
     qDebug() << "Failed to execute query: " << query.lastError().text();
     return model;
 }
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("mdp"));
 model->setHeaderData(7, Qt::Horizontal, QObject::tr("Image"));
    return  model;

}
QSqlQueryModel* Employe ::displayClause(QString cls)
{
   QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("SELECT *FROM EMPLOYES3 " +cls);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("mdp"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Image"));
   return  model;

}
int Employe::authentification(QString user,QString mdp)
 {
     QSqlQuery query;
     QMessageBox msg;
     int i=0;
     QString r;

     query.prepare(QString("select * from EMPLOYES3 WHERE id=:id AND mdp=:mdp"));
     query.bindValue(":id",user);
     query.bindValue(":mdp",mdp);
     query.exec();
     while(query.next())
     {
         QString IdFromDB=query.value("id").toString();
         QString MdpFromDB=query.value("mdp").toString();
         if(user==IdFromDB && mdp==MdpFromDB)
         {  r=query.value("ROLE").toString(); i=1;}


     }
     if (i==0)
        {
         msg.setText("error!  mot de passe ou identifiant incorrecte!");
         msg.exec();
         }
       else{

            if(r=="employe")
                i=2;

            }


     return i;
}
