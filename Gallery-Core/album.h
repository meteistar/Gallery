#ifndef ALBUM_H
#define ALBUM_H

#include <QString>

#include "Gallery-Core_global.h"


class GALLERYCORE_EXPORT Album
{
public:
    explicit Album(const QString &name = "");

    int id() const;
    void setId(int newId);
    QString name() const;
    void setName(const QString& newName);

private:
    int mId;
    QString mName;
};

#endif // ALBUM_H
