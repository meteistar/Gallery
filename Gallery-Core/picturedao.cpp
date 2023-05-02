#include "picturedao.h"

#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "DatabaseManager.h"
#include "picture.h"

PictureDao::PictureDao(QSqlDatabase& database) :
    mDatabase(database)
{

}

void PictureDao::init() const
{
    QStringList list = mDatabase.tables();

    if (!list.contains("pictures")) {
        QSqlQuery query(mDatabase);
        query.exec(QString("CREATE TABLE pictures")
                   + " (id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   + "album_id INTEGER, "
                   + "url TEXT)");
    }
}

void PictureDao::addPictureInAlbum(int albumId, Picture &picture) const
{
    QSqlQuery query(mDatabase);
        query.prepare(QString("INSERT INTO pictures")
            + " (album_id, url)"
            + " VALUES ("
            + ":album_id, "
            + ":url"
            + ")");
        query.bindValue(":album_id", albumId);
        query.bindValue(":url", picture.fileUrl());
        query.exec();
        DatabaseManager::debugQuery(query);
        picture.setId(query.lastInsertId().toInt());
        picture.setAlbumId(albumId);
}
