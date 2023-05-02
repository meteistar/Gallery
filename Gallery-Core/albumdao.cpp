#include "albumdao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>

#include "databasemanager.h"

AlbumDao::AlbumDao(QSqlDatabase& database) :
    mDatabase(database)
{

}

void AlbumDao::init() const
{
    QStringList list = mDatabase.tables();

    if (!list.contains("album")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE albums (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
    }
}
