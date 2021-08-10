#ifndef SPECIAL_H
#define SPECIAL_H

#include <QDialog>

namespace Ui {
class Special;
}

class Special : public QDialog
{
    Q_OBJECT

public:
    explicit Special(QWidget *parent = nullptr);
    ~Special();

private:
    Ui::Special *ui;
};

#endif // SPECIAL_H
