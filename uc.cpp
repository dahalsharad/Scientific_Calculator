#include "uc.h"
#include "ui_uc.h"
bool length = false;
bool mass = false;
bool Time = false;
bool temp = false;
bool speed = false;
bool numSys = false;




void uc::mw()
{
    if (length)
    {
        ui->mass_6->hide();
        ui->time_12->hide();
        ui->temp_2->hide();
        ui->speed_6->hide();
        ui->noSys->hide();
        ui->length_7->show();
        length = false;
    }
    else if (mass)
    {
        ui->time_12->hide();
        ui->temp_2->hide();
        ui->noSys->hide();
        ui->speed_6->hide();
        ui->length_7->hide();
        ui->mass_6->show();
        mass = false;
    }
    else if (Time)
    {
        ui->time_12->show();
        ui->temp_2->hide();
        ui->noSys->hide();
        ui->speed_6->hide();
        ui->length_7->hide();
        ui->mass_6->hide();
        Time = false;
    }
    else if (temp)
    {
        ui->time_12->hide();
        ui->noSys->hide();
        ui->temp_2->show();
        ui->speed_6->hide();
        ui->length_7->hide();
        ui->mass_6->hide();
        temp = false;
    }
    else if (speed)
    {
        ui->time_12->hide();
        ui->noSys->hide();
        ui->temp_2->hide();
        ui->speed_6->show();
        ui->length_7->hide();
        ui->mass_6->hide();
        speed = false;
    }
    else if (numSys)
    {
        ui->time_12->hide();
        ui->noSys->show();
        ui->temp_2->hide();
        ui->speed_6->hide();
        ui->length_7->hide();
        ui->mass_6->hide();
        numSys = false;
    }
}
uc::uc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uc)
{
    ui->setupUi(this);

    ui->length_7->hide();
    ui->mass_6->hide();
    ui->time_12->hide();
    ui->temp_2->hide();
    ui->speed_6->hide();
    ui->noSys->hide();
}


uc::~uc()
{
    delete ui;
}
void uc::on_length_released()
{
    length =true;
    mw();

}


void uc::on_mass_released()
{
    mass =true;
    mw();
}
void uc::on_time_released()
{
    Time =true;
    mw();

}


void uc::on_temp_released()
{
    temp=true;
    mw();
}
void uc::on_speed_released()
{
    speed=true;
    mw();
}
void uc::on_numSys_released()
{
    numSys=true;
    mw();
}



