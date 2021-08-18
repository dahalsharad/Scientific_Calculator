#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QDialog>

namespace Ui {
class constants;
}

class constants : public QDialog
{
    Q_OBJECT

public:
    explicit constants(QWidget *parent = nullptr);
    ~constants();
signals:
    void planks();



private:
    Ui::constants *ui;
        void mod_window();

private slots:


    void on_pba_released();
    void on_pbb_released();
    void on_pushButton_pressed();
    void on_pushButton_2_pressed();
};

#endif // CONSTANTS_H
