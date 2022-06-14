#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include "base.h"
#include "picture.h"

#include <QObject>
#include <QTableWidget>
#include <QDateTime>

class TableWidget : public QTableWidget
{
    Q_OBJECT
public:
    TableWidget(int rows, int columns, QWidget *parent = nullptr);
public slots:
    void prepareSave();
    void download(Base*);
signals:
    void save(Base*);
};


#endif // TABLEWIDGET_H
