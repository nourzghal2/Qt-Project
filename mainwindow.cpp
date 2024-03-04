#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include "equipement.h"
#include <QMessageBox>
#include <QApplication>
#include <QTextDocument>
#include<QtDebug>
#include<QDesktopServices>
#include <QDebug>
#include<QPainter>
#include<QSystemTrayIcon>
#include <QIntValidator>
#include<QString>
#include<QVBoxLayout>
#include<QFileDialog>
#include <QSqlQuery>
#include<QVBoxLayout>
#include <QPieSeries>
#include <QtCharts/QPieSeries>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QtDebug>
#include "patient.h"
#include <QtGui>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>
#include "xlsxdocument.h"
#include <QDesktopServices>
#include <QUrl>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QTextDocument>
#include <QFileDialog>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSqlError>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QSortFilterProxyModel>
#include <QPieSeries>
#include <QChart>
#include <QPieSlice>
#include <QChartView>
#include <QBrush>
#include <QPen>
#include <QDialog>
#include <QFile>
#include <QtCharts/QPieSlice>
#include"notification.h"
#include <QSqlTableModel>

#include <QtCharts/QAbstractSeries>
#include <QtCharts/QPieSlice>
#include <QChartView>
#include<QSqlQuery>
#include<QMessageBox>
#include<QtDebug>
#include<QObject>
#include <QWidget>
#include <QFileDialog>
#include <QTextDocument>
#include <QDebug>
#include <QtPrintSupport/QPrinter>
#include "smtp.h"
#include "employe.h"

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QApplication>
#include <QTimer>
#include <QPrinter>
#include <QSystemTrayIcon>



#include "Medicament.h"
#include <QMessageBox>
#include <QApplication>
#include <QListWidget>
 #include <QMessageBox>
#include <QInputDialog>
//#include <Nexmo.hpp>
//#include <NexmoMessage.hpp>
//#include <NexmoMessage.hpp>
/*#include <curl/curl.h>
#include <openssl/ssl.h>
#include <openssl/err.h>*/

#include <fstream>
#include <QAuthenticator>
#include "addtaskdialog.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
//#include <QSvgRenderer>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QApplication>
#include <QPrinter>
#include <QLabel>

#include<QDateEdit>
#include "tache.h"
#include "webaxwidget.h"


#include <QMessageBox>
#include <QUrl>
#include <QUrlQuery>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QtDebug>
#include "patient.h"
#include <QtGui>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>
#include "xlsxdocument.h"
#include <QDesktopServices>
#include <QUrl>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QTextDocument>
#include <QFileDialog>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSqlError>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QSortFilterProxyModel>
#include <QPieSeries>
#include <QChart>
#include <QPieSlice>
#include <QChartView>
#include <QBrush>
#include <QPen>
#include <QDialog>
#include <QFile>



#include "ambulance.h"
#include <QtWidgets>
#include <QSqlQuery>
#include <QMessageBox>
#include <QPrinter>
#include <QFile>
#include <QFileDialog>
#include <QPainter>
#include <QPdfWriter>
#include <QTextDocument>
#include <QSqlRecord>

#include <Arduino.h>
using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).



    ui -> tab_fH_ -> setModel(am.afficher_ambulance());

    ui -> tableView_15 -> setModel(am.afficher_ambulance());
    QHeaderView *header1 = ui->tab_fH_->horizontalHeader();
    header1->setSectionResizeMode(QHeaderView::Stretch);

    QHeaderView *header2 = ui->tableView_15->horizontalHeader();
    header2->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->A_recherche_6, SIGNAL(textChanged(const QString &)), this, SLOT(on_A_recherche_6_textChanged(const QString &)));


     ui->tabmedi->setModel(M.afficher());
     ui->linecin_NOUR_4->setValidator(new QIntValidator(0, 9999999,this));
    ui->lineEdit_18->setValidator(new QIntValidator(0, 9999999,this));
     ui->modifier_age->setValidator(new QIntValidator(0, 9999999,this));

             ui->modifier_cin->setValidator(new QIntValidator(0, 9999999,this));

     ui->tableView_NOUR_4->setModel(P.afficher());
     m_model_2 = new QSqlQueryModel(this);
         m_model_2->setQuery("SELECT * FROM patient");

        // ui->tableView->setModel(m_model_2);
      date = QDate::currentDate();
      ui->tableView_NOUR_4->setAlternatingRowColors(true);
          ui->tableView_NOUR_4->setStyleSheet("alternate-background-color: #EEEEEE; background-color: #FFFFFF;");
          ui->tableView_NOUR_4->verticalHeader()->setVisible(false);



              ui->tableView_NOUR_4->setMinimumWidth(400);
              ui->searchLineEdit->setMinimumWidth(150);

              ui->refreshButton->setToolTip("Refresh the table");
              ui->tributton->setToolTip("Sort by age ascending");
              ui->radioButton_7->setToolTip("Sort by cin ascending");
              ui->radioButton_8->setToolTip("Sort by name ascending");
              ui->imprimerf_10->setToolTip("Show age range statistics");
              ui->exportExcelButton->setToolTip("Export data to Excel");
              ui->generer_pdf_9->setToolTip("Export data to PDF");
     connect(ui->tableView_NOUR_4, &QTableView::clicked, this, &MainWindow::on_tableView_NOUR_4_clicked);
     connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::on_searchLineEdit_textChanged);
     connect(ui->imprimerf_10, &QPushButton::clicked, this, &MainWindow::on_imprimerf_10_clicked);
     updateDateFormats();

    ui->tabequipement->setModel(E1.afficher());
ui->tabmedi->setModel(M.afficher());
ui->tabmedi->setModel(M.afficher());
ui->tabmedi->setModel(M.afficher());
ui->tabmedi->setModel(M.afficher());
    //wissal arfaoui
    ui->tabemploye->setModel(E1.afficher());
        m_model = new QSqlTableModel(this);
            m_model->setTable("EMPLOYES3");
            m_model->select();


ui->tabmedi->setModel(M.afficher());
         m_searchTimer = new QTimer(this);
            m_searchTimer->setInterval(500); // set the interval to 500 ms
            connect(m_searchTimer, &QTimer::timeout, this, &MainWindow::onSearchTimerTimeout);
            connect(ui->lineEdit_chercher, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);

                // ajouter des colonnes au modèle, y compris la colonne d'image


                // définir le delegate pour la colonne d'image
                ui->tabemploye->setItemDelegateForColumn(7, new ImageDelegate(this));
                ui->tabemploye->setModel(m_model);










                   //m_dateAffichee = QDate::currentDate();

                   connect(ui->calendarWidget, SIGNAL(selectionChanged()), this, SLOT(on_calendrier_selectionChanged()));
                   // Configuration du calendrier
                   ui->calendarWidget->setMinimumDate(QDate::currentDate());
                  // ui->calendarWidget->setSelectedDate(m_dateAffichee);
                   // Créer le bouton d'envoi de SMS
                      sendSMSButton = new QPushButton("Send SMS", this);

                      // Définir la position et la taille du bouton
                      sendSMSButton->setGeometry(QRect(QPoint(100, 100), QSize(100, 50)));

                      // Connecter le clic sur le bouton à la fonction on_SMS_clicked

                   // Configuration de la liste des tâches
                  // ui->list->setSelectionMode(QAbstractItemView::SingleSelection);
                 //  ui->list->setSortingEnabled(true);
               connect(ui->tabmedi_3, SIGNAL(clicked(const QModelIndex&)), this, SLOT(onTableClicked(const QModelIndex&)));
                   // Affichage des tâches
                  // afficherTaches();

                  // QListWidget* toDoListWidget = ui->list;//new QListWidget(this);
                  // toDoListWidget->setGeometry(10, 10, 200, 150);

               //connect(ui->AjouterTache, &QPushButton::clicked, this, &MainWindow::ajouterTache);
                      // Créer un objet Medicament
                     // Medicament* medicament = new Medicament();

                      // Appeler la fonction toDoList de Medicament en passant le QListWidget comme argument
                     // medicament->toDoList(toDoListWidget);

                       // Créer le widget QDateEdit
                    /*   QDateEdit *deDeadline = new QDateEdit(this);
                       deDeadline->setObjectName("deDeadline");
                       deDeadline->setDate(QDate::currentDate());
                       // ...
                       QDateEdit *dateEdit = new QDateEdit(this);
                       dateEdit->setObjectName("dateEdit");
                       connect(dateEdit, SIGNAL(dateChanged(QDate)), this, SLOT(updateDate(QDate)));
                       QDateEdit *deadlineEdit = new QDateEdit(this);
                       deadlineEdit->setObjectName("deadlineEdit");
                       connect(deadlineEdit, SIGNAL(dateChanged(QDate)), this, SLOT(updateDeadline(QDate)));

                       // Ajouter les objets à la fenêtre principale
                       ui->verticalLayout->addWidget(dateEdit);
                       ui->verticalLayout->addWidget(deadlineEdit);*/
                    /*  ui->tabWidget->setColumnCount(4);
                          QStringList labels;
                          labels << "Date" << "Tâche" << "Deadline" << "Terminé";
                          ui->tabmedi_3->setHorizontalHeaderLabels(labels);*/

               m_currentPage = 0; // Initialise m_currentPage à zéro




                   // Initialisation de proxyModel
                       proxyModel = new QSortFilterProxyModel(this);
                       proxyModel->setSourceModel(M.getModel());

                       // Connecter le slot on_line_chercher_textChanged à la modification de texte dans la ligne de recherche
                       connect(ui->lineEdit_chercher, &QLineEdit::textChanged, this, &MainWindow::on_line_chercher_textChanged);

                       // Configurer le modèle pour le tableau de médicaments
                       ui->tabmedi->setModel(proxyModel);
                       ui->tabmedi->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
                       ui->tabmedi->verticalHeader()->hide();
                       ui->tabmedi->setSelectionBehavior(QAbstractItemView::SelectRows);
                       ui->tabmedi->setSelectionMode(QAbstractItemView::SingleSelection);
                       ui->tabmedi->setStyleSheet(QString("QTableView::item:selected { background-color: yellow; }"));

                       setupReminders(); // Appel de la fonction pour configurer les rappels

                       // Si aucun modèle n'est défini, créer un nouveau modèle avec 4 colonnes
                       //if (!model) {
                           model = new QStandardItemModel(0, 4, this);
                           model->setHeaderData(0, Qt::Horizontal, tr("Date"));
                           model->setHeaderData(1, Qt::Horizontal, tr("Tâche"));
                           model->setHeaderData(2, Qt::Horizontal, tr("Deadline"));
                           model->setHeaderData(3, Qt::Horizontal, tr("Terminé"));
                           model->setHeaderData(4, Qt::Horizontal, tr("Deadline dépassée"));
                           ui->tabmedi_3->setModel(model);

                           // Définir le style pour le tableau
                           setTableStyle(ui->tabmedi_3);
                      // }


                           //maps
                               QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                                                  QCoreApplication::organizationName(), QCoreApplication::applicationName());

                               ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");




}

MainWindow::~MainWindow()
{
    delete ui;
}

//amir


/*
csv
mailing
generateStatistics()
*/
//generer_exel_7
void MainWindow::on_generer_exel_7_clicked() {
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save CSV"), QString(), "*.csv");
  if (!fileName.isEmpty()) {
    if (QFileInfo(fileName).suffix().isEmpty()) {
      fileName.append(".csv");
    }

    QFile csvFile(fileName);
    if (csvFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QTextStream out(&csvFile);

      QSqlQuery query = am.getAllData();
      QSqlRecord record = query.record();

      // Write the header
      for (int i = 0; i < record.count(); ++i) {
        out << "\"" << record.fieldName(i) << "\"";
        if (i < record.count() - 1) {
          out << ",";
        }
      }
      out << "\n";

      // Write the data
      while (query.next()) {
        for (int i = 0; i < record.count(); ++i) {
          out << "\"" << query.value(i).toString() << "\"";
          if (i < record.count() - 1) {
            out << ",";
          }
        }
        out << "\n";
      }

      csvFile.close();

      QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("CSV file generated successfully."), QMessageBox::Cancel);
    } else {
      QMessageBox::critical(nullptr, QObject::tr("Error"),
        QObject::tr("Failed to create the CSV file."), QMessageBox::Cancel);
    }
  }
}



