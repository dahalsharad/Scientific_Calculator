#include "length.h"
#include "ui_length.h"

Length::Length(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Length)
{
    ui->setupUi(this);
}

Length::~Length()
{
    delete ui;
}
