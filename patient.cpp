#include "patient.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QtGui>
#include <QObject>
#include <QSqlError>
#include <QMessageBox>

patient::patient()
{

    age=0; nom=" "; prenom=" ";  cin=" ";     date = QDate();

    }
    patient::patient(int age ,QString nom,QString prenom,QString cin, QDate date){
    this->age=age;
    this->nom=nom;
    this->prenom=prenom;
        this->cin=cin;
this->date=date;

    }
    int patient::getage(){return age;}
    QString patient::getnom(){return nom;}
    QString patient::getprenom(){return prenom;}
    QString patient::getcin(){return cin;}
    QDate patient::getDate() const {
        return date;
    }
    void patient::setage(int age){
        this->age=age;
    }
    void patient::setnom(QString nom){

        this->nom=nom;

    }
    void patient::setprenom(QString prenom){

        this->prenom=prenom;


    }
    void patient::setcin(QString cin){

        this->cin=cin;


    }


    bool patient::isAgeValid(int age) {
        return age >= 0 && age <= 150;
    }
    bool patient::isNameValid(const QString &nom) {
        QRegExp regex("^[A-Za-zÀ-ÿ]+(?:\\s+[A-Za-zÀ-ÿ]+)*$");
        return regex.exactMatch(nom);
    }
    bool patient::isprenomValid(const QString &prenom) {
        QRegExp regex("^[A-Za-zÀ-ÿ]+(?:\\s+[A-Za-zÀ-ÿ]+)*$");
        return regex.exactMatch(prenom);
    }
    bool patient::ajouter()
    {
        if (!isNameValid(nom)) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur : Le nom saisi est invalide.\nCliquez sur Annuler pour quitter."),
                                  QMessageBox::Cancel);
            return false;
        }
        if (!isNameValid(prenom)) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur : Le prénom saisi est invalide.\nCliquez sur Annuler pour quitter."),
                                  QMessageBox::Cancel);
            return false;
        }
        if (!isAgeValid(age)) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur : L'âge saisi est invalide.\nCliquez sur Annuler pour quitter."),
                                  QMessageBox::Cancel);
            return false;
        }


        QString age_string = QString::number(age);
        QSqlQuery query;

        query.prepare("SELECT COUNT(*) FROM PATIENT WHERE cin = ?");
        query.addBindValue(cin);
        query.exec();

        if (query.next() && query.value(0).toInt() > 0)
        {
            QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Error: Patient with the same cin already exists.\nClick Cancel to exit."), QMessageBox::Cancel);
            return false;
        }

        query.prepare("INSERT INTO PATIENT (cin, nom, prenom, age, date_ajout) VALUES (:id, :forename, :surname, :age, TO_DATE(:date_ajout, 'YYYY-MM-DD'))");
        query.bindValue(":id", cin);
        query.bindValue(":forename", nom);
        query.bindValue(":surname", prenom);
        query.bindValue(":age", age_string);
        query.bindValue(":date_ajout", date.toString("yyyy-MM-dd"));

        bool success = query.exec();

        if (!success)
        {
            QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Error: Failed to insert new patient record.\nClick Cancel to exit."), QMessageBox::Cancel);
        }

        return success;
    }

    QSqlQueryModel* patient::afficher()
    {
        QSqlQueryModel* model = new QSqlQueryModel;
        model->setQuery("SELECT cin, nom, prenom, age, TO_CHAR(date_ajout, 'YYYY-MM-DD') as date_ajout FROM PATIENT");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("penom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date ajout"));
        return model;
    }






    bool patient::supprimer(QString cin) {
        QSqlQuery query;

        query.prepare("SELECT COUNT(*) FROM PATIENT WHERE cin = ?");
        query.addBindValue(cin);
        query.exec();

        if (query.next() && query.value(0).toInt() == 0) {
            QMessageBox::critical(nullptr, QObject::tr("Error"),
                QObject::tr("Error: No patient with the given cin exists.\nClick Cancel to exit."), QMessageBox::Cancel);
            return false;
        }

        query.prepare("DELETE FROM PATIENT WHERE cin = :id");
        query.bindValue(":id", cin);

        bool success = query.exec();

        if (!success) {
            QMessageBox::critical(nullptr, QObject::tr("Error"),
                QObject::tr("Error: Failed to delete patient record.\nClick Cancel to exit."), QMessageBox::Cancel);
        }

        return success;
    }



    bool patient::modifier(QString cin, QString nom, QString prenom, int age) {
        if (!isNameValid(nom)) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur : Le nom saisi est invalide.\nCliquez sur Annuler pour quitter."),
                                  QMessageBox::Cancel);
            return false;
        }
        if (!isNameValid(prenom)) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur : Le prénom saisi est invalide.\nCliquez sur Annuler pour quitter."),
                                  QMessageBox::Cancel);
            return false;
        }
        if (!isAgeValid(age)) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur : L'âge saisi est invalide.\nCliquez sur Annuler pour quitter."),
                                  QMessageBox::Cancel);
            return false;
        }
        QSqlQuery query;

        query.prepare("SELECT COUNT(*) FROM PATIENT WHERE cin = ?");
        query.addBindValue(cin);
        query.exec();

        if (query.next() && query.value(0).toInt() == 0) {
            QMessageBox::critical(nullptr, QObject::tr("Error"),
                QObject::tr("Error: No patient with the given cin exists.\nClick Cancel to exit."), QMessageBox::Cancel);
            return false;
        }

        query.prepare("UPDATE PATIENT SET nom=:nom, prenom=:prenom, age=:age WHERE cin=:cin");
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":age", age);
        query.bindValue(":cin", cin);

        bool success = query.exec();

        if (!success) {
            QMessageBox::critical(nullptr, QObject::tr("Error"),
                QObject::tr("Error: Failed to update patient record.\nClick Cancel to exit."), QMessageBox::Cancel);
        }

        return success;
    }

    QSqlQueryModel* patient::refreshModel()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM PATIENT");
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("Cin"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("age"));
        return model;
    }
    QSqlQueryModel* patient::tri_age_asc()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM PATIENT ORDER BY age ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
        return model;
    }
    QSqlQueryModel* patient::tri_cin_asc()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM PATIENT ORDER BY cin ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
        return model;
    }
    QSqlQueryModel* patient::tri_nom_asc()
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM patient ORDER BY nom ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Cin"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
        return model;
    }

    QSqlQueryModel* patient::getPatientByCin(QString cin) {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(QString("SELECT * FROM patient WHERE cin ILIKE '%1'").arg(cin));
        return model;
    }
    int patient::countByAgeRange(int minAge, int maxAge)
    {
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM PATIENT WHERE age >= :minAge AND age <= :maxAge");
        query.bindValue(":minAge", minAge);
        query.bindValue(":maxAge", maxAge);
        query.exec();
        query.next();
        return query.value(0).toInt();
    }
    QVariantList patient::toVariantList() const
    {
        QVariantList row;
        row << QVariant(age) << QVariant(nom) << QVariant(prenom) << QVariant(cin);
        return row;
    }