void MainWindow::on_A_recherche_6_textChanged(const QString &text) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM Ambulance WHERE matricule LIKE :matricule");
    query.bindValue(":matricule", "%" + text + "%");
    if (query.exec()) {
        model->setQuery(query);
        ui->tableView_15->setModel(model);
    } else {
        // Handle the error
        QMessageBox::critical(this, QObject::tr("Error"), QObject::tr("Failed to query the database."));
    }
}

bool Ambulance::checkDatabase() {
  QSqlQuery query;
  query.prepare("SELECT COUNT(*) FROM Ambulance");
  if (query.exec() && query.next()) {
    int count = query.value(0).toInt();
    if (count == 0) {
      // Display an alert message
      QString message = "The database is empty.";
      QMessageBox::information(nullptr, QObject::tr("OK"),
        message, QMessageBox::Cancel);
      return false;
    }
  }
  return true;
}
//
void MainWindow::on_vue3d_7_clicked() {

  std::string message = "work successful on .\n"
  "Click Cancel to exit.";
  QMessageBox::information(nullptr, QObject::tr("OK"),
    QString::fromStdString(message), QMessageBox::Cancel);

}

void MainWindow::on_A_comboBox_currentIndexChanged(const QString &text) {
    if (text == "Matricule") {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM Ambulance ORDER BY MATRICULE");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date de sortie"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("disponibilite"));
        ui->tableView_15->setModel(model);
        //resize the columns of your table view to fit the content or the available space
        QHeaderView *header = ui->tableView_15->horizontalHeader();
        header->setSectionResizeMode(QHeaderView::Stretch);
    }else if (text == "IDA") {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM Ambulance ORDER BY IDA");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date de sortie"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("disponibilite"));
        ui->tableView_15->setModel(model);
        //resize the columns of your table view to fit the content or the available space
        QHeaderView *header = ui->tableView_15->horizontalHeader();
        header->setSectionResizeMode(QHeaderView::Stretch);
    }else if (text == "Date de Sortie") {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM Ambulance ORDER BY DATE_SORTIE");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date de sortie"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("disponibilite"));
        ui->tableView_15->setModel(model);
        //resize the columns of your table view to fit the content or the available space
        QHeaderView *header = ui->tableView_15->horizontalHeader();
        header->setSectionResizeMode(QHeaderView::Stretch);
    }else {
        // else function
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM Ambulance");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date de sortie"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("disponibilite"));
        ui->tableView_15->setModel(model);
        //resize the columns of your table view to fit the content or the available space
        QHeaderView *header = ui->tableView_15->horizontalHeader();
        header->setSectionResizeMode(QHeaderView::Stretch);
    }
}

void MainWindow::on_generer_pdf_6_clicked() {

  if (!am.checkDatabase()) {
    return;
  }

  QString fileName = QFileDialog::getSaveFileName(this, tr("Save PDF"), QString(), "*.pdf");
  if (!fileName.isEmpty()) {
    if (QFileInfo(fileName).suffix().isEmpty()) {
      fileName.append(".pdf");
    }

    QPrinter pdfWriter(QPrinter::PrinterResolution);
    pdfWriter.setOutputFormat(QPrinter::PdfFormat);
    pdfWriter.setOutputFileName(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageMargins(QMarginsF(15, 15, 15, 15));

    QTextDocument doc;
    QString html = "<html><body style='background-color : red;'><img src='C:\\Users\\AnisOthman\\Desktop\\giphy.gif' width='30%' ><h1><center>Liste des ambulances</center></h1><br><center><table style='background-color:lightblue;' border=\"1\">";
    html += "<tr>";
    html += "<th>ID</th>";
    html += "<th>Matricule</th>";
    html += "<th>Date de sortie</th>";
    html += "<th>Disponibilité</th>";
    html += "</tr>";

    QSqlQuery query;
    query.prepare("SELECT * FROM Ambulance");
    if (query.exec()) {
      while (query.next()) {
        html += "<tr>";
        html += "<td>" + query.value(0).toString() + "</td>";
        html += "<td>" + query.value(1).toString() + "</td>";
        html += "<td>" + query.value(2).toString() + "</td>";
        html += "<td>" + query.value(3).toString() + "</td>";
        html += "</tr>";
      }
    }

    html += "</table></center></body></html>";
    doc.setHtml(html);
    doc.setPageSize(pdfWriter.pageRect().size());

    doc.print( & pdfWriter);

    // Display an alert message
    QString message = "PDF generated successfully.";
    QMessageBox::information(nullptr, QObject::tr("OK"),
      message, QMessageBox::Cancel);
  }
}


//
void MainWindow::on_Statistiquesf_clicked() {

    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle("Statistiques");
    customMsgBox.setText("Cliquez sur un bouton pour voir le résultat :");

    QPushButton *button1 = customMsgBox.addButton("Statistiques par dispo", QMessageBox::ActionRole);
    QPushButton *button2 = customMsgBox.addButton("Statistiques par Date", QMessageBox::ActionRole);

    customMsgBox.exec();

    if (customMsgBox.clickedButton() == button1) {

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
            chart.setTitle("Statistiques par dispo");
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


                // Set custom colors for the pie slices
                QList<QColor> colors = {Qt::red, Qt::blue, Qt::green, Qt::yellow}; // Add more colors if necessary
                int colorIndex = 0;
                foreach(slice, series->slices()) {
                    slice->setColor(colors[colorIndex % colors.size()]);
                    colorIndex++;
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
    } else if (customMsgBox.clickedButton() == button2) {
        // Create a new dialog window
            QDialog *dialogc = new QDialog();
            // Set the window title
            dialogc->setWindowTitle("Statistics");
            dialogc->setFixedSize(QSize(800, 600));
            // Define the width and height of the chart
            int width = 800;
            int height = 600;
            // Create a chart object
            QChart chartc;
            // Set the chart title
            chartc.setTitle("Statistiques par Date");
            // Create a pie series and add it to the chart
            QPieSeries *seriecs = new QPieSeries();
            // Query the database to get the data for the chart
            QSqlQuery quercy;
            quercy.prepare("SELECT DATE_SORTIE, COUNT(*) FROM Ambulance GROUP BY DATE_SORTIE");
            if(quercy.exec())
            {
                int totalc = 0;
                while(quercy.next())
                {
                    // Get the type and count for the current row
                    QString typec = quercy.value(0).toString();
                    int countc = quercy.value(1).toInt();
                    // Add the type and count to the series
                    seriecs->append(typec, countc);
                    // Increment the total count
                    totalc += countc;
                }
                // Set the series as the data source for the chart
                chartc.addSeries(seriecs);
                // Set the chart legend to show the percentage values
                QPieSlice *slicec;
                foreach(slicec, seriecs->slices()) {
                    slicec->setLabel(QString("%1\n%2%").arg(slicec->label()).arg(100 * slicec->percentage(), 0, 'f', 1));
                }
                // Set custom colors for the pie slices
                QList<QColor> colors = {Qt::red, Qt::blue, Qt::green, Qt::yellow}; // Add more colors if necessary
                int colorIndex = 0;
                foreach(slicec, seriecs->slices()) {
                    slicec->setColor(colors[colorIndex % colors.size()]);
                    colorIndex++;
                }
                // Create a chart view and set its size
                QChartView *chartViewc = new QChartView(&chartc, dialogc);
                chartViewc->setRenderHint(QPainter::Antialiasing);
                chartViewc->resize(width, height);


                // Create a layout for the dialog window and add the chart view widget to it
                QVBoxLayout *layoutc = new QVBoxLayout();
                layoutc->addWidget(chartViewc);
                dialogc->setLayout(layoutc);
            }
            // Show the dialog window
            dialogc->exec();
    }


}

void MainWindow::on_ajout_clicked() {
  /* int ida = ui -> le_id -> text().toInt();
   int matricule = ui -> le_mat -> text().toInt();
   QString date_sortie = ui -> le_date -> text();
   QString disponibilite = ui -> le_disp -> text();
   Ambulance am(ida, date_sortie, matricule, disponibilite);
   */
  int ida = ui -> le_id -> text().toInt();
  QString matricule = ui -> le_mat -> text();
  QString date_sortie = ui -> le_date -> text();
  //QString disponibilite = ui -> le_disp -> text();
  QString checkboxValue;

  if(ui->checkBox_7->isChecked() || ui->checkBox_8->isChecked()) {
    if(ui->checkBox_7->isChecked()) {
      checkboxValue = ui->checkBox_7->text();
    } else {
      checkboxValue = ui->checkBox_8->text();
    }
    Ambulance am(ida, matricule, date_sortie, checkboxValue);
    bool test = am.ajouter_ambulance();
    if (test) {
      std::string message = "ajout successful on .\n"
      "Click Cancel to exit.";
      QMessageBox::information(nullptr, QObject::tr("OK"),
        QString::fromStdString(message), QMessageBox::Cancel);
      ui -> tab_fH_ -> setModel(am.afficher_ambulance());
      ui -> tableView_15 -> setModel(am.afficher_ambulance());

      QHeaderView *header1 = ui->tab_fH_->horizontalHeader();
      header1->setSectionResizeMode(QHeaderView::Stretch);

      QHeaderView *header2 = ui->tableView_15->horizontalHeader();
      header2->setSectionResizeMode(QHeaderView::Stretch);

      stat();
    } else QMessageBox::critical(nullptr, QObject::tr(" not OK"),
      QObject::tr("ajout non effectue.\n"
        "click cancel to exit."), QMessageBox::Cancel);
  } else {
    QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Checkbox not checked."), QMessageBox::Cancel);
  }


}

void MainWindow::on_supprimer_clicked() {
  Ambulance am1;
  am1.setida(ui -> le_id -> text().toInt());
  bool test = am1.supprimer_ambulance(am1.getida());
  QMessageBox msgbox;
  if (test) {
    ui -> tab_fH_ -> setModel(am.afficher_ambulance());
    ui -> tableView_15 -> setModel(am.afficher_ambulance());

    QHeaderView *header1 = ui->tab_fH_->horizontalHeader();
    header1->setSectionResizeMode(QHeaderView::Stretch);

    QHeaderView *header2 = ui->tableView_15->horizontalHeader();
    header2->setSectionResizeMode(QHeaderView::Stretch);

    QMessageBox::information(nullptr, QObject::tr("OK"),
      QObject::tr("suppression avec succes.\n"
        "click cancel to exit."), QMessageBox::Cancel);

  } else QMessageBox::critical(nullptr, QObject::tr(" not OK"),
    QObject::tr("echec de suppression.\n"
      "click cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier_clicked() {
  int ida = ui -> le_id -> text().toInt();
  QString date_sortie = ui -> le_date -> text();
  QString matricule = ui -> le_mat -> text();
  // QString disponibilite = ui -> le_disp -> text();
    QString checkboxValue;

    if(ui->checkBox_7->isChecked() || ui->checkBox_8->isChecked()) {
      if(ui->checkBox_7->isChecked()) {
        checkboxValue = ui->checkBox_7->text();
      } else {
        checkboxValue = ui->checkBox_8->text();
      }

  Ambulance am(ida, matricule, date_sortie, checkboxValue);
  bool test = am.modifier_ambulance(ida, matricule, date_sortie, checkboxValue);
  if (test) {
    ui -> tab_fH_ -> setModel(am.afficher_ambulance());
    ui -> tableView_15 -> setModel(am.afficher_ambulance());

    QHeaderView *header1 = ui->tab_fH_->horizontalHeader();
    header1->setSectionResizeMode(QHeaderView::Stretch);

    QHeaderView *header2 = ui->tableView_15->horizontalHeader();
    header2->setSectionResizeMode(QHeaderView::Stretch);

    stat();
    QMessageBox::information(nullptr, QObject::tr("OK"),
      QObject::tr("modif successful.\n"
        "click cancel to exit."), QMessageBox::Cancel);

  } else QMessageBox::critical(nullptr, QObject::tr(" not OK"),
    QObject::tr("modif non effectue.\n"
      "click cancel to exit."), QMessageBox::Cancel);


    } else {
      QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Checkbox not checked."), QMessageBox::Cancel);
    }
}



//amir


//********************************************NOUR*************************************************************//
bool MainWindow::controlesaisiN()
{

    bool test=true;

        int id=ui->le_ID_2->text().toInt();

        Equipement E;
        if(E.verification_id(id))
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                  QObject::tr("L'ID existe déjà.\n"
                                             "Veuillez saisir un autre ID."),QMessageBox::Cancel);
            test=false;
        }
        else if(ui->le_ID_2->text().isEmpty() || ui->le_nom_2->text().isEmpty() || ui->la_quantite_2->text().isEmpty() || ui->le_prix_2->text().isEmpty())
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                  QObject::tr("Veuillez remplir tous les champs."),QMessageBox::Cancel);
            test=false;
        }
        else if(ui->la_quantite_2->text().toInt() <=0 || ui->le_prix_2->text().toFloat() <=0)
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                  QObject::tr("La quantité et le prix doivent être supérieurs à zéro."),QMessageBox::Cancel);
            test=false;
        }

        return test;
}


