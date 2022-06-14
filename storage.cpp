#include "storage.h"

Storage::Storage(QWidget *parent) : QVBoxLayout(parent) {
   pictures = new QList<Base*>;
}
void Storage::save(Base *Base) {
    pictures->push_back(Base);
    currentPicture =pictures->back();
    QPushButton *pictureButton = new QPushButton();
    pictureButton->setText(Base->getTitle());
    this->insertWidget(0,pictureButton);
    connect(pictureButton, &QPushButton::clicked, this, [=]() {
        int size =pictures->size();
        for(int i = 0; i < size; i++) {
            if(!pictures->at(i)->getTitle().compare(pictureButton->text())) {
                currentPicture =pictures->at(i);
            }
        }
    });
}
void Storage::prepareGetPicture() {
    if(currentPicture != nullptr) {
        emit getPicture(currentPicture);
    }
}
Storage::~Storage() {
    int size =pictures->size();
    for(int i = 0; i < size; i++) {
        delete (*pictures)[i];
    }
    delete pictures;
}
