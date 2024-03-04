#include "notification.h"




#include <QSystemTrayIcon>
#include<QString>
Notification::Notification()
{

}

void Notification::notification_ajoutproduit()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    //notifyIcon->setIcon(QIcon("C:/Users/zghal/OneDrive/Bureau/ateliercnx avec CRUD - Copie/icon"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des equipements ","nouveau produit est ajouté ",QSystemTrayIcon::Information,15000);
}



void Notification::notification_supprimerproduit(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon("C:/Users/zghal/OneDrive/Bureau/ateliercnx avec CRUD - Copie/icon"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des equipements ","Un produit est supprimé",QSystemTrayIcon::Information,15000);
}





void Notification::notification_modifierproduit(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon("C:/Users/zghal/OneDrive/Bureau/ateliercnx avec CRUD - Copie/icon"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des equipements ","nouveau produit est modifié",QSystemTrayIcon::Information,15000);

}