void MainWindow::on_ajouter_equipement_clicked() //NOUR
{
    int id=ui->le_ID_2->text().toInt();
        QString nom=ui->le_nom_2->text();
        int quantite=ui->la_quantite_2->text().toInt();
       float prix=ui->le_prix_2->text().toFloat();
        Equipement E(id,nom,quantite,prix);
        bool test=controlesaisiN();
        if(test)
                test=E.ajouter();
        if (test){
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("ajout effectué \n"
                                                 "click cancel to exit."), QMessageBox:: Cancel);
             ui->tabequipement->setModel(E.afficher());
             ui->tabequipement->setModel(E.afficher());

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                  QObject::tr("ajout non effectué .\n"
                                             "click cancel to exit."),QMessageBox::Cancel);


}

void MainWindow::on_supprimer_equipement_clicked() //NOUR
{

    Equipement E1; E1.setID(ui->le_ID_sup->text().toInt());
        bool test=E1.verification_id(E1.getID());
               if(test) test=E1.supprimer(E1.getID());
        QMessageBox msgBox;
        if (test)
        {

        msgBox.setText("supprimé avec succes");
          ui->tabequipement->setModel(E.afficher());
          // ui->tabequipement->setModel(M.afficher());
        }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();

}

bool MainWindow::controlesaisi() //NOUR
{

    if(
            !(ui->le_nom_3->text().contains(QRegExp("^[A-Za-z]+$"))) ||
             ui->la_quantite_3->text().isEmpty()||
             ui->le_prix_3->text().isEmpty()||
            ui->le_ID_3->text().isEmpty()||
            ui->le_ID_3->text().toInt()==0)
        return 0;
    else return 1;
}

void MainWindow::on_modifier_equipement_clicked() //NOUR
{

    bool test;bool trouver;

            int id=ui->le_ID_3->text().toInt();
            QString nom=ui->le_nom_3->text();
            int quantite=ui->la_quantite_3->text().toInt();
     float prix=ui->le_prix_3->text().toFloat();


            Equipement E(id,nom,quantite,prix);
            QMessageBox msg;
           test=controlesaisi();
            if(test)
            test=E.modifier(id);

            trouver=E.verification_id(id);
            if(!trouver)
            {
                test=false;
                msg.setText("id n'existe pas");
                msg.exec();
             }

            if(test)
            {
              msg.setText("modification avec succes!!");

              ui->tabequipement->setModel(E.afficher());
     //ui->tabmedi_2->setModel(M.afficher());

      ui->le_ID_3->clear();
              ui->le_nom_3->clear();
                      ui->la_quantite_3->clear();
    ui->le_prix_3->clear();
             }
            else

            msg.setText("echec de modification");
             msg.exec();
}
void MainWindow::on_generer_pdf_clicked() //NOUR

{
        Equipement E;
        E.genererPDF();
        QString link="C:/Users/zghal/Downloads/Validation Finale/integration_V1 N+W+S+B+A/integration_V1 N+W+S+B+A/integration_V1 N+W+S+B/liste.pdf";
        QDesktopServices::openUrl(QUrl(link));
}
void MainWindow::on_A_recherche_textChanged() //NOUR
{
    Equipement E;
        if(ui->A_recherche->text() == "")
            {
                ui->tabequipement->setModel(E.afficher());
            }
            else
            {
                 ui->tabequipement->setModel(E.rechercherf(ui->A_recherche->text()));
            }

}

void MainWindow::on_trierf_clicked()
{
        QSqlQueryModel * model= new QSqlQueryModel();



           model->setQuery("select id, nom, quantite, prix from EQUIPEMENTS order by "+ui->A_comboBox->currentText()+" ");

           model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite "));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix "));


                   ui->tabequipement->setModel(model);
                    ui->tabequipement->show();

                    ;
}

void MainWindow::on_le_ID_3_textChanged() //NOUR
{

    QSqlQuery query;
    query.prepare("SELECT  nom FROM EQUIPEMENTS WHERE id= "+ui->le_ID_3->text()+"");
    query.bindValue(":nom", ui->le_nom_3->text());
    if (query.exec() && query.next()) {
        ui->le_nom_3->setText(query.value(0).toString());
    }

    query.prepare("SELECT  quantite FROM EQUIPEMENTS WHERE id= "+ui->le_ID_3->text()+"");
    query.bindValue(":quantite", ui->la_quantite_3->text());
    if (query.exec() && query.next()) {
        ui->la_quantite_3->setText(query.value(0).toString());
    }
    query.prepare("SELECT  prix FROM EQUIPEMENTS WHERE id= "+ui->le_ID_3->text()+"");
    query.bindValue(":prix", ui->le_prix_3->text());
    if (query.exec() && query.next()) {
        ui->le_prix_3->setText(query.value(0).toString());
    }
}
void MainWindow::on_send_mail_clicked() //NOUR
{
    Smtp* smtp = new Smtp("zghal.nour@esprit.tn","Nawaramezyena","smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
       smtp->sendMail("zghal.nour@esprit.tn",ui->rcpt->text(),ui->subject->text(),ui->msg->toPlainText());

}


//***************************************************WISSAL******************************************************************



void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->le_ID->text().toInt();
        QString nom = ui->le_nom->text();
        QString prenom = ui->le_prenom->text();
        int age = ui->le_age->text().toInt();
        int num = ui->le_num->text().toInt();
        QString role = ui->le_role->text();
        QString mdp = ui->le_mdp->text();


        // Sélectionner l'image
        QString imagePath = QFileDialog::getOpenFileName(this, "Sélectionnez une image", QString(), "Images (*.png *.xpm *.jpg)");
        if (imagePath.isEmpty()) {
            QMessageBox::warning(this, "Avertissement", "Aucune image sélectionnée.");
            return;

        }

        // Charger l'image en mémoire
        QImage image(imagePath);
        if (image.isNull()) {
            QMessageBox::warning(this, "Avertissement", "Impossible de charger l'image sélectionnée.");
            return;
        }

        // Convertir l'image en QByteArray
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        image.save(&buffer, "JPG"); // vous pouvez utiliser un autre format si vous le souhaitez

        // Créer un objet Employe
        Employe E1(id, nom, prenom, age, num, role, mdp, byteArray,imagePath);

        // Ajouter l'employé à la base de données
        bool test = E1.ajouter();
        if (test) {
            QMessageBox::information(this, "Succès", "L'employé a été ajouté avec succès.");
            ui->tabemploye->setModel(E1.afficher());
        } else {
            QMessageBox::warning(this, "Erreur", "Impossible d'ajouter l'employé.");
        }
}



void MainWindow::on_pb_supprimer_clicked()
{
    Employe E1;QMessageBox msg;
       E.setID(ui->le_ID_sup->text().toInt());
       bool test=false;
       bool trouver=E1.verification_id(E.getID());
             if(trouver)
               test=E1.supprimer(E1.getID());
             else
             {msg.setText("id n'existe pas!!");msg.exec();}


        if(test)
        {
          msg.setText("suppression avec succes!!");
          ui->tabemploye->setModel(E1.afficher());

         }
        else
        msg.setText("!!echec de suppression!!");
         msg.exec();
}


void MainWindow::on_pb_modifier_e_clicked()
{
    bool trouver;
                bool test1;
    QString imagePath;
                int id=ui->edit_ID->text().toInt();
                QString nom=ui->edit_nom->text();
                QString prenom=ui->edit_prenom->text();
                int age=ui->edit_age->text().toInt();
                int num=ui->edit_num->text().toInt();
                QString role=ui->edit_role->text();
                QString mdp=ui->edit_mdp->text();
                QByteArray image;
                Employe E1(id,nom,prenom,age,num,role,mdp,image,imagePath);
                QMessageBox msg;

              test1=controlesaisi1();
                      if(test1)

              test1=E1.modifier(id);

              trouver=E1.verification_id(id);
                      if(!trouver)
                      {
                          test1=false;
                          msg.setText("id n'existe pas");
                          msg.exec();
                       }


                if(test1)
                {
                  msg.setText("modification avec succes!!");

                  ui->tabemploye->setModel(E1.afficher());

                          ui->edit_nom->clear();
                          ui->edit_prenom->clear();
                          ui->edit_age->clear();
                          ui->edit_num->clear();
                          ui->edit_role->clear();
                          ui->edit_mdp->clear();
                 }
                else
                msg.setText("echec de modification");
                 msg.exec();

}
bool MainWindow::controlesaisi1()
{
    QRegExp mailRex("\\b[A-Z,a-z0-9._%+-]+@[A-Z,a-z0-9.-]+\\.[A-Z,a-z]{2,4}\\b");
    mailRex.setCaseSensitivity(Qt::CaseInsensitive);
    mailRex.setPatternSyntax(QRegExp::RegExp);


    if (

                !(ui->edit_nom->text().contains(QRegExp("^[A-Za-z]+$"))) ||

                !(ui->edit_prenom->text().contains(QRegExp("^[A-Za-z]+$"))) ||


                ui->edit_ID->text().isEmpty() ||

                ui->edit_ID->text().toInt() == 0 )



            return 0;

        else

            return 1;







}

void MainWindow::on_pb_trier_clicked()
{
    if (ui->comboBox_trier->currentText()=="Par age")
           ui->tabemploye->setModel (E1.trie_age()) ;
        if (ui->comboBox_trier->currentText()=="Par role")
           ui->tabemploye->setModel (E1.trie_role()) ;
        if (ui->comboBox_trier->currentText()=="Par nom")
           ui->tabemploye->setModel (E1.trie_nom()) ;
}
void MainWindow::onSearchTextChanged(const QString &searchText)
{
    // Démarrer un minuteur pour éviter de déclencher la recherche trop fréquemment
    m_searchTimer->start(500); // 500 millisecondes

    // Enregistrer le texte de recherche actuel
    m_currentSearchText = searchText;
}

void MainWindow::onSearchTimerTimeout()
{
    // Arrêter le minuteur pour éviter que la recherche ne soit déclenchée plusieurs fois en même temps
    m_searchTimer->stop();
    // Vérifier si le texte de recherche a changé depuis le dernier minuteur
        if (m_currentSearchText != m_lastSearchText) {
            // Enregistrer le texte de recherche actuel comme dernier texte de recherche
            m_lastSearchText = m_currentSearchText;
    // Effectuer la recherche avec le texte de recherche actuel



}
}



