#include "tablewidget.h"

TableWidget::TableWidget(int rows, int columns, QWidget *parent)
    : QTableWidget(rows, columns, parent) {

}
void TableWidget::prepareSave() {
    QList<QTableWidgetItem> *data = new QList<QTableWidgetItem>();
    for(int i = 0; i < this->rowCount(); i++) {
        for(int j = 0; j < this->columnCount(); j++) {
            if(this->item(i, j) == nullptr) {
                data->push_back(*new QTableWidgetItem());
            }
            else {
                data->push_back(*this->item(i, j));
            }
        }
    }
    Picture *pic = new Picture(data, "Pic " + QDateTime::currentDateTime().toString("hh:mm:ss dd/MM"));
    emit save(pic);
}
void TableWidget::download(Base *base) {
    Picture *pic = static_cast<Picture*>(base);
    for(int l = 0, i = 0; i < this->rowCount(); i++) {
        for(int j = 0; j < this->columnCount(); j++, l++) {
            this->setItem(i, j, new QTableWidgetItem(pic->data->at(l)));
        }
    }
}
