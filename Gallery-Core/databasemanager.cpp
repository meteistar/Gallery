#include "databasemanager.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

void DatabaseManager::debugQuery(const QSqlQuery &query)
{
    if (query.lastError().type() == QSqlError::ErrorType::NoError) {
            qDebug() << "Query OK:"  << query.lastQuery();
        } else {
           qWarning() << "Query KO:" << query.lastError().text();
           qWarning() << "Query text:" << query.lastQuery();
        }
}

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
    delete mDatabase;
}

DatabaseManager::DatabaseManager(const QString &path):
    mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    albumDao(*mDatabase)
{
    mDatabase->setDatabaseName(path);
    mDatabase->open();

    albumDao.init();
}