void MainWindow::on_tabemploye_activated(const QModelIndex &index)
{
    QString val=ui->tabemploye->model()->data(index).toString();
                QSqlQuery qry;
                qry.prepare("select * from EMPLOYES3 where ID='"+val+"'");
                       if (qry.exec())
               {
                   while(qry.next())
                   {
                      ui->edit_ID->setText(qry.value(0).toString());
                      if (ui->tabWidget->count() > 1) {
                                    ui->tabWidget->setCurrentIndex( (ui->tabWidget->currentIndex()+2) % ui->tabWidget->count() );

        }

        ui->le_ID_sup->setText(qry.value(0).toString());
                   }
               }
               else
               {
                   QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                           QObject::tr("Echec"),
                           QMessageBox::Cancel);
               }
}

void MainWindow::on_pushButton_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                                 model->setQuery("select * from EMPLOYES3 where AGE <20 ");
                                 float e=model->rowCount();
                                 model->setQuery("select * from EMPLOYES3 where AGE between 20 and 40 ");
                                 float ee=model->rowCount();
                                 model->setQuery("select * from EMPLOYES3 where AGE > 40 ");
                                 float eee=model->rowCount();
                                 float total=e+ee+eee;
                                 QString a=QString("Moins de 20 ANS "+QString::number((e*100)/total,'f',2)+"%" );
                                 QString b=QString("Entre 20 et 40 ANS "+QString::number((ee*100)/total,'f',2)+"%" );
                                 QString c=QString("Plus de 40 ANS "+QString::number((eee*100)/total,'f',2)+"%" );
                                 QPieSeries *series = new QPieSeries();
                                 series->append(a,e);
                                 series->append(b,ee);
                                 series->append(c,eee);
                         if (e!=0)
                         {QPieSlice *slice = series->slices().at(0);
                          slice->setLabelVisible();
                          slice->setPen(QPen());}
                         if ( ee!=0)
                         {
                                  // Add label, explode and define brush for 2nd slice
                                  QPieSlice *slice1 = series->slices().at(1);
                                  //slice1->setExploded();
                                  slice1->setLabelVisible();
                         }
                         if(eee!=0)
                         {
                                  // Add labels to rest of slices
                                  QPieSlice *slice2 = series->slices().at(2);
                                  //slice1->setExploded();
                                  slice2->setLabelVisible();
                         }
                                 // Create the chart widget
                                 QChart *chart = new QChart();

                                 // Add data to chart with title and hide legend
                                 chart->addSeries(series);
                                 chart->setTitle("Statistiques par AGES : "+ QString::number(total));
                                 chart->legend()->hide();
                                 // Used to display the chart
                                 QChartView *chartView = new QChartView(chart);
                                 chartView->setRenderHint(QPainter::Antialiasing);
                                 chartView->resize(1000,500);
                                 chartView->show();
}

void MainWindow::on_pushButton_pdf_clicked()
{
    QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tabemploye->model()->rowCount();
        const int columnCount =ui->tabemploye->model()->columnCount();

        out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg("vols")
                <<  "</head>\n"
                "<body bgcolor=#E53055 link=#5000A0>\n"
                    "<h1>Liste des employes</h1>\n"

                    "<table border=1.5 cellspacing=0 cellpadding=1>\n";
       out << "<img src=\"C:\\Users\\User\\Desktop\\vald\\final\\projetqt\\image.jpg\" width=\"200\">\n";
        // headers
        out << "<thead><tr bgcolor=#E53055>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabemploye->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabemploye->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";
        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabemploye->isColumnHidden(column)) {
                    QString data = ui->tabemploye->model()->data(ui->tabemploye->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }

        out <<  "</table>\n"

            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        // Créer une boîte de dialogue pour demander à l'utilisateur où enregistrer le PDF
        QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer sous..."), "Liste_employes.pdf", tr("Fichiers PDF (*.pdf)"));

        // Si l'utilisateur a annulé la boîte de dialogue, quitter la fonction
        if (fileName.isEmpty()) {
            return;
        }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        document->print(&printer);

        // Ouvrir le fichier PDF avec le lecteur PDF par défaut
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

void MainWindow::on_lineEdit_chercher_id_textChanged(const QString &arg1)
{
    if (ui->lineEdit_chercher_id->text()!="")
           {

               QString a=ui->lineEdit_chercher_id->text();
               ui->tabemploye->setModel(E1.displayClause("WHERE (id LIKE '%"+a+"%')"));

           }
           else
               ui->tabemploye->setModel(E1.afficher());
}

void MainWindow::on_lineEdit_chercher_nom_textChanged(const QString &arg1)
{ if (ui->lineEdit_chercher_nom->text()!="")
    {

        QString a=ui->lineEdit_chercher_nom->text();
        ui->tabemploye->setModel(E1.displayClause("WHERE (nom LIKE '%"+a+"%')"));

    }
    else
        ui->tabemploye->setModel(E1.afficher());

}

void MainWindow::on_lineEdit_chercher_pre_textChanged(const QString &arg1)
{
    if (ui->lineEdit_chercher_pre->text()!="")
          {

              QString a=ui->lineEdit_chercher_pre->text();
              ui->tabemploye->setModel(E1.displayClause("WHERE (prenom LIKE '%"+a+"%')"));

          }
          else
              ui->tabemploye->setModel(E1.afficher());
}








                            //SEEEEEEEELLLIIIIIIIMAAAAAAAA///////////////////////////////



void MainWindow::sendSMSReminder(QString phoneNumber, QString appointmentDate, QString appointmentTime)
{
    // Remplacer ces valeurs par les identifiants de votre fournisseur de messagerie SMS
    QString accountSid = "AC9d4dfc029eb9feb26e3b77a207a2b160";
    QString authToken = "123b508c2c1017087e513eded8434ecb";
    QString fromNumber = "+15076046312";

    // Construire le corps du message
    QString messageBody = "Rappel de rendez-vous le " + appointmentDate + " à " + appointmentTime;

    // Construire l'URL de l'API du fournisseur de messagerie SMS
    QUrl url("https://console.twilio.com/" + accountSid + "/Messages.json");

    // Construire l'en-tête HTTP pour l'authentification
    QString authHeader = "Basic " + (accountSid + ":" + authToken).toUtf8().toBase64();

    // Construire les paramètres de la requête
    QUrlQuery query;
    query.addQueryItem("From", fromNumber);
    query.addQueryItem("To", phoneNumber);
    query.addQueryItem("Body", messageBody);

    // Créer l'objet QNetworkRequest et ajouter l'en-tête d'authentification
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", authHeader.toUtf8());

    // Envoyer la requête HTTP POST pour envoyer le SMS
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkReply* reply = manager->post(request, query.toString(QUrl::FullyEncoded).toUtf8());

    // Gérer la réponse de la requête (par exemple, vérifier si le SMS a été envoyé avec succès)
    connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Le SMS a été envoyé avec succès
            qDebug() << "SMS envoyé avec succès";
        } else {
            // Le SMS n'a pas pu être envoyé
            qDebug() << "Erreur lors de l'envoi du SMS : " << reply->errorString();
        }

        // Libérer les ressources
        reply->deleteLater();
    });
}
bool MainWindow::controlesaisi11()
{

    if(
            !(ui->le_nom_4->text().contains(QRegExp("^[A-Za-z]+$"))) ||
             ui->la_quantite->text().isEmpty()||
             ui->le_prix->text().isEmpty()||
            ui->le_ID_4->text().isEmpty()||
            ui->le_ID_4->text().toInt()==0)
        return 0;
    else return 1;
}



bool MainWindow::controlesaisii()
{

    if(
            !(ui->le_nommodif->text().contains(QRegExp("^[A-Za-z]+$"))) ||
             ui->la_quantitemodif->text().isEmpty()||
             ui->le_prixmodif->text().isEmpty()||
            ui->le_IDMODIF->text().isEmpty()||
            ui->le_IDMODIF->text().toInt()==0)
        return 0;
    else return 1;
}


void MainWindow::on_ajo_4_clicked()
{
    int id=ui->le_ID_4->text().toInt();
    QString nom=ui->le_nom_4->text();
    int quantite=ui->la_quantite->text().toInt();
   float prix=ui->le_prix->text().toFloat();
    Medicament M(id,nom,quantite,prix);
    bool test=controlesaisi11();
    if(test)
            test=M.ajouter();
    if (test){
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajout effectué \n"
                                             "click cancel to exit."), QMessageBox:: Cancel);
         ui->tabmedi->setModel(M.afficher());
         ui->tabmedi->setModel(M.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                              QObject::tr("ajout non effectué .\n"
                                         "click cancel to exit."),QMessageBox::Cancel);
}




void MainWindow::on_supprimerf_8_clicked()
{
    Medicament M1; M1.setID(ui->le_IDMODIF->text().toInt());
    bool test=M1.verification_id(M1.getID());
           if(test) test=M1.supprimer(M1.getID());
    QMessageBox msgBox;
    if (test)
    {

    msgBox.setText("supprimé avec succes");
      ui->tabmedi->setModel(M.afficher());
      // ui->tabmedi_2->setModel(M.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();

}



void MainWindow::on_Modifier_clicked()
{
    bool test;bool trouver;

        int id=ui->le_IDMODIF->text().toInt();
        QString nom=ui->le_nommodif->text();
        int quantite=ui->la_quantitemodif->text().toInt();
 float prix=ui->le_prixmodif->text().toFloat();


        Medicament M(id,nom,quantite,prix);
        QMessageBox msg;
       test=controlesaisii();
        if(test)
        test=M.modifier(id);

        trouver=M.verification_id(id);
        if(!trouver)
        {
            test=false;
            msg.setText("id n'existe pas");
            msg.exec();
         }

        if(test)
        {
          msg.setText("modification avec succes!!");

          ui->tabmedi->setModel(M.afficher());
 //ui->tabmedi_2->setModel(M.afficher());

  ui->le_IDMODIF->clear();
          ui->le_nommodif->clear();
                  ui->la_quantitemodif->clear();
ui->le_prixmodif->clear();
         }
        else

        msg.setText("echec de modification");
         msg.exec();

}




void MainWindow::on_tabmedi_activated(const QModelIndex &index)
{
    QString val=ui->tabmedi->model()->data(index).toString();
            QSqlQuery qry;
            qry.prepare("select * from MEDICAMENT where ID='"+val+"'");
            //qry.prepare("select * from MEDICAMENT where NOM='"+val+"'");
           if (qry.exec())
           {
               while(qry.next())
               {
                  ui->le_IDMODIF->setText(qry.value(0).toString());
                  ui->le_nommodif->setText(qry.value(1).toString());
                  ui->la_quantitemodif->setText(qry.value(2).toString());
                  ui->le_prixmodif->setText(qry.value(3).toString());
                  if (ui->tabWidget->count() > 1) {
                                ui->tabWidget->setCurrentIndex( (ui->tabWidget->currentIndex()+1) % ui->tabWidget->count() );

    }

    ui->le_ID_sup->setText(qry.value(0).toString());


               }
           }
           else
           {
               QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                       QObject::tr("Echec"),
                       QMessageBox::Cancel);
           }

}




void MainWindow::on_Rechercher_NOUR_7_clicked()
{
    //Medicament M;
       // ui->tabmedi->setModel(M.trie_prix());

        QSqlQueryModel *sortedModel = M.trie_prix();
          ui->tabmedi->setModel(nullptr);
        ui->tabmedi->setModel(sortedModel);
        ui->tabmedi->resizeColumnsToContents();

}



void MainWindow::on_Rechercher_NOUR_8_clicked()
{
    QSqlQueryModel *sortedModel = M.trie_ID();
      ui->tabmedi->setModel(nullptr);
    ui->tabmedi->setModel(sortedModel);
    ui->tabmedi->resizeColumnsToContents();

}




