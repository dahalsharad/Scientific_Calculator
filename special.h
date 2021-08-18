#ifndef SPECIAL_H
#define SPECIAL_H

#include <QDialog>
#include "uc.h"
#include "constants.h"

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


signals:
    void constantsSelect();
    void ucSelect();




};

#endif // SPECIAL_H
