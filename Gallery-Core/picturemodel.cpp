#include "picturemodel.h"
#include "databasemanager.h"
#include "albummodel.h"

using namespace std;

PictureModel::PictureModel(const AlbumModel& albumModel, QObject* parent)
    : QAbstractListModel{parent}
    , mDb(DatabaseManager::instance())
    , mAlbumId(-1)
    , mPictures(new vector<unique_ptr<Picture>>())
{
    connect(&albumModel, &AlbumModel::rowsRemoved,
            this, &PictureModel::deletePicturesForAlbum);
}

QModelIndex PictureModel::addPicture(const Picture &picture)
{
    return QModelIndex();
}

int PictureModel::rowCount(const QModelIndex &parent) const
{
    return mPictures->size();
}

QVariant PictureModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

bool PictureModel::removeRows(int row, int count, const QModelIndex &parent)
{
    return false;
}

void PictureModel::setAlbumId(int albumId)
{
    beginResetModel();
    mAlbumId = albumId;
    loadPictures(mAlbumId);
    endResetModel();
}

void PictureModel::clearAlbum()
{

}

void PictureModel::deletePicturesForAlbum()
{

}

void PictureModel::loadPictures(int albumId)
{
    if (albumId <= 0) {
        mPictures.reset(new vector<unique_ptr<Picture>>());
        return;
    }
    mPictures = mDb.pictureDao.picturesForAlbum(albumId);
}

bool PictureModel::isIndexValid(const QModelIndex &index) const
{
    return false;
}