void MainWindow::on_mod_4_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                                    model->setQuery("select * from MEDICAMENT where prix <5 ");
                                    float e=model->rowCount();
                                    QSqlQueryModel *model2 = new QSqlQueryModel();
                                    model2->setQuery("select * from MEDICAMENT where prix between 5 and 50");
                                    float ee = model2->rowCount();
                                    model->setQuery("select * from MEDICAMENT where prix > 50 ");
                                      float eee=model->rowCount();
                                    float total=e+ee+eee;
                                    QString a=QString("Moins de 5 Dinars "+QString::number((e*100)/total,'f',2)+"%" );
                                    QString b=QString("Entre 5 et 50 Dinars "+QString::number((ee*100)/total,'f',2)+"%" );
                                    QString c=QString("Plus de 50 Dinars "+QString::number((eee*100)/total,'f',2)+"%" );
                                    QPieSeries *series = new QPieSeries();
                                    series->append(a,e);
                                    series->append(b,ee);
                                     series->append(c,eee);
                            if (e!=0)
                            {QPieSlice *slice = series->slices().at(0);
                             slice->setLabelVisible();
                             slice->setPen(QPen());}
                            if ( ee!=0)
                            {
                                     // Add label, explode and define brush for 2nd slice
                                     QPieSlice *slice1 = series->slices().at(1);
                                     //slice1->setExploded();
                                     slice1->setLabelVisible();
                            }
                            if(eee!=0)
                            {
                                     // Add labels to rest of slices
                                     QPieSlice *slice2 = series->slices().at(2);
                                     //slice1->setExploded();
                                     slice2->setLabelVisible();
                            }
                                    // Create the chart widget
                                    QChart *chart = new QChart();
                                    // Add data to chart with title and hide legend
                                    chart->addSeries(series);
                                    chart->setTitle("Pourcentage des prix des Medicaments : nombre total : "+ QString::number(total));
                                    chart->legend()->hide();
                                    // Used to display the chart
                                    QChartView *chartView = new QChartView(chart);
                                    chartView->setRenderHint(QPainter::Antialiasing);
                                    chartView->resize(1000,500);
                                    chartView->show();

}




void MainWindow::on_generer_pdf_10_clicked()
{
    QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tabmedi->model()->rowCount();
        const int columnCount =ui->tabmedi->model()->columnCount();

        out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg("vols")
                <<  "</head>\n"
                "<body bgcolor=#E53055 link=#5000A0>\n"
                    "<h1>Liste des medicaments</h1>\n"

                    "<table border=1.5 cellspacing=0 cellpadding=1>\n";
       out << "<img src=\"C:Users/zghal/Downloads/Validation Finale/integration_V1 N+W+S+B+A/integration_V1 N+W+S+B+A/integration_V1 N+W+S+B/MeDispatch Main Logo 800x600.png\" width=\"200\">\n";
        // headers
        out << "<thead><tr bgcolor=#E53055>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabmedi->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabmedi->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";
        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabmedi->isColumnHidden(column)) {
                    QString data = ui->tabmedi->model()->data(ui->tabmedi->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }

        out <<  "</table>\n"

            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        // Créer une boîte de dialogue pour demander à l'utilisateur où enregistrer le PDF
        QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer sous..."), "Liste_medicament.pdf", tr("Fichiers PDF (*.pdf)"));

        // Si l'utilisateur a annulé la boîte de dialogue, quitter la fonction
        if (fileName.isEmpty()) {
            return;
        }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        document->print(&printer);

        // Ouvrir le fichier PDF avec le lecteur PDF par défaut
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));


}




void MainWindow::on_Rechercher_NOUR_6_clicked()
{
    QSqlQueryModel *sortedModel = M.trie_Quantite();
          ui->tabmedi->setModel(nullptr);
        ui->tabmedi->setModel(sortedModel);
        ui->tabmedi->resizeColumnsToContents();

}


void MainWindow::sendSMS(MainWindow* mainWindowPtr, QString phoneNumber, QString message)
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
    connect(reply, &QNetworkReply::finished, mainWindowPtr, &MainWindow::parseSMSReply);
}
void MainWindow::parseSMSReply()
{
    // handle the Twilio API response here
}

void MainWindow::sendSMS(QString account_sid, QString auth_token, QString message, QString from_number, QString to_number, QString picture_url, bool verbose)
{
    if (account_sid.isEmpty() || auth_token.isEmpty() || message.isEmpty() || from_number.isEmpty() || to_number.isEmpty()) {
           qDebug() << "You didn't include all necessary inputs!";
           qDebug() << "Call using -h for help.";
           return;
       }

       QUrl url("https://api.twilio.com/2010-04-01/Accounts/" + account_sid + "/Messages.json");
       QNetworkRequest request(url);
       QByteArray auth = QString("%1:%2").arg(account_sid, auth_token).toLocal8Bit().toBase64();
       request.setRawHeader("Authorization", "Basic " + auth);
       request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

       QUrlQuery params;
       params.addQueryItem("From", from_number);
       params.addQueryItem("To", to_number);
       params.addQueryItem("Body", message);
       if (!picture_url.isEmpty()) {
           params.addQueryItem("MediaUrl", picture_url);
       }

       QNetworkAccessManager *manager = new QNetworkAccessManager(this);
       QNetworkReply *reply = manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());

       QObject::connect(reply, &QNetworkReply::finished, [=](){
           QString response = QString(reply->readAll());
           if (reply->error() != QNetworkReply::NoError) {
               qDebug() << "Message send failed.";
               if (verbose && !response.isEmpty()) {
                   qDebug() << "Response:" << response;
               }
           } else {
               if (verbose) {
                   qDebug() << "SMS sent successfully!";
                   qDebug() << "Response:" << response;
               }
           }
           reply->deleteLater();
           manager->deleteLater();
       });

       QObject::connect(manager, &QNetworkAccessManager::authenticationRequired, [&](QNetworkReply *reply, QAuthenticator *authenticator){
           Q_UNUSED(reply);
           authenticator->setUser(account_sid);
           authenticator->setPassword(auth_token);
       });
}


void MainWindow::on_supprimerf_9_clicked()
{
    QString account_sid = "AC9d4dfc029eb9feb26e3b77a207a2b160";
            QString auth_token = "123b508c2c1017087e513eded8434ecb";
            QString from_number = "+15076046312"; // votre numéro Twilio
            QString to_number = "+21695093545"; // numéro de téléphone du destinataire
            QString message = "Hello, world!"; // message à envoyer
            QString picture_url = ""; // URL de l'image, si vous voulez en envoyer une
            bool verbose = true; // afficher les messages de débogage ou non

            sendSMS(account_sid, auth_token, message, from_number, to_number, picture_url, verbose);

}



void MainWindow::on_calendarWidget_selectionChanged()
{
    QDate selectedDate = ui->calendarWidget->selectedDate();
        QLineEdit *lineEditToUpdate = nullptr;

        if (!m_isFirstDateSelected)
        {
            lineEditToUpdate = ui->date;
        }
        else
        {
            lineEditToUpdate = ui->deadline;
        }

        lineEditToUpdate->setText(selectedDate.toString("yyyy-MM-dd"));

        m_isFirstDateSelected = !m_isFirstDateSelected;

}


void MainWindow::setTableStyle(QTableView *table)
{

    // Définir la couleur de fond de la table
        table->setStyleSheet("background-color: white");

        // Définir la couleur de fond des cellules sélectionnées
        QPalette pal = table->palette();
        pal.setColor(QPalette::Highlight, QColor(213, 213, 213));
        pal.setColor(QPalette::HighlightedText, Qt::black);
        table->setPalette(pal);

        // Définir la couleur de fond des cellules de la colonne "Terminé"
        QStandardItemModel *model = qobject_cast<QStandardItemModel *>(table->model());
        if (model) {
            for (int i = 0; i < model->rowCount(); i++) {
               QString termine = model->data(model->index(i, 3)).toString();
                if (termine == "Oui") {
                    for (int j = 0; j < model->columnCount(); j++) {
                        QStandardItem *item = model->item(i, j);
                        if (item) {
                            item->setBackground(QBrush(Qt::green));
                        }
                    }
                }
            }
        }

        // Modifier la couleur de fond des cellules de la colonne "Deadline dépassée"
        /* if (model) {
            for (int i = 0; i < model->rowCount(); i++) {
                QString deadline = model->data(model->index(i, 2)).toString();
                QString terminé = model->data(model->index(i, 3)).toString();
                if (terminé == "Non") {
                    QDate dl = QDate::fromString(deadline, "yyyy-MM-dd");
                    if (dl < QDate::currentDate()) {
                        for (int j = 0; j < model->columnCount(); j++) {
                            QStandardItem *item = model->item(i, j);
                            if (item) {
                                item->setBackground(QBrush(Qt::red));
                            }
                        }
                    }
                }
            }
        } */

        // Définir la couleur de fond des cellules de la colonne "Titre"
        for (int i = 0; i < model->rowCount(); i++) {
            QStandardItem *item = model->item(i, 0);
            if (item) {
                item->setBackground(QBrush(QColor(255, 214, 214)));
            }
        }

        // Définir la couleur de fond des cellules de la colonne "Description"
        for (int i = 0; i < model->rowCount(); i++) {
            QStandardItem *item = model->item(i, 1);
            if (item) {
                item->setBackground(QBrush(QColor(238, 238, 238)));
            }
        }

        // Définir la couleur de fond des entêtes des colonnes
        QString headerStyleSheet = "QHeaderView::section {"
                                   "background-color: #F2A1A1;"
                                   "color: white;"
                                   "font-weight: bold;"
                                   "padding: 4px;"
                                   "border: none;"
                                   "}";
        table->horizontalHeader()->setStyleSheet(headerStyleSheet);

        // Définir la largeur des colonnes
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // Masquer la colonne "ID"
        table->hideColumn(4);
}

void MainWindow::addPagination()
{

    int currentPage = ui->tabmedi_3->currentIndex().row() / m_pageSize;
       int rowCount = ui->tabmedi_3->model()->rowCount();
       int totalPages = rowCount / m_pageSize + ((rowCount % m_pageSize > 0) ? 1 : 0);
       int startRow = currentPage * m_pageSize;
       int endRow = qMin(startRow + m_pageSize, rowCount) - 1;

       // Show only the rows for the current page
      // QAbstractItemModel *model = ui->tabmedi_3->model();
       for (int row = 0; row < rowCount; row++) {
           if (row >= startRow && row <= endRow) {
               ui->tabmedi_3->setRowHidden(row, false);
           } else {
               ui->tabmedi_3->setRowHidden(row, true);
           }
       }

       // Update page info label
       QString pageInfo = QString("Page %1/%2").arg(currentPage + 1).arg(totalPages);
       ui->pageInfoLbl->setText(pageInfo);

       // Disable "Previous Month" and "Next Month" buttons if necessary
       ui->moisprec->setEnabled(currentPage > 0);
       ui->moisuivant->setEnabled(currentPage < totalPages - 1);




}

void MainWindow::on_moisuivant_clicked()
{
    QModelIndex currentIndex = ui->tabmedi_3->currentIndex();
        int nextIndexRow = currentIndex.row() + m_pageSize;
        int rowCount = ui->tabmedi_3->model()->rowCount();
        if (nextIndexRow >= rowCount) {
            nextIndexRow = rowCount - 1;
        }

        m_currentPage = nextIndexRow / m_pageSize;
        addPagination();

        QModelIndex nextIndex = ui->tabmedi_3->model()->index(nextIndexRow, currentIndex.column());
        ui->tabmedi_3->setCurrentIndex(nextIndex);

}



