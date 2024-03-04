#ifndef AMBULANCE_H
#define AMBULANCE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDialog>
#include <QPushButton>
#include <QObject>
#include <QtCharts>

class Ambulance {
  public:
    Ambulance();
    Ambulance(int, QString, QString, QString);
    int getida();
    void setida(int);
    static bool isMatriculeValid(const QString & matricule);
    QString getmatricule();
    void setmatricule(QString);
    QString getdate_sortie();
    void setdate_sortie(QString);
    QString getdisponibilite();
    void setdisponibilite(QString);
    bool ajouter_ambulance();
    QSqlQueryModel * afficher_ambulance();
    bool supprimer_ambulance(int);
    bool modifier_ambulance(int, QString, QString, QString);
    bool checkDatabase();
    QSqlQuery getAllData(); // Add this line to declare the function
  private:
    int ida;
    QString matricule;
    QString date_sortie;
    QString disponibilite;
    void generateStatistics();
};

#endif // AMBULANCE_H
