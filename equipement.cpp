#include "equipement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QPdfWriter>
#include<QMessageBox>
#include<QSystemTrayIcon>
#include<QPainter>
#include <QTextDocument>

#include<QDesktopServices>

Equipement::Equipement(int id,QString nom, int quantite,float prix)
{
   this->id=id;
   this->nom=nom;
   this->quantite=quantite;
   this->prix=prix;
}

bool Equipement::ajouter()
{ QSqlQuery query;
  QString res= QString::number(id);
  QString res_1= QString::number(quantite);
  QString res_2= QString::number(prix);


  query.prepare("INSERT INTO EQUIPEMENTS (id , nom , quantite , prix) "
                "VALUES (:id, :nom, :quantite , :prix)");
             query.bindValue(":id",res);
             query.bindValue(":nom",nom);
             query.bindValue(":quantite", res_1);
             query.bindValue(":prix", res_2);
    return query.exec();
}
QSqlQueryModel * Equipement ::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM EQUIPEMENTS ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

  return model;
}
bool Equipement ::supprimer(int id)
{
   QSqlQuery query;
   QString res=QString::number(id);
   query.prepare("Delete from EQUIPEMENTS where id= :id");
   query.bindValue(":id",res);
   return query.exec();
}


bool Equipement::verification_id(int id)
{
QSqlQuery query;
QString n;
QString numid = QString::number (id);
query.exec ("SELECT ID from EQUIPEMENTS");
while (query.next())
{
n=query.value ("ID").toString();
if (n==numid)
{
return true;
}
}
return false;
}

bool Equipement::modifier(int id)
 {
     QString res=QString::number(id);
     QString res1=QString::number(quantite);
     QString res2=QString::number(prix);
     QSqlQuery query;
           query.prepare("UPDATE EQUIPEMENTS SET nom=:nom,quantite=:quantite,prix=:prix WHERE id=:id");
           query.bindValue(":id",res);
           query.bindValue(":nom",nom);
           query.bindValue(":quantite", res1);
           query.bindValue(":prix", res2);

           if(id !=0 || nom!=""|| quantite!=0|| prix!=0)
                    return query.exec();
               return 0;

 }

void Equipement::genererPDF()
{
    QPdfWriter pdf("C:/Users/zghal/Download/Validation Finale/integration_V1 N+W+S+B+A/integration_V1 N+W+S+B+A/integration_V1 N+W+S+B/liste.pdf");
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setPageOrientation(QPageLayout::Portrait);

    QPainter painter(&pdf);

    int i = 4000;
    painter.setPen(QColor(16, 78, 139)); //bleu marine
    painter.setFont(QFont("Times New Roman", 25, QFont::Bold)); //changement de font et agrandissement
    painter.drawText(2000,1300,"Liste Des Equipements");
    // Add image to the PDF
    QImage image("C:/Users/zghal/Downloads/Validation Finale/integration_V1 N+W+S+B+A/integration_V1 N+W+S+B+A/integration_V1 N+W+S+B/MeDispatch Main Logo 800x600");
    if (!image.isNull()) {
        QRectF imageRect(150, 500, 1200, 1200);
        painter.drawImage(imageRect, image);

    //designer la page
    QRectF rectangle(80, 550, 9500, 3200);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(QColor(200,200,200,50)));
    painter.drawRect(rectangle);

    QRectF rectangle2(80, 3700, 9500, 500);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(QColor(200,200,200,50)));
    painter.drawRect(rectangle2);

    painter.setPen(QColor(16, 78, 139)); //bleu marine
    painter.setFont(QFont("Times New Roman", 11, QFont::Bold)); //changement de font et agrandissement
    painter.drawText(200,3300,"ID");
    painter.drawText(1200,3300,"Nom");
    painter.drawText(2000,3300,"Quantite");
    painter.drawText(3200,3300,"Prix");


    }

    QSqlQuery query;
    query.prepare("select * from EQUIPEMENTS");
    query.exec();
    while (query.next())
    {
        painter.setPen(QColor(16, 78, 139)); //bleu marine
        painter.setFont(QFont("Arial", 10)); //changement de font
        painter.drawText(200,i,query.value(0).toString());
        painter.drawText(1300,i,query.value(1).toString());
        painter.drawText(2200,i,query.value(2).toString());
        painter.drawText(3200,i,query.value(3).toString());

        i = i + 500;
    }

    int reponse = QMessageBox::Yes;
    if (reponse == QMessageBox::Yes)
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();
        notifyIcon->setIcon(QIcon("C:/Users/zghal/Downloads/integration_V1 N+W+S+B+A/integration_V1 N+W+S+B+A/integration_V1 N+W+S+B/icon"));

        notifyIcon->showMessage("GESTION DES  EQUIPEMENTS ","Liste des EQUIPEMENTS prete dans PDF",QSystemTrayIcon::Information,15000);

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }

}

QSqlQueryModel* Equipement::rechercherf (const QString &aux)

{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("select id, nom, quantite, prix from EQUIPEMENTS where ((id || nom || quantite || prix ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


    return model;
}












