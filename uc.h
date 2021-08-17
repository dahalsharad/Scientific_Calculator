#ifndef UC_H
#define UC_H

#include <QDialog>

namespace Ui {
class uc;
}

class uc : public QDialog
{
    Q_OBJECT

public:
    explicit uc(QWidget *parent = nullptr);
    ~uc();
private:
    Ui::uc *ui;
        void mw();
private slots:
    void on_length_released();
    void on_mass_released();
    void on_time_released();
    void on_temp_released();
    void on_numSys_released();
    void on_speed_released();


};

#endif // UC_H
