#include "constants.h"
#include "ui_constants.h"

constants::constants(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::constants)
{
    ui->setupUi(this);
}

constants::~constants()
{
    delete ui;
}
