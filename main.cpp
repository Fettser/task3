#include "mainwindow.h"

#include "storage.h"
#include "picture.h"
#include "tablewidget.h"

#include <QApplication>
#include <QScrollArea>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget win;

    win.setWindowTitle("Хранитель");

    QHBoxLayout *mlayout = new QHBoxLayout;

    QVBoxLayout *slayout = new QVBoxLayout;

    QHBoxLayout *hlayout = new QHBoxLayout;

    TableWidget *table = new TableWidget(3, 3);

    Storage *storage = new Storage;
    QWidget *area = new QWidget;
    QScrollArea *scroll = new QScrollArea;
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setWidgetResizable(true);

    QPushButton *saveButton = new QPushButton;
    QPushButton *downloadButton = new QPushButton;
    saveButton->setText("Сохранить");
    downloadButton->setText("Загрузить");

    area->setLayout(storage);
    scroll->setWidget(area);

    hlayout->addWidget(saveButton);
    hlayout->addWidget(downloadButton);

    slayout->addWidget(scroll);
    slayout->addLayout(hlayout);

    mlayout->addLayout(slayout);
    mlayout->addWidget(table);

    win.setLayout(mlayout);

    QObject::connect(saveButton, SIGNAL(clicked()), table, SLOT(prepareSave()));
    QObject::connect(table, SIGNAL(save(Base*)), storage, SLOT(save(Base*)));
    QObject::connect(downloadButton, SIGNAL(clicked()), storage, SLOT(prepareGetPicture()));
    QObject::connect(storage, SIGNAL(getPicture(Base*)), table, SLOT(download(Base*)));

    win.show();
    return a.exec();
}

