#ifndef LENGTH_H
#define LENGTH_H

#include <QDialog>

namespace Ui {
class Length;
}

class Length : public QDialog
{
    Q_OBJECT

public:
    explicit Length(QWidget *parent = nullptr);
    ~Length();

private:
    Ui::Length *ui;
};

#endif // LENGTH_H
