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

void Special::on_pushButton_5_released()//for universal constants
{
    Special::close();//to close current box

}

