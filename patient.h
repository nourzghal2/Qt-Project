#ifndef PATIENT_H
#define PATIENT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QPdfWriter>
#include <QTextDocument>
#include <QFileDialog>
#include <QVariant>
#include <xlsxdocument.h>

class patient
{
public:
    patient();
    patient(int, QString, QString, QString, QDate);
    int getage();
    QString getnom();
    QString getprenom();
    QString getcin();
    QDate getDate() const;

    void setage(int);
    void setnom(QString);
    void setprenom(QString);
    void setcin(QString);
    QDate setDate() const;


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(QString cin, QString nom, QString prenom, int age);
    QSqlQueryModel* refreshModel();
    QSqlQueryModel* tri_age_asc();
    QSqlQueryModel* tri_cin_asc();
    QSqlQueryModel* tri_nom_asc();
    QSqlQueryModel* getPatientByCin(QString cin);
    int countByAgeRange(int minAge, int maxAge);
    QVariantList toVariantList() const;
    static QSqlQueryModel* getPatientsByDate(QDate date);
bool isNameValid(const QString &nom);
bool isprenomValid(const QString &prenom);

bool isAgeValid(int age);
bool isCinValid(const QString &cin);
private:
    int age;
    QString nom, prenom, cin;
    QDate date;
};

#endif // PATIENT_H
