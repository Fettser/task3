#ifndef BASE_H
#define BASE_H

#include <QObject>

class Base : public QObject
{
public:
    virtual QString getTitle() const = 0;
};


#endif // BASE_H
