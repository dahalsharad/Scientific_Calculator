#include "special.h"
#include "ui_special.h"

Special::Special(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Special)
{
    ui->setupUi(this);
    connect(ui->pbuc,SIGNAL(released()),this,SLOT(on_pushButton_1_released()));


}

Special::~Special()
{
    delete ui;
}
void Special::on_pushButton_1_released()//for uc
{

  emit ucSelect();
    delete this;
}

void Special::on_pushButton_5_released()//for universal constants
{
    emit constantsSelect();
    delete this;
}

