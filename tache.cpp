#include "tache.h"

Tache::Tache(QString date, QString tache, QString deadline)
{
    m_date = date;
    m_tache = tache;
    m_deadline = deadline;
    m_done = false;
}

QString Tache::getDate()
{
    return m_date;
}

QString Tache::getTache()
{
    return m_tache;
}

QString Tache::getDeadline()
{
    return m_deadline;
}

bool Tache::isDone()
{
    return m_done;
}

void Tache::setDone(bool done)
{
    m_done = done;
}


bool Tache::isDeadlineExpired()
{
    QDate deadlineDate = QDate::fromString(m_deadline, "yyyy-MM-dd");
    QDate currentDate = QDate::currentDate();
    return deadlineDate < currentDate;
}
