#include "ambulance.h"

#include <QString>

#include <QSqlDatabase>

#include <QSqlError>

#include <QSqlQuery>

#include<QSqlQueryModel>

#include <QMessageBox>

#include <QRegExp>

#include <QVBoxLayout>

bool Ambulance::isMatriculeValid(const QString & matricule) {
  QRegExp matriculeRegExp("^[0-9]{2,}[A-Z]{2}[0-9]{4}$");
  return matriculeRegExp.exactMatch(matricule);
}

Ambulance::Ambulance() {
  ida = 0;
  matricule = " ";
  date_sortie = ""; // Change from 0 to empty QString
  disponibilite = " ";
}
Ambulance::Ambulance(int ida, QString matricule, QString date_sortie, QString disponibilite) {
  this -> ida = ida;
  this -> matricule = matricule;
  this -> date_sortie = date_sortie;
  this -> disponibilite = disponibilite;
}

int Ambulance::getida() {
  return ida;
}
void Ambulance::setida(int ida) {
  this -> ida = ida;
}

QString Ambulance::getmatricule() {
  return matricule;
}
void Ambulance::setmatricule(QString matricule) {
  this -> matricule = matricule;
}

QString Ambulance::getdisponibilite() {
  return disponibilite;
}
void Ambulance::setdisponibilite(QString disponibilite) {
  this -> disponibilite = disponibilite;
}

QString Ambulance::getdate_sortie() {
  return date_sortie;
}
void Ambulance::setdate_sortie(QString date_sortie) {
  this -> date_sortie = date_sortie;
}

bool Ambulance::ajouter_ambulance() {

  // Check if all inputs are not empty
  if (ida == 0 || matricule.isEmpty() || date_sortie.isEmpty() || disponibilite.isEmpty()) {
    return false;
  }

  // Check if matricule already exists
  QSqlQuery checkQuery;
  checkQuery.prepare("SELECT ida FROM Ambulance WHERE matricule=:matricule");
  checkQuery.bindValue(":matricule", matricule);
  if (checkQuery.exec() && checkQuery.next()) {
    // matricule already exists, cannot add ambulance
    return false;
  }
  // If matricule does not exist, proceed with adding ambulance
  QSqlQuery query;
  QString id_string = QString::number(ida);

  // Convert matricule to uppercase
  QString matricule_upper = matricule.toUpper();
  // Validate matricule format and convert to uppercase
  if (!isMatriculeValid(matricule)) {
    return false;
  }

  query.prepare("INSERT INTO AMBULANCE (ida,matricule,date_sortie,disponibilite) "
    "VALUES (:ida, :matricule, :date_sortie, :disponibilite)");
  query.bindValue(":ida", id_string);
  query.bindValue(":matricule", matricule_upper);
  query.bindValue(":date_sortie", date_sortie);
  query.bindValue(":disponibilite", disponibilite);

  return query.exec();

}
bool Ambulance::supprimer_ambulance(int ida) {
  /*
   QSqlQuery query;
   QString id_string = QString::number(ida);
   query.prepare("Delete from AMBULANCE where ida=:ida");
   query.bindValue(0, id_string);
   return query.exec();
   */
  QSqlQuery query;
  QString id_string = QString::number(ida);
  query.prepare("SELECT * FROM AMBULANCE WHERE ida=:ida");
  query.bindValue(0, id_string);
  if (query.exec() && query.next()) {
    query.prepare("DELETE FROM AMBULANCE WHERE ida=:ida");
    query.bindValue(0, id_string);
    return query.exec();
  } else {
    return false;
  }

}

void Ambulance::generateStatistics()
{

    // Create a new dialog window
        QDialog *dialog = new QDialog();

        // Set the window title
        dialog->setWindowTitle("Statistics");
        dialog->setFixedSize(QSize(800, 600));
        // Define the width and height of the chart
        int width = 800;
        int height = 600;

        // Create a chart object
        QChart chart;

        // Set the chart title
        chart.setTitle("Type de Donateurs");

        // Create a pie series and add it to the chart
        QPieSeries *series = new QPieSeries();

        // Query the database to get the data for the chart
        QSqlQuery query;
        query.prepare("SELECT DISPONIBILITE, COUNT(*) FROM Ambulance GROUP BY DISPONIBILITE");
        if(query.exec())
        {
            int total = 0;
            while(query.next())
            {
                // Get the type and count for the current row
                QString type = query.value(0).toString();
                int count = query.value(1).toInt();

                // Add the type and count to the series
                series->append(type, count);

                // Increment the total count
                total += count;
            }

            // Set the series as the data source for the chart
            chart.addSeries(series);

            // Set the chart legend to show the percentage values
            QPieSlice *slice;
            foreach(slice, series->slices()) {
                slice->setLabel(QString("%1\n%2%").arg(slice->label()).arg(100 * slice->percentage(), 0, 'f', 1));
            }

            // Create a chart view and set its size
            QChartView *chartView = new QChartView(&chart, dialog);
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->resize(width, height);

            // Create a layout for the dialog window and add the chart view widget to it
            QVBoxLayout *layout = new QVBoxLayout();
            layout->addWidget(chartView);
            dialog->setLayout(layout);
        }

        // Show the dialog window
        dialog->exec();



}


bool Ambulance::modifier_ambulance(int ida, QString matricule, QString date_sortie, QString disponibilite) {

  // Check if all inputs are not empty
  if (ida == 0 || matricule.isEmpty() || date_sortie.isEmpty() || disponibilite.isEmpty()) {
    return false;
  }

  // Check if new matricule already exists (other than for the ambulance being modified)
  QSqlQuery checkQuery;
  checkQuery.prepare("SELECT ida FROM Ambulance WHERE matricule=:matricule AND ida<>:ida");
  checkQuery.bindValue(":matricule", matricule);
  checkQuery.bindValue(":ida", ida);
  if (checkQuery.exec() && checkQuery.next()) {
    // matricule already exists, cannot modify ambulance
    return false;
  }
  // If new matricule does not exist, proceed with modifying ambulance

  QSqlQuery query;
  QString id_string = QString::number(ida);

  // Check if ida exists
  query.prepare("SELECT * FROM Ambulance WHERE ida=:ida");
  query.bindValue(":ida", id_string);
  if (!query.exec() || !query.next()) {
    // Record with given ida not found
    return false;
  }
  // Convert matricule to uppercase
  QString matricule_upper = matricule.toUpper();
  // Validate matricule format and convert to uppercase
  if (!isMatriculeValid(matricule)) {
    return false;
  }
  // If ida exists, perform the update
  query.prepare("UPDATE Ambulance SET ida=:ida, matricule=:matricule, date_sortie=:date_sortie, disponibilite=:disponibilite WHERE ida=:ida");
  query.bindValue(":ida", id_string);
  query.bindValue(":matricule", matricule_upper);
  query.bindValue(":date_sortie", date_sortie);
  query.bindValue(":disponibilite", disponibilite);
  return query.exec();
}


QSqlQuery Ambulance::getAllData() {
  QSqlQuery query;
  query.prepare("SELECT * FROM Ambulance");
  query.exec();
  return query;
}



QSqlQueryModel * Ambulance::afficher_ambulance() {
  QSqlQueryModel * model = new QSqlQueryModel();

  model -> setQuery("SELECT* FROM Ambulance");
  model -> setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
  model -> setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
  model -> setHeaderData(7, Qt::Horizontal, QObject::tr("date de sortie"));
  model -> setHeaderData(8, Qt::Horizontal, QObject::tr("disponibilite"));

  return model;
}
