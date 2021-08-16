#include "constants.h"
#include "ui_constants.h"
bool b = false;
bool a = false;


void constants::mod_window()
{
    if (a)
    {
        ui->gbb->hide();
        ui->gba->show();
        a = false;
    }
    else if (b)
    {
        ui->gba->hide();
        ui->gbb->show();
        b = false;
    }
}
constants::constants(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::constants)
{
    ui->setupUi(this);

    ui->gba->hide();
    ui->gbb->hide();
}


constants::~constants()
{
    delete ui;
}

void constants::on_pba_released()
{
    a=true;
    mod_window();

}


void constants::on_pbb_released()
{
    b=true;
    mod_window();
}

