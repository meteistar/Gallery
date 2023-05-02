#include "albumdao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>
#include <memory>

#include "databasemanager.h"
#include "album.h"

using namespace std;

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

void AlbumDao::addAlbum(Album &album) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO albums (name) VALUES (:name)");
    query.bindValue(":name", album.name());
    query.exec();
    album.setId(query.lastInsertId().toInt());
}

void AlbumDao::updateAlbum(const Album &album) const
{

}

void AlbumDao::removeAlbum(int id) const
{

}

std::unique_ptr<std::vector<std::unique_ptr<Album> > > AlbumDao::albums() const
{
    QSqlQuery query("SELECT * FROM albums", mDatabase);
    query.exec();
    unique_ptr<vector<unique_ptr<Album>>> list(new vector<unique_ptr<Album>>());
    while(query.next()) {
        unique_ptr<Album> album(new Album());
        album->setId(query.value("id").toInt());
        album->setName(query.value("name").toString());
        list->push_back(move(album));
    }
    return list;
}

//QVector<Album *> AlbumDao::albums() const
//{
//    QSqlQuery query("SELECT * FROM albums", mDatabase);
//    query.exec();
//    QVector<Album*> list;
//    while(query.next()) {
//        Album* album = new Album();
//        album->setId(query.value("id").toInt());
//        album->setName(query.value("name").toString());
//        list.append(album);
//    }
//    return list;
//}
