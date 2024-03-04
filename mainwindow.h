#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"equipement.h"
#include "ui_mainwindow.h"
#include <QChartView>
#include"employe.h"
#include <QPainter>
#include <QStyledItemDelegate>
#include <QMainWindow>
#include <QDialog>

#include"Medicament.h"
#include <QStack>
#include"addtaskdialog.h"
#include<QStandardItem>
#include <QTableView>
#include <QSortFilterProxyModel>

#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QDialog>
#include "patient.h"

#include "Arduino.h"
#include "ambulance.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   bool controlesaisi(); //WISSAL
   bool controlesaisi1(); //WISSAL

void update_labell();
void update_label();
   bool controlesaisii(); //SELIMA

      bool controlesaisi11(); //SELIMA

   void sendSMS(QString phoneNumber, QString message);

   void parseSMSReply();

   void setTableStyle(QTableView *tableView);

   void incrementDate();

   void addPagination();



   void setupReminders(); // Appel de la fonction pour configurer les rappels

   void checkReminders();

   QDateTime getReminderDateTime(const QModelIndex &index);

   void addReminderColumn();

   void setReminder(const QModelIndex &index, const QDateTime &reminderDateTime);



   void sendSMSReminder(QString phoneNumber, QString appointmentDate, QString appointmentTime);

   void addPriorityColumn();

   void rechercherAvancee(const QString& text);

   void sendSMS(MainWindow* mainWindowPtr, QString phoneNumber, QString message);





    void sendSMS(QString account_sid, QString auth_token, QString message, QString from_number, QString to_number, QString picture_url, bool verbose);
private slots:


    void on_ajouter_equipement_clicked();
    void on_modifier_equipement_clicked();
    void on_supprimer_equipement_clicked();

    void on_generer_pdf_clicked();
    void on_A_recherche_textChanged();
    void on_le_ID_3_textChanged();
    void on_trierf_clicked();
    void on_send_mail_clicked();
    bool controlesaisiN(); //NOUR






    void on_pb_ajouter_clicked();

    void on_tabemploye_activated(const QModelIndex &index);

    void on_pb_supprimer_clicked();

    void on_pb_modifier_e_clicked();

    void on_pb_trier_clicked();

    void onSearchTextChanged(const QString &searchText);
void onSearchTimerTimeout();


void on_pushButton_stat_clicked();

void on_pushButton_pdf_clicked();

void on_lineEdit_chercher_id_textChanged(const QString &arg1);

void on_lineEdit_chercher_nom_textChanged(const QString &arg1);

void on_lineEdit_chercher_pre_textChanged(const QString &arg1);

void on_ajo_4_clicked();

void on_supprimerf_8_clicked();

void on_Modifier_clicked();

void on_tabmedi_activated(const QModelIndex &index);

void on_Rechercher_NOUR_7_clicked();

void on_Rechercher_NOUR_8_clicked();

void on_mod_4_clicked();

void on_generer_pdf_10_clicked();

void on_Rechercher_NOUR_6_clicked();

void on_supprimerf_9_clicked();

void on_calendarWidget_selectionChanged();

void on_moisuivant_clicked();

void on_moisprec_clicked();

void on_supprimerf_15_clicked();

void on_supprimerf_13_clicked();

void on_tabmedi_3_doubleClicked(const QModelIndex &index);

void on_supprimerf_14_clicked();

void on_line_chercher_textChanged(const QString &arg1);

void on_checkBox_clicked(bool checked);

void on_reminder_clicked();

void on_calendarWidget_clicked(const QDate &date);

void on_Ajouterclient_NOUR_4_clicked();


void on_pushButton_2_NOUR_4_clicked();

//void on_Rechercher_NOUR_4_clicked();

void on_modifier_button_clicked();

//void on_refresh_button_clicked();



void on_refreshButton_clicked();

void on_tributton_clicked();

//void on_pushButton_7_clicked();

//void on_pushButton_8_clicked();


void on_imprimerf_10_clicked();

void on_generer_pdf_9_clicked();

void on_exportExcelButton_clicked();

void on_calendarWidget_2_clicked(const QDate &date);

void on_radioButton_7_clicked();

void on_radioButton_8_clicked();

//amir

void on_ajout_clicked();
void on_vue3d_7_clicked();
void on_generer_pdf_6_clicked();
void on_supprimer_clicked();
void on_modifier_clicked();
void on_Statistiquesf_clicked();
//void on_tab_146_destroyed();
void on_A_comboBox_currentIndexChanged(const QString &text);
//void on_tab_144_destroyed();
//void on_tab_144_objectNameChanged();
void on_A_recherche_6_textChanged(const QString &text);
void on_generer_exel_7_clicked();

//void on_pushButton_7_clicked();


void on_UP_clicked();

void on_DOWN_clicked();

void on_statistiques_2_clicked();

void on_comboBox_trier_2_activated(const QString &text);

void on_log_in_clicked();

void on_reset_clicked();

private:
    Ui::MainWindow *ui;
    Equipement E;

    Ambulance am;


       Employe E1;

        QString m_currentSearchText;
           QTimer* m_searchTimer; // declare the timer variable
    QString m_lastSearchText;
     QSqlTableModel *m_model;
     QByteArray data ;
     Medicament M;

         QPushButton *sendSMSButton;

        // TodoList m_todoList;

     QStandardItemModel *model;

     int m_currentPage = 0;

     const int m_pageSize = 2;

     QSortFilterProxyModel* proxyModel;

     QSortFilterProxyModel* proxyModel1;

     QSortFilterProxyModel* proxyModel2;

            //QDate m_dateAffichee;

          //  void afficherTaches();

              bool m_isFirstDateSelected;

     QTimer  * m_timer;

     Arduino A;
 QByteArray dataa ;
              // void itemChanged(QListWidgetItem *item);

            //void ajouterTache(QString tache, QDate deadline);

     patient P;
     patient P2;
     QDate date;
     void updateTableView(QSqlQueryModel *model);
     void on_tableView_NOUR_4_clicked(const QModelIndex &index);
     void on_searchLineEdit_textChanged(const QString &text);
     void updateDateFormats();
     void setStyles();
     QSqlQueryModel *m_model_2;



};
class ImageDelegate : public QStyledItemDelegate
{
public:
    ImageDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        if (index.column() == 7) // remplacez IMAGE_COLUMN_INDEX par l'indice de la colonne contenant l'image dans votre modèle
        {
            // récupérer l'image stockée dans le modèle
            QByteArray imageData = index.model()->data(index, Qt::DisplayRole).toByteArray();
            QPixmap pixmap;
            pixmap.loadFromData(imageData);

            // dessiner l'image sur le painter
            painter->drawPixmap(option.rect, pixmap);
        }
        else
        {
            QStyledItemDelegate::paint(painter, option, index);
        }
    }
};

#endif // MAINWINDOW_H
