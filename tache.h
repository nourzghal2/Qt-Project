#ifndef TACHE_H
#define TACHE_H

#include <QString>
#include <QDate>

class Tache
{
public:
    Tache(QString date, QString tache, QString deadline);

    QString getDate();
    QString getTache();
    QString getDeadline();
    bool isDone();
    void setDone(bool done);
        bool isDeadlineExpired();
private:
    QString m_date;
    QString m_tache;
    QString m_deadline;
    bool m_done;
};

#endif // TACHE_H

