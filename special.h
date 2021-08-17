#ifndef SPECIAL_H
#define SPECIAL_H

#include <QDialog>
#include "uc.h"

namespace Ui {
class Special;
}

class Special : public QDialog
{
    Q_OBJECT

public:
    explicit Special(QWidget *parent = nullptr);
    ~Special();

private slots:
    void on_pushButton_5_released();
    void on_pushButton_1_released();

private:
    Ui::Special *ui;
    //void CreateCalculatorWidget();
    uc *UC;
};

#endif // SPECIAL_H
