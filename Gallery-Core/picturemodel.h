#ifndef PICTUREMODEL_H
#define PICTUREMODEL_H

#include <QAbstractListModel>

class PictureModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PictureModel(QObject *parent = nullptr);
};

#endif // PICTUREMODEL_H