void MainWindow::on_moisprec_clicked()
{

    m_currentPage--;
        if (m_currentPage < 0) {
            m_currentPage = 0;
        }
        addPagination();

        // Aller à la page précédente
        int prevPageStartRow = m_currentPage * m_pageSize;
        int rowCount = ui->tabmedi_3->model()->rowCount();
        if (prevPageStartRow < rowCount) {
            QModelIndex prevIndex = ui->tabmedi_3->model()->index(prevPageStartRow, 0);
            ui->tabmedi_3->setCurrentIndex(prevIndex);
        }

}



void MainWindow::on_supprimerf_15_clicked()
{
    QString date = ui->date->text();
        // Convertir la chaîne de caractères en QDate
        QDate myDate = QDate::fromString(date, "yyyy-MM-dd");

        // Incrémenter la date d'un jour
        myDate = myDate.addDays(1);

        // Convertir la nouvelle date en QString
        QString newDate = myDate.toString("yyyy-MM-dd");

        // Définir la nouvelle date dans l'interface utilisateur
        ui->date->setText(newDate);


           QString tache = ui->tachee->text();
           QString deadline = ui->deadline->text();

         //  QString emplacement;

           if (date.isEmpty() || tache.isEmpty() || deadline.isEmpty()) {
               return;
           }



           QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tabmedi_3->model());

              if (!model) {
                  // Si aucun modèle n'est défini, créer un nouveau modèle avec 4 colonnes
                  model = new QStandardItemModel(0, 4, this);
                  model->setHeaderData(0, Qt::Horizontal, tr("Date"));
                  model->setHeaderData(1, Qt::Horizontal, tr("Tâche"));
                  model->setHeaderData(2, Qt::Horizontal, tr("Deadline"));
                  model->setHeaderData(3, Qt::Horizontal, tr("Terminé"));
                  model->setHeaderData(4, Qt::Horizontal, tr("Deadline dépassée"));
                  ui->tabmedi_3->setModel(model);

                  // Définir le style pour le tableau
                 setTableStyle(ui->tabmedi_3);
              }

              if (model) {
               QList<QStandardItem *> rowItems;
               rowItems << new QStandardItem(date)
                        << new QStandardItem(tache)
                        << new QStandardItem(deadline)
                        << new QStandardItem("Non")
                        << new QStandardItem("");
             //  << new QStandardItem(emplacement); // Ajouter une colonne "Emplacement" avec la valeur de l'emplacement
               model->appendRow(rowItems);



               //Maps





               QDate d = QDate::fromString(date, "yyyy-MM-dd");
               QDate dl = QDate::fromString(deadline, "yyyy-MM-dd");

             //  qDebug() << "date: " << date << " deadline: " << deadline;
              // qDebug() << "d: " << d << " dl: " << dl;

               if (dl < d) {
                   qDebug() << "deadline dépassée";
                   for (int i = 0; i < model->columnCount(); i++) {
                       model->setData(model->index(model->rowCount() - 1, i), QBrush(Qt::red), Qt::BackgroundRole);
                   }
               }

    }
           ui->tachee->clear();
           ui->deadline->clear();
           ui->date->setText("");
           m_isFirstDateSelected = true;
           // ui->dateEdit->setDate(QDate::currentDate());
           // Créer la tâche correspondante
    addPagination();

}





void MainWindow::on_supprimerf_13_clicked()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tabmedi_3->model());
            if (!model) {
                return;
            }

            QItemSelectionModel *selection = ui->tabmedi_3->selectionModel();
            QModelIndexList indexes = selection->selectedIndexes();
            if (indexes.isEmpty()) {
                return;
            }

            int row = indexes.first().row();
            QModelIndex termineIndex = model->index(row, 3);
            model->setData(termineIndex, "Oui", Qt::DisplayRole);

            QDate date = QDate::fromString(model->data(model->index(row, 0)).toString(), "yyyy-MM-dd");
            QDate deadline = QDate::fromString(model->data(model->index(row, 2)).toString(), "yyyy-MM-dd");

            QBrush brush(Qt::green);
            if (deadline < date) {
                brush = QBrush(Qt::red);
            }
          //  On met à jour la couleur de fond de chaque cellule dans la ligne sélectionnée en utilisant la couleur définie précédemment.
            for (int i = 0; i < model->columnCount(); i++) {
                model->setData(model->index(row, i), brush, Qt::BackgroundRole);
            }

}



void MainWindow::on_tabmedi_3_doubleClicked(const QModelIndex &index)
{
    // Afficher les tâches de la cellule sélectionnée dans une fenêtre modale
       QString taches = ui->tabmedi_3->model()->data(ui->tabmedi_3->model()->index(index.row(), 1)).toString();

       // Créer la fenêtre de dialogue et personnaliser son apparence
       QMessageBox messageBox(this);
       messageBox.setWindowTitle(tr("Tâches de la cellule"));
       messageBox.setText(taches);
       messageBox.setIcon(QMessageBox::Information);
       messageBox.setWindowIcon(QIcon(":/icons/icon.png"));
       messageBox.setMinimumWidth(400);

       // Ajouter un champ d'édition pour ajouter une nouvelle tâche
       QLineEdit* lineEdit = new QLineEdit(&messageBox);
       lineEdit->setPlaceholderText(tr("Entrez une nouvelle tâche"));
       lineEdit->setAlignment(Qt::AlignCenter);
       messageBox.layout()->addWidget(lineEdit);

       // Ajouter les boutons Ajouter et Annuler
       QPushButton* addButton = messageBox.addButton(tr("Ajouter"), QMessageBox::AcceptRole);
       messageBox.addButton(tr("Annuler"), QMessageBox::RejectRole);

       // Personnaliser le style des boutons
       QPalette pal = messageBox.palette();
       pal.setColor(QPalette::Button, QColor("#ff99cc"));
       pal.setColor(QPalette::ButtonText, QColor("#ffffff"));
       messageBox.setPalette(pal);

       QList<QPushButton*> buttons = messageBox.findChildren<QPushButton*>();
       for (QPushButton* button : buttons) {
           button->setStyleSheet("border: 2px solid #8f8f91;"
                                 "font-size: 12pt;"
                                 "padding: 5px;"
                                 "min-width: 80px;");
       }

       // Afficher la fenêtre modale et récupérer le résultat
       int result = messageBox.exec();

       if (result == QMessageBox::AcceptRole) {
           // Ajouter la nouvelle tâche à la ligne sélectionnée
           QString nouvelleTache = lineEdit->text();
           if (!nouvelleTache.isEmpty()) {
               QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tabmedi_3->model());
               if (model) {
                   QString oldTache = model->data(index.sibling(index.row(), 1)).toString(); // récupérer la tâche existante
                   QString newTache = "*" + oldTache + "   *" + nouvelleTache; // créer la nouvelle tâche
                   model->setData(index.sibling(index.row(), 1), newTache); // mettre à jour la cellule
               }
           }
       }

}


void MainWindow::on_supprimerf_14_clicked()
{
    // Récupérer la date sélectionnée dans le tableau
              QModelIndex index = ui->tabmedi_3->currentIndex();
              if (!index.isValid()) {
                  // Si aucune cellule n'est sélectionnée, sortir de la fonction
                  return;
              }
              QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tabmedi_3->model());
              QVariant dateValue = model->data(model->index(index.row(), 0));
              QDate myDate = QDate::fromString(dateValue.toString(), "yyyy-MM-dd");

                  // Incrémenter la date de 1 jour
                  myDate = myDate.addDays(1);

                  // Convertir la nouvelle date en QString
                  QString newDate = myDate.toString("yyyy-MM-dd");

                  // Définir la nouvelle date dans la cellule sélectionnée
                  model->setData(index, newDate);

                  // Récupérer la date limite dans la cellule correspondante
                      QVariant deadlineValue = model->data(model->index(index.row(), 2));
                      QDate deadline = QDate::fromString(deadlineValue.toString(), "yyyy-MM-dd");
                      // Comparer la date limite à la date actuelle
                      if (deadline < myDate) {
                          // Si la deadline est passée, colorer la ligne en rouge
                          for (int col = 0; col < model->columnCount(); col++) {
                              QModelIndex index2 = model->index(index.row(), col);
                              QStandardItem *item = model->itemFromIndex(index2);
                              item->setBackground(QBrush(Qt::red));
                          }
                      } else {
                          // Sinon, réinitialiser la couleur de fond de la ligne
                          for (int col = 0; col < model->columnCount(); col++) {
                              QModelIndex index2 = model->index(index.row(), col);
                              QStandardItem *item = model->itemFromIndex(index2);
                              item->setBackground(QBrush(Qt::white));
                          }
                      }


}


void MainWindow::on_line_chercher_textChanged(const QString &arg1)
{
    QString searchColumnName = ui->combo_chercher->currentText();
           if (searchColumnName.isEmpty()) {
               // Si le nom de la colonne de recherche est vide, on sort de la fonction
               return;
           }
        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
           proxyModel->setSourceModel(M.getModel());

           int index = ui->combo_chercher->currentIndex();
           if (index < 0) {
               // Aucune colonne sélectionnée, on quitte la fonction
               ui->tabmedi->setModel(M.getModel());
               return;
           }
           int ID =ui->lineEdit_chercher->text().toInt();
                   QString nom =ui->lineEdit_chercher->text();
                   int quantite =ui->lineEdit_chercher->text().toInt();
                   if (ui->combo_chercher->currentText()=="ID")
                   {
                   ui->tabmedi->setModel (M.recherche_id(ID)) ;
                   proxyModel->setFilterKeyColumn(0);
                   }
               else if  (ui->combo_chercher->currentText()=="nom") {
                  ui->tabmedi->setModel (M.recherche_nom(nom)) ;
                       proxyModel->setFilterKeyColumn(1);
                   }
                 else if (ui->combo_chercher->currentText()=="quantite")
                   {
                       ui->tabmedi->setModel (M. recherche_quantite(quantite)) ;
                       proxyModel->setFilterKeyColumn(2);
                   }

           QRegExp regex(arg1, Qt::CaseInsensitive, QRegExp::FixedString);
           proxyModel->setFilterRegExp(regex);

           ui->tabmedi->setModel(proxyModel);
           ui->tabmedi->setStyleSheet(QString("QTableView::item:selected { background-color: yellow; }"));

}



void MainWindow::on_checkBox_clicked(bool checked)
{
    if (!ui->tabmedi_3->selectionModel()->hasSelection()) {
            return;
        }

        QModelIndex selectedIndex = ui->tabmedi_3->selectionModel()->selectedIndexes().at(0);

        QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tabmedi_3->model());
        if (model) {
            QStandardItem *item = model->itemFromIndex(selectedIndex);
            if (item) {
                // Si la case cochée est dans la colonne "Terminé", marquer la tâche comme importante
                if (selectedIndex.column() == 0) {
                    QIcon icon;
                    if (checked) {

                        item->setBackground(QBrush(Qt::yellow));
                       // item->setData("Important", Qt::DisplayRole);
                        // Mettre à jour la valeur de la colonne "Terminé" avec la valeur précédente plus importante
                                            QModelIndex termineIndex = model->index(selectedIndex.row(), 3);
                                            QString value = model->data(termineIndex, Qt::DisplayRole).toString();
                                            if (!value.isEmpty()) {
                                                value += " + importante !";
                                            }
                                            model->setData(termineIndex, value, Qt::DisplayRole);
                    } else {
                        item->setBackground(QBrush(Qt::white));
                        item->setData("", Qt::DisplayRole);
                    }
                    item->setIcon(icon);
                }
            }
        }

}



void MainWindow::addReminderColumn()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tabmedi_3->model());
    if (model) {
        model->setHorizontalHeaderItem(model->columnCount(), new QStandardItem("Rappel"));
    }
}

void MainWindow::setReminder(const QModelIndex &index, const QDateTime &reminderDateTime)
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tabmedi_3->model());
    if (model) {
        model->setData(index.sibling(index.row(), model->columnCount() - 1), reminderDateTime, Qt::DisplayRole);
    }
}

