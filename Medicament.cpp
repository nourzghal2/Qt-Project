#include "Medicament.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QListWidget>
#include <QInputDialog>
 #include <QMessageBox>
//#include <nexmo.hpp>
//#include <NexmoMessage.hpp>
//#include <Nexmo.hpp>
//#include <NexmoMessage.hpp>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QDebug>
#include <QFile>
#include <QTextDocument>
#include <QPrintPreviewDialog>
#include <QPrinter>
#include <QtCore>
#include <QSqlRecord>
#include <QString>


#include <QtGui>
Medicament::Medicament(int id,QString nom, int quantite, float prix)
{
   this->id=id;
   this->nom=nom;
   this->quantite=quantite;
    this->prix=prix;
}

bool Medicament::ajouter()
{
    QSqlQuery query;
  QString res= QString::number(id);
QString res1= QString::number(quantite);
QString res2= QString::number(prix);
      query.prepare("INSERT INTO MEDICAMENT(id, nom, quantite, prix) ""VALUES (:id, :nom, :quantite, :prix)");
             query.bindValue(":id",res);
             query.bindValue(":nom",nom);
             query.bindValue(":quantite", res1);
             query.bindValue(":prix", res2);
    return query.exec();
}
QSqlQueryModel * Medicament ::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM MEDICAMENT ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

  return model;
}
bool Medicament ::supprimer(int id)
{
   QSqlQuery query;
   QString res=QString::number(id);
   query.prepare("Delete from MEDICAMENT where id= :id");
   query.bindValue(":id",res);
   return query.exec();
}


bool Medicament::verification_id(int id)
{
QSqlQuery query;
QString n;
QString numid = QString::number (id);
query.exec ("SELECT ID from MEDICAMENT");
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

bool Medicament::modifier(int id)
 {
     QString res=QString::number(id);
QString des=QString::number(quantite);
QString aes=QString::number(prix);
     QSqlQuery query;
           query.prepare("UPDATE MEDICAMENT SET nom=:nom, quantite=:quantite, prix=:prix WHERE id=:id");
           query.bindValue(":id",res);
           query.bindValue(":nom",nom);
           query.bindValue(":quantite", des);
           query.bindValue(":prix", aes);

     if(id !=0  || nom!="" ||  quantite!=0 ||  prix!=0)
          return query.exec();
     return 0;

 }






QSqlQueryModel* Medicament ::trie_prix()
{
  QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("SELECT * FROM MEDICAMENT ORDER BY PRIX " );
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));

  return  model;

}
QSqlQueryModel* Medicament ::trie_ID()
{
  QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("SELECT * FROM MEDICAMENT ORDER BY ID " );
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));

  return  model;

}
QSqlQueryModel* Medicament ::trie_Quantite()
{
  QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("SELECT * FROM MEDICAMENT ORDER BY quantite " );
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));

  return  model;

}


/*void Medicament::send_sms(const QString& api_key, const QString& api_secret, const QString& from_number, const QString& to_number, const QString& message)
{
    // Convert QStrings to standard C++ strings
    std::string API_KEY = "e38f1398";
       std::string API_SECRET = "yEmMKAMsBq7sxUhB";
       Nexmo::Client nexmo(e38f1398, yEmMKAMsBq7sxUhB);
    std::string api_key_str = api_key.toStdString();
    std::string api_secret_str = api_secret.toStdString();
    std::string from_number_str = from_number.toStdString();
    std::string to_number_str = to_number.toStdString();
    std::string message_str = message.toStdString();

    // Create a Nexmo client object
    nexmo::client client(api_key_str, api_secret_str);

    // Create a Nexmo message object and set the properties
    nexmo::message msg;
    msg.to = to_number_str;
    msg.from = from_number_str;
    msg.text = message_str;

    // Send the message
    nexmo::response res = client.send_message(msg);

    // Check if the message was sent successfully
    if (res.status == nexmo::response::status_type::success) {
        qDebug() << "SMS sent successfully: " << res.message_id.c_str();
    } else {
        qDebug() << "Failed to send SMS: " << res.error_message.c_str();
    }
}*/
QSqlQueryModel* Medicament :: recherche_id(int ID)
{

QSqlQuery query;
QString id=QString::number(ID);
 query.prepare("SELECT * FROM MEDICAMENT where ID = :ID");
 query.bindValue(":ID",ID);
 query.exec();
 QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));

    return  model;

}


QSqlQueryModel* Medicament :: recherche_nom(QString nom)
{

QSqlQuery query;
 query.prepare("SELECT * FROM MEDICAMENT where nom = :nom");
 query.bindValue(":nom",nom);
 query.exec();
 QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));

    return  model;

}

