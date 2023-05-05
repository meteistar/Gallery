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

void PictureModel::setAlbumId(int albumId)
{
    beginResetModel();
    mAlbumId = albumId;
    loadPictures(mAlbumId);
    endResetModel();
}

void PictureModel::loadPictures(int albumId)
{
    if (albumId <= 0) {
        mPictures.reset(new vector<unique_ptr<Picture>>());
        return;
    }
    mPictures = mDb.pictureDao.picturesForAlbum(albumId);
}
