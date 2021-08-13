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
/*private slots:
    void on_length_released();
    void on_mass_released();
    void on_time_released();
    void on_temperature_released();
    void on_nosys_released();
    void on_speed_released();*/

private:
    Ui::uc *ui;
};

#endif // UC_H
