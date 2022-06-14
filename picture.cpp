#include "picture.h"

Picture::Picture(QList<QTableWidgetItem> *data, QString title)
{
    this->data = data;
    this->title = title;
}
QString Picture::getTitle() const {
    return title;
}
Picture::~Picture() {
    delete data;
}
