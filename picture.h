#ifndef PICTURE_H
#define PICTURE_H

#include "base.h"

#include <QObject>
#include <QVector>
#include <QTableWidgetItem>

class Picture : public Base
{
    Q_OBJECT
private:
    QString title;
    QList<QTableWidgetItem> *data;
public:
    Picture(QList<QTableWidgetItem>*, QString);
    ~Picture();

    QString getTitle() const override;

    friend class TableWidget;
};


#endif // PICTURE_H
