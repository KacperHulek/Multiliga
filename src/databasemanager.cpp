#include "../include/databasemanager.h"

DatabaseManager::DatabaseManager(const QString &dbName) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
}

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::openConnection() {
    return db.open();
}

void DatabaseManager::closeConnection() {
    if (db.isOpen()) {
        db.close();
    }
}
QString DatabaseManager::lastError(){
    return db.lastError().text();
}

void DatabaseManager::setCurrentUserID(const int id){
    userID = id;
}

void DatabaseManager::clearCurrentUserID(){
    userID = NULL;
}

int DatabaseManager::getCurrentUserID(){
    return userID;
}

void DatabaseManager::zalogujUzytkownika(const QString login,const QString haslo){


}


//to nie dziala wiec nie uzywac
QSqlQuery* DatabaseManager::executeQuery(const QString &queryString) {
    return nullptr;
}
