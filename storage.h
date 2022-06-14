#ifndef STORAGE_H
#define STORAGE_H

#include "base.h"

#include <QVBoxLayout>
#include <QPushButton>

class Storage : public QVBoxLayout
{
    Q_OBJECT
private:
    QList<Base*> *pictures;
    Base *currentPicture;
public:
    Storage(QWidget *parent = 0);
    ~Storage();
public slots:
    void save(Base*);
    void prepareGetPicture();
signals:
    void getPicture(Base*);
};


#endif // STORAGE_H
