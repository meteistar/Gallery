#include "albummodel.h"

AlbumModel::AlbumModel(QObject* parent):
    QAbstractListModel(parent),
    mDb(DatabaseManager::instance()),
    mAlbums(mDb.albumDao.albums())
{

}

int AlbumModel::rowCount(const QModelIndex &parent) const
{
    return mAlbums->size();
}