QDateTime MainWindow::getReminderDateTime(const QModelIndex &index)
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tabmedi_3->model());
    if (model) {
        return model->data(index.sibling(index.row(), model->columnCount() - 1), Qt::DisplayRole).toDateTime();
    }
    return QDateTime();
}

void MainWindow::checkReminders()
{
    QDateTime now = QDateTime::currentDateTime();

       QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tabmedi_3->model());
       if (model) {
           for (int row = 0; row < model->rowCount(); ++row) {
               QModelIndex reminderIndex = model->index(row, 2);
               QDateTime reminderDateTime = QDateTime::fromString(model->data(reminderIndex, Qt::DisplayRole).toString(), Qt::ISODate);

               if (reminderDateTime.isValid() && reminderDateTime <= now) {
                   QString taskTitle = model->data(model->index(row, 0), Qt::DisplayRole).toString();
                   QString reminderMessage = QString("Rappel pour la tâche : %1").arg(taskTitle);
                   QMessageBox::information(this, "Rappel", reminderMessage);
                   model->setData(reminderIndex, QVariant(), Qt::DisplayRole); // Effacer le rappel après l'avoir affiché
               }
           }
       }
}

void MainWindow::setupReminders()
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkReminders);
    timer->start(60000); // Vérifier toutes les minutes

    m_timer = timer;
}


void MainWindow::on_reminder_clicked()
{
    // Vérifier qu'une tâche est sélectionnée
            QModelIndexList selection = ui->tabmedi_3->selectionModel()->selectedIndexes();
            if (selection.isEmpty()) {
                QMessageBox::warning(this, "Aucune tâche sélectionnée", "Veuillez sélectionner une tâche pour ajouter un rappel.");
                return;
            }

            // Obtenir la date et l'heure actuelle
            QDateTime now = QDateTime::currentDateTime();

            // Afficher une boîte de dialogue pour sélectionner la date et l'heure du rappel
            QDialog dialog(this);
            dialog.setWindowTitle("Ajouter un rappel");
            QFormLayout layout(&dialog);

            QDateTimeEdit dateTimeEdit(&dialog);
            dateTimeEdit.setDateTime(now.addDays(1)); // Par défaut, le rappel est défini pour demain à la même heure
            dateTimeEdit.setMinimumDateTime(now);
            layout.addRow("Date et heure du rappel :", &dateTimeEdit);

            QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
            layout.addRow(&buttonBox);

            connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
            connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

            if (dialog.exec() == QDialog::Accepted) {
                // Mettre à jour la colonne de rappel pour la tâche sélectionnée
                QModelIndex selectedIndex = selection.at(0);
                QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tabmedi_3->model());
                if (model) {
                    QModelIndex reminderIndex = model->index(selectedIndex.row(), 2);
                    QDateTime reminderDateTime = dateTimeEdit.dateTime();
                    model->setData(reminderIndex, reminderDateTime.toString(Qt::ISODate), Qt::DisplayRole);

                    if (now >= reminderDateTime) {
                        // Afficher une notification
                        QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
                        trayIcon->setIcon(QIcon("C:/Users/zghal/Downloads/integration_V1 N+W+S+B+A/integration_V1 N+W+S+B+A/integration_V1 N+W+S+B/liste.pdficon"));
                        trayIcon->show();
                        trayIcon->showMessage("Rappel", "La tâche sélectionnée est due maintenant.", QSystemTrayIcon::Information, 10000);
                    }
                }
            }

}



void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    // Obtenir les tâches à accomplir pour cette date
           QList<QString> tasks;
           QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tabmedi_3->model());
           if (model) {
               for (int row = 0; row < model->rowCount(); row++) {
                   QModelIndex deadlineIndex = model->index(row, 2);
                   if (deadlineIndex.isValid()) {
                       QDateTime deadlineDateTime = QDateTime::fromString(model->data(deadlineIndex, Qt::DisplayRole).toString(), Qt::ISODate);
                       if (deadlineDateTime.date() == date) {
                           QModelIndex taskIndex = model->index(row, 1);
                           QString taskName = model->data(taskIndex, Qt::DisplayRole).toString();
                           tasks.append(taskName);
                       }
                   }
               }
           }

           // Afficher les tâches à accomplir pour cette date
           QString message;
           if (!tasks.isEmpty()) {
               message = "Tâches à accomplir pour le " + date.toString("dd/MM/yyyy") + " :\n";
               for (const QString &task : tasks) {
                   message += "- " + task + "\n" ;
               }
               QMessageBox::information(this, "Tâches à accomplir", message);
           }

}
//BAAAAAAHAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA///
void MainWindow::on_Ajouterclient_NOUR_4_clicked()
{
    int age = ui->lineEdit_18->text().toInt();
    QString nom = ui->linenom_NOUR_4->text();
    QString prenom = ui->lineprenom_NOUR_4->text();
    QString cin = ui->linecin_NOUR_4->text();
    QDate date = ui->dateEdit_4->date();

    patient P(age, nom, prenom, cin, date);

    bool test = P.ajouter();
    if (test)
    {
        qDebug() << "Ajout effectué";
        QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Ajout effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
        updateDateFormats();

    }
    else
    {
        qDebug() << "Ajout non effectué";
        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("Error: Ajout non effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
    }

}
void MainWindow::on_pushButton_2_NOUR_4_clicked()
{
    patient p1; p1.setcin(ui->linecin_3_NOUR_4->text());
    bool test=p1.supprimer(p1.getcin());
    QMessageBox msgBox;
    if (test)

        msgBox.setText("suppression avec succes.");

    else
        msgBox.setText("Failed.");
        msgBox.exec();

}



void MainWindow::on_modifier_button_clicked()
{
    {
        QString cin = ui->modifier_cin->text();
        QString nom = ui->modifier_nom->text();
        QString prenom = ui->modifier_prenom->text();
        int age = ui->modifier_age->text().toInt();

        QSqlQuery query;
        query.prepare("UPDATE PATIENT SET nom=:nom, prenom=:prenom, age=:age WHERE cin=:cin");
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":age", age);
        query.bindValue(":cin", cin);
        patient P(age,nom,prenom,cin,date);

        bool test = P.modifier(cin,nom,prenom,age);
        if (test)
        {
            qDebug() << "Ajout effectué";
            QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("Modification effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            qDebug() << "Modification non effectué";
            QMessageBox::critical
                    (nullptr, QObject::tr("Error"),
                QObject::tr("Error: Ajout non effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
        }
}
}




void MainWindow::updateTableView(QSqlQueryModel *model)
{
    ui->tableView_NOUR_4->setModel(model);
    ui->tableView_NOUR_4->resizeColumnsToContents();
    ui->tableView_NOUR_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_refreshButton_clicked()
{
    QSqlQueryModel* model = P.refreshModel();
    updateTableView(model);
}

void MainWindow::on_tributton_clicked()
{
    QSqlQueryModel* model = P.tri_age_asc();
    ui->tableView_NOUR_4->setModel(model);
}









void MainWindow::on_imprimerf_10_clicked()
{
    int totalPatients = P.countByAgeRange(0, 80);
    int age0to18 = P.countByAgeRange(0, 18);
    int age18to25 = P.countByAgeRange(19, 25);
    int age26to50 = P.countByAgeRange(26, 50);
    int age50to80 = P.countByAgeRange(51, 80);

    float percentage0to18 = (float)age0to18 / totalPatients * 100;
    float percentage18to25 = (float)age18to25 / totalPatients * 100;
    float percentage26to50 = (float)age26to50 / totalPatients * 100;
    float percentage50to80 = (float)age50to80 / totalPatients * 100;

    QPieSeries *series = new QPieSeries();
    series->append("0-18: " + QString::number(percentage0to18, 'f', 2) + "%", percentage0to18);
    series->append("18-25: " + QString::number(percentage18to25, 'f', 2) + "%", percentage18to25);
    series->append("26-50: " + QString::number(percentage26to50, 'f', 2) + "%", percentage26to50);
    series->append("50-80: " + QString::number(percentage50to80, 'f', 2) + "%", percentage50to80);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Age Range Statistics");
    QFont titleFont("Arial", 14, QFont::Bold);
    chart->setTitleFont(titleFont);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
    chart->legend()->setPen(QPen(QColor(192, 192, 192), 1));
    chart->setAnimationOptions(QChart::AllAnimations);

    QColor colors[] = {QColor(60,179,113), QColor(255,165,0), QColor(30,144,255), QColor(220,20,60)};

    for (int i = 0; i < series->count(); ++i) {
        QPieSlice *slice = series->slices().at(i);
        slice->setBrush(colors[i]);
        slice->setLabelColor(QColor(Qt::black));
        slice->setLabelVisible(false);
    }

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(400, 300);
    chartView->setWindowTitle("Age Range Statistics");
    chartView->setWindowIcon(QIcon(":/icons/chart_icon.png"));
    chartView->setWindowFlags(Qt::WindowStaysOnTopHint);
    chartView->show();
}














void MainWindow::on_exportExcelButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export to Excel"), "", tr("Excel files (*.xlsx)"));

    if (fileName.isEmpty()) {
        QMessageBox::warning(this, tr("Export to Excel"), tr("File name is empty. Export canceled."));
        return;
    }

    QSqlQuery query("SELECT * FROM patient");

    QXlsx::Document xlsx;

    xlsx.write("A1", "CIN");
    xlsx.write("B1", "NOM");
    xlsx.write("C1", "PRENOM");
    xlsx.write("D1", "Age");

    int row = 2;
    while (query.next()) {
        xlsx.write(row, 1, query.value(0).toInt());
        xlsx.write(row, 2, query.value(1).toString());
        xlsx.write(row, 3, query.value(2).toString());
        xlsx.write(row, 4, query.value(3).toString());
        ++row;
    }

    if (xlsx.saveAs(fileName)) {
        QMessageBox::information(this, tr("Export to Excel"), tr("Export successful."));
    } else {
        QMessageBox::warning(this, tr("Export to Excel"), tr("Export failed."));
    }
}

void MainWindow::on_generer_pdf_9_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export to PDF"), QString(), "*.pdf");
    if (fileName.isEmpty()) {
        return;
    }

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPagedPaintDevice::A4);
    pdfWriter.setPageOrientation(QPageLayout::Portrait);
    pdfWriter.setCreator("My Application");

    QTextDocument document;
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT * FROM patient");

    QString html = "<html><head>"

                                      "<style>"
                                      "table { border-collapse: collapse; width: 100%; font-family: Arial, sans-serif; }"
                                      "th, td { border: 1px solid #dddddd; padding: 8px; text-align: left; }"
                                      "th { background-color: #f2f2f2; font-weight: bold; }"
                                      "tr:nth-child(even) { background-color: #f2f2f2; }"
                                      "h1 { font-family: Arial, sans-serif; font-size: 24px; margin-left: 10px; }"
                                      ".header { display: flex; align-items: center; justify-content: flex-start; margin-bottom: 20px; }"
                                      "body { background-color: #ADD8E6; }" // Add this line to set the background color of the body to blue
                                      "</style>"
                                      "</head><body>"
                                      "<div class=\"header\">"
                                      "<img src=\"C:\\\\Users\\\\Beha Eddine\\\\Pictures\\\\Screenshots\\\\logo.png\" style=\"width:50px; height:50px;\">"
                                      "<h1>Liste des Patients</h1>"
                                      "</div>"
                                      "</body></html>";


    html += "<tr>";
    for (int i = 0; i < model->columnCount(); i++) {
        html += "<th>" + model->headerData(i, Qt::Horizontal).toString() + "</th>";
    }
    html += "</tr>";

    for (int row = 0; row < model->rowCount(); row++) {
        html += "<tr>";
        for (int col = 0; col < model->columnCount(); col++) {
            html += "<td>" + model->data(model->index(row, col)).toString() + "</td>";
        }
        html += "</tr>";
    }

    html += "</table></body></html>";
    document.setHtml(html);

    document.print(&pdfWriter);
    delete model;

    QMessageBox::information(this, tr("Export to PDF"), tr("Exported data to %1.").arg(fileName));
}
void MainWindow::updateDateFormats()
{
    QSqlQuery query;
    query.prepare("SELECT DISTINCT date_ajout FROM PATIENT");



    QTextCharFormat normalFormat = ui->calendarWidget_2->dateTextFormat(QDate());
    QTextCharFormat patientFormat = normalFormat;
    patientFormat.setBackground(Qt::green);

    while (query.next())
    {
        QDate date = query.value(0).toDate();
        ui->calendarWidget_2->setDateTextFormat(date, patientFormat);
    }
}

void MainWindow::on_calendarWidget_2_clicked(const QDate &date)
{
    QString dateString = date.toString("yyyy-MM-dd");

    QSqlQuery query;
    query.prepare("SELECT * FROM PATIENT WHERE TO_CHAR(date_ajout, 'YYYY-MM-DD')=:date_ajout");
    query.bindValue(":date_ajout", dateString);

    if (!query.exec())
    {
        QMessageBox::critical(this, "Error executing query", query.lastError().text());
        return;
    }

    QDialog patientDialog(this);
    patientDialog.setWindowTitle("Patients added on " + dateString);

    QVBoxLayout *layout = new QVBoxLayout();

    QScrollArea *scrollArea = new QScrollArea(&patientDialog);
    QWidget *scrollWidget = new QWidget();
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);

    bool hasPatients = false;

    while (query.next()) {
        hasPatients = true;
        QString cin = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        int age = query.value(3).toInt();

        QString patientInfo = QString("CIN: %1\nNom: %2\nPrenom: %3\nAge: %4\n\n").arg(cin, nom, prenom, QString::number(age));
        QLabel *patientLabel = new QLabel(patientInfo);
        scrollLayout->addWidget(patientLabel);
    }

    if (hasPatients) {
        scrollArea->setWidget(scrollWidget);
        layout->addWidget(scrollArea);
        patientDialog.setLayout(layout);

        patientDialog.setFixedSize(400, 300);
        patientDialog.exec();
    } else {
        QMessageBox::information(this, "No patients added on " + dateString, "There are no patients added on this date.");
    }
    updateDateFormats();

}
void MainWindow::on_tableView_NOUR_4_clicked(const QModelIndex &index)
{
    if (index.isValid())
    {
        QString cin = ui->tableView_NOUR_4->model()->data(ui->tableView_NOUR_4->model()->index(index.row(), 0)).toString();
        QString nom = ui->tableView_NOUR_4->model()->data(ui->tableView_NOUR_4->model()->index(index.row(), 1)).toString();
        QString prenom = ui->tableView_NOUR_4->model()->data(ui->tableView_NOUR_4->model()->index(index.row(), 2)).toString();
        int age = ui->tableView_NOUR_4->model()->data(ui->tableView_NOUR_4->model()->index(index.row(), 3)).toInt();

        ui->modifier_cin->setText(cin);
        ui->modifier_nom->setText(nom);
        ui->modifier_prenom->setText(prenom);
        ui->modifier_age->setText(QString::number(age));
        ui->linecin_3_NOUR_4->setText(cin);

    }
}

