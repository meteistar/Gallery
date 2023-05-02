#include "picturedao.h"

#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>

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
