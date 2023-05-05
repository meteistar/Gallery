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

QVariant AlbumModel::data(const QModelIndex &index, int role) const
{
    if (!isIndexValid(index)) {
        return QVariant();
    }
    const Album& album = *mAlbums->at(index.row());
    switch (role) {
    case Roles::IdRole:
        return album.id();
    case Roles::NameRole:
    case Qt::DisplayRole:
        return album.name();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> AlbumModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    return roles;
}

bool AlbumModel::isIndexValid(const QModelIndex &index) const
{

}
