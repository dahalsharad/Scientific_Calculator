#include "special.h"
#include "ui_special.h"

Special::Special(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Special)
{
    ui->setupUi(this);
}

Special::~Special()
{
    delete ui;
}