QSqlQueryModel* Medicament :: recherche_quantite(int quantite)
{

QSqlQuery query;
 query.prepare("SELECT * FROM MEDICAMENT where quantite = :quantite");
 query.bindValue(":quantite",quantite);
 query.exec();
 QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));

    return  model;

}


void Medicament::afficherCouponSomme(QList<Medicament> medicaments)
{
    // Calcul de la somme des médicaments
    float somme = 0;
    for (const Medicament& M : medicaments) {
        somme += M.prix * M.quantite;
    }

    // Affichage du coupon
    QTextDocument doc;
    QTextCursor cursor(&doc);
    cursor.insertText("========================================\n");
    cursor.insertText("           COUPON DE COMMANDE           \n");
    cursor.insertText("========================================\n\n");

    // Affichage de chaque médicament
    for (const Medicament& med : medicaments) {
        cursor.insertText(med.nom + "\n");
        cursor.insertText("Prix unitaire : " + QString::number(med.prix) + " euros\n");
        cursor.insertText("Quantité : " + QString::number(med.quantite) + "\n");
        float prixMedicament = med.prix * med.quantite;
        cursor.insertText("Prix total : " + QString::number(prixMedicament) + " euros\n");
        cursor.insertText("\n");
    }

    // Affichage de la somme des médicaments
    cursor.insertText("========================================\n");
    cursor.insertText("Somme totale : " + QString::number(somme) + " euros\n");
    cursor.insertText("========================================\n");

    // Affichage du coupon dans un aperçu d'impression
    QPrinter printer;
    printer.setPrinterName("Nom de l'imprimante");
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Portrait);
    QPrintPreviewDialog preview(&printer);
   QObject::connect(&preview, SIGNAL(paintRequested(QPrinter*)), &doc, SLOT(print(QPrinter*)));
    preview.exec();
}


int Medicament::calculerNoteMoyenne() const {
    if (quantite == 0) {
        return 0; // Si aucun vote n'a été enregistré, la note moyenne est de 0
    }
    float noteMoyenne = round(prix); // Arrondir la note moyenne à l'entier le plus proche
    return static_cast<int>(noteMoyenne); // Convertir la note moyenne en entier et la retourner
}


/*void Medicament::ajouterTache(QString date, QString tache, bool terminee, QString deadline) {
    QList<QString> tacheAfaire;
    tacheAfaire.append(date);
    tacheAfaire.append(tache);
    tacheAfaire.append(terminee ? "oui" : "non");
    tacheAfaire.append(deadline);
    QList<QList<QString>> toDoList;
    toDoList.append(tacheAfaire);
}

void Medicament::afficherToDoList() {
    QList<QList<QString>> toDoList;
    for (int i = 0; i < toDoList.size(); i++) {
        QList<QString> tacheAfaire = toDoList.at(i);
        qDebug() << "Date: " << tacheAfaire.at(0);
        qDebug() << "Tache a faire: " << tacheAfaire.at(1);
        qDebug() << "Terminee: " << tacheAfaire.at(2);
        qDebug() << "Deadline: " << tacheAfaire.at(3);
    }
}
*/


/*void sendSMS(QString phoneNumber, QString message)
{
    // Création de l'objet NetworkAccessManager pour effectuer la requête
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    // Construction de la requête POST avec les paramètres
    QUrl url("https://api.twilio.com/2010-04-01/Accounts/{ AC9d4dfc029eb9feb26e3b77a207a2b160}/Messages.json");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("Authorization", "Basic {123b508c2c1017087e513eded8434ecb}");

    QUrlQuery params;
    params.addQueryItem("From", "{+15076046312}");
    params.addQueryItem("To", phoneNumber);
    params.addQueryItem("Body", message);

    // Envoi de la requête
    QNetworkReply *reply = manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());

    // Gestion de la réponse
    connect(reply, &QNetworkReply::finished, [=]() {
        handleReply(reply);
    });
}
void Medicament::handleReply(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        // Traiter la réponse ici
    } else {
        qDebug() << "Erreur lors de la requête :" << reply->errorString();
    }
    reply->deleteLater();
}*/


QSqlQueryModel* Medicament::getModel() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MEDICAMENT");
    return model;
}

/*QSqlQueryModel* Medicament::getModel1() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT nom FROM MEDICAMENT");
    return model;
}
QSqlQueryModel* Medicament::getModel2() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT quantite FROM MEDICAMENT");
    return model;
}
*/
