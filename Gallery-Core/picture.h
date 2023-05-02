#ifndef PICTURE_H
#define PICTURE_H

#include <QString>
#include <QUrl>

#include "Gallery-Core_global.h"

class GALLERYCORE_EXPORT Picture
{
public:
    Picture(const QString& filePath = "");
    Picture(const QUrl& fileUrl);

    int id() const;
    void setId(int newId);

    int albumId() const;
    void setAlbumId(int newAlbumId);

    const QUrl &fileUrl() const;
    void setFileUrl(const QUrl &newFileUrl);

private:
    int mId;
    int mAlbumId;
    QUrl mFileUrl;
};

#endif // PICTURE_H
