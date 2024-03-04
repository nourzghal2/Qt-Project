#ifndef ADDTASKDIALOG_H
#define ADDTASKDIALOG_H

#include <QDialog>

class AddTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTaskDialog(QWidget *parent = nullptr);
    ~AddTaskDialog();
    void setTaches(const QString &tache);

private:
    // Déclaration de widgets et de variables membres privées

};

#endif // ADDTASKDIALOG_H
