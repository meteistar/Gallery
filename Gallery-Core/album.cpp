#include "album.h"

Album::Album()
{
}

int Album::id() const
{
    return mId;
}

void Album::setId(int newId)
{
    mId = newId;
}

const QString &Album::name() const
{
    return mName;
}

void Album::setName(const QString &newName)
{
    mName = newName;
}
