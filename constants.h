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

private:
    Ui::constants *ui;
};

#endif // CONSTANTS_H