void MainWindow::on_radioButton_7_clicked()
{

        QSqlQueryModel* model = P.tri_cin_asc();
            ui->tableView_NOUR_4->setModel(model);

}

void MainWindow::on_radioButton_8_clicked()
{
    QSqlQueryModel* model = P.tri_nom_asc();
    ui->tableView_NOUR_4->setModel(model);
}
void MainWindow::on_searchLineEdit_textChanged(const QString &text)
{
    patient P;
    QSqlQueryModel *model = P.refreshModel();

    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);

    // Create a regular expression pattern to search in all columns
    QString pattern = QString("^(?=.*%1)").arg(QRegExp::escape(text));
    QRegExp regExp(pattern, Qt::CaseInsensitive, QRegExp::RegExp);

    // Set the filterRegExp to the regular expression pattern
    proxyModel->setFilterRegExp(regExp);

    // Enable filtering for all columns
    proxyModel->setFilterKeyColumn(-1);

    ui->tableView_NOUR_4->setModel(proxyModel);
    ui->tableView_NOUR_4->resizeColumnsToContents();
    ui->tableView_NOUR_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}




//ARDUINOOOOOOOOOOOOOOOOOO///


void MainWindow::update_label()
{
    QByteArray data = A.read_from_arduino();
    qDebug() << data;

    if (!data.isEmpty())
    {
        QString str = QString::fromUtf8(data); // convertir la QByteArray en QString
        int value = str.split("\r\n")[0].toInt(); // extraire la première valeur entière
        qDebug() << value;
        if (value == 0)
        {
            A.write_to_arduino("mmm");

            // Afficher une fenêtre pour la confirmation de l'utilisateur
            QMessageBox msgBox;
            msgBox.setText("detecter");
            msgBox.setStandardButtons(QMessageBox::Yes); //| QMessageBox::No);
            int confirmation = msgBox.exec();

            if (confirmation == QMessageBox::Yes)
            {
                // Convert the result of A.recuperer() to a QByteArray and send it to the Arduino

                A.write_to_arduino(0);

            }
        }

    }
}

void MainWindow::update_labell()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_18->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_18->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON

}


void MainWindow::on_UP_clicked()
{
A.write_to_arduino("1"); //envoyer 1 à arduino
}

void MainWindow::on_DOWN_clicked()
{
    A.write_to_arduino("0");  //envoyer 0 à arduino
}

void MainWindow::on_statistiques_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                                    model->setQuery("select * from EQUIPEMENTS where nom = 'oxygene' ");
                                    float e=model->rowCount();
                                    model->setQuery("select * from EQUIPEMENTS where nom = 'eau' ");
                                    float ee=model->rowCount();
                                    float total=e+ee;
                                    QString a=QString("oxygene"+QString::number((e*100)/total,'f',2)+"%" );
                                    QString b=QString("eau"+QString::number((ee*100)/total,'f',2)+"%" );
                                    QPieSeries *series = new QPieSeries();
                                    series->append(a,e);
                                    series->append(b,ee);
                            if (e!=0)
                            {QPieSlice *slice = series->slices().at(0);
                             slice->setLabelVisible();
                             slice->setPen(QPen());}
                            if ( ee!=0)
                            {
                                     // Add label, explode and define brush for 2nd slice
                                     QPieSlice *slice1 = series->slices().at(1);
                                     //slice1->setExploded();
                                     slice1->setLabelVisible();
                            }
                                    // Create the chart widget
                                    QChart *chart = new QChart();
                                    // Add data to chart with title and hide legend
                                    chart->addSeries(series);
                                    chart->setTitle("Pourcentage des Equipements: nombre total : "+ QString::number(total));
                                    chart->legend()->hide();
                                    // Used to display the chart
                                    QChartView *chartView = new QChartView(chart);
                                    chartView->setRenderHint(QPainter::Antialiasing);
                                    //Set the brush color for each slice
                                                                      QPieSlice *slice = series->slices().at(0);
                                                                       slice->setBrush(QColor("#F44336")); // red color
                                                                       QPieSlice *slice1 = series->slices().at(1);
                                                                       slice1->setBrush(QColor("#2196F3")); // blue color

                                    chartView->show();
}


void MainWindow::on_comboBox_trier_2_activated(const QString &text)
{
    if (text == "Matricule") {
           QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery("SELECT * FROM Ambulance ORDER BY MATRICULE");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("date de sortie"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("disponibilite"));
           ui->tableView_15->setModel(model);
           //resize the columns of your table view to fit the content or the available space
           QHeaderView *header = ui->tableView_15->horizontalHeader();
           header->setSectionResizeMode(QHeaderView::Stretch);
       }else if (text == "ID") {
           QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery("SELECT * FROM Ambulance ORDER BY IDA");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("date de sortie"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("disponibilite"));
           ui->tableView_15->setModel(model);
           //resize the columns of your table view to fit the content or the available space
           QHeaderView *header = ui->tableView_15->horizontalHeader();
           header->setSectionResizeMode(QHeaderView::Stretch);
       }else if (text == "Date_sortie") {
           QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery("SELECT * FROM Ambulance ORDER BY DATE_SORTIE");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("date de sortie"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("disponibilite"));
           ui->tableView_15->setModel(model);
           //resize the columns of your table view to fit the content or the available space
           QHeaderView *header = ui->tableView_15->horizontalHeader();
           header->setSectionResizeMode(QHeaderView::Stretch);
       }else {
           // else function
           QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery("SELECT * FROM Ambulance");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("date de sortie"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("disponibilite"));
           ui->tableView_15->setModel(model);
           //resize the columns of your table view to fit the content or the available space
           QHeaderView *header = ui->tableView_15->horizontalHeader();
           header->setSectionResizeMode(QHeaderView::Stretch);
       }
}
//**********************************login


void MainWindow::on_log_in_clicked()
{

    QMessageBox msg;
       QString username=ui->id_edit->text();
       QString mdp=ui->mdp_edit->text();
       Employe e;
       if(e.authentification(username,mdp)==1)
         {
          ui->stackedWidget_2->setCurrentIndex(1);
          msg.setText("welcome admin!");msg.exec();
          }
        else
         {if(e.authentification(username,mdp)==2)
           {msg.setText("welcome employe!");msg.exec();
               ui->stackedWidget_2->setCurrentIndex(2);}
          }
       ui->id_edit->clear();
       ui->mdp_edit->clear();
}

void MainWindow::on_reset_clicked()
{
    // Affiche une boîte de dialogue pour saisir le nom d'utilisateur
            QString id = QInputDialog::getText(this, tr("Changer le mot de passe"), tr("id :"), QLineEdit::Normal);

            // Vérifie si le nom d'utilisateur existe dans la base de données
            QSqlQuery query;
            query.prepare("SELECT id, mdp FROM EMPLOYES3 WHERE id = :id");
            query.bindValue(":id", id);

            if (!query.exec() || !query.next()) {
                QMessageBox::critical(nullptr, tr("Erreur d'authentification"),
                                      tr("id incorrect ou inexistant dans la base de données"), QMessageBox::Cancel);
                return;
            }

            // Affiche une boîte de dialogue pour saisir le nouveau mot de passe
            QString newPassword = QInputDialog::getText(this, tr("Changer le mot de passe"), tr("Nouveau mot de passe :"), QLineEdit::Normal);

            // Met à jour le mot de passe dans la base de données
            query.prepare("UPDATE EMPLOYES3 SET mdp = :newPassword WHERE id = :id");
            query.bindValue(":newPassword", newPassword);
            query.bindValue(":id", id);

            if (!query.exec()) {
                QMessageBox::critical(nullptr, tr("Erreur de mise à jour du mot de passe"),
                                      tr("Impossible de mettre à jour le mot de passe dans la base de données"), QMessageBox::Cancel);
                return;
            }

            // Enregistre le nouveau mot de passe et le nom d'utilisateur dans un fichier texte sur le bureau
            QString filePath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/nouveau_mot_de_passe_reset.txt";
            QFile file(filePath);

            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QMessageBox::critical(nullptr, tr("Erreur d'écriture dans le fichier"),
                                      tr("Impossible d'écrire dans le fichier sur le bureau"), QMessageBox::Cancel);
                return;
            }

            QTextStream out(&file);
            out << "id: " << id << "\n";
            out << "Nouveau mot de passe : " << newPassword;

            file.close();

            QMessageBox::information(nullptr, tr("Mot de passe mis à jour"),
                                      tr("Le mot de passe a été mis à jour avec succès"), QMessageBox::Ok);
}

