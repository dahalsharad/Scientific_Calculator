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

private slots:
    void on_pushButton_5_released();

private:
    Ui::Special *ui;
};

#endif // SPECIAL_H
