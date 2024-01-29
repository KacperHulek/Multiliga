#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql>

class DatabaseManager {
public:
    DatabaseManager(const QString &dbName);
    ~DatabaseManager();

    bool openConnection();
    void closeConnection();
    void zalogujUzytkownika(const QString login,const QString haslo);
    QString lastError();
    QSqlQuery* executeQuery(const QString &queryString);
    void setCurrentUserID(const int id);
    void clearCurrentUserID();
    int getCurrentUserID();

private:
    QSqlDatabase db;
    int userID;
};

#endif // DATABASEMANAGER_H
