#include "uc.h"
#include "ui_uc.h"

uc::uc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uc)
{
    ui->setupUi(this);
}

uc::~uc()
{
    delete ui;
}

