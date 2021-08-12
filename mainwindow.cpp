#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <math.h>


double firstNum;
bool userIsTypingSecondNumber = false;
int dotStatus,loop;
QString checktext;
bool simplemode = true;
bool complexmode = false;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pb0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pb9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pbPosNeg,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pbRoot,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pbSum,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pbSub,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pbMult,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pbDiv,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    connect(ui->pbsh,SIGNAL(released()),this,SLOT(hyperbolic_released()));
    connect(ui->pbch,SIGNAL(released()),this,SLOT(hyperbolic_released()));
    connect(ui->pbth,SIGNAL(released()),this,SLOT(hyperbolic_released()));

    connect(ui->pbSin,SIGNAL(released()),this,SLOT(trigonometric_released()));
    connect(ui->pbCos,SIGNAL(released()),this,SLOT(trigonometric_released()));
    connect(ui->pbTan,SIGNAL(released()),this,SLOT(trigonometric_released()));

    connect(ui->pben,SIGNAL(released()),this,SLOT(logarithmic_released()));
    connect(ui->pbln,SIGNAL(released()),this,SLOT(logarithmic_released()));
    connect(ui->pbLog,SIGNAL(released()),this,SLOT(logarithmic_released()));

    connect(ui->pbx2,SIGNAL(released()),this,SLOT(power_released()));
    connect(ui->pbx3,SIGNAL(released()),this,SLOT(power_released()));
    connect(ui->pbxn,SIGNAL(released()),this,SLOT(power_released()));

    connect(ui->pb3rootn,SIGNAL(released()),this,SLOT(roots_released()));
    connect(ui->pbnroot,SIGNAL(released()),this,SLOT(roots_released()));

    ui->pbSum->setCheckable(true);
    ui->pbSub->setCheckable(true);
    ui->pbMult->setCheckable(true);
    ui->pbDiv->setCheckable(true);
    ui->pbnroot->setCheckable(true);
    ui->pbxn->setCheckable(true);

    CreateCalculatorWidget();
}

void MainWindow::CreateCalculatorWidget()
{
    if (simplemode)
    {
        ui->Complex->hide();
        setMinimumSize(302, 363);
        setMaximumSize(302, 363);
        simplemode = false;
        complexmode = true;
        ui->label->resize(301,61);
        ui->pbSimp->setText("Complex");
    }
    else if (complexmode)
    {
        ui->Complex->show();
        setMinimumSize(484, 363);
        setMaximumSize(484, 363);
        complexmode = false;
        simplemode = true;
        ui->label->resize(484,61);
        ui->pbSimp->setText("Simple");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton* button = (QPushButton*)sender();  // cast result of sender to QPushButton* to get button that sends signal

    double labelNumber;
    QString newLabel;

    if((ui->pbSum->isChecked() || ui->pbSub->isChecked() || ui->pbMult->isChecked() || ui->pbDiv->isChecked() || ui->pbxn->isChecked() || ui->pbnroot->isChecked())
        && (!userIsTypingSecondNumber))
    {
        labelNumber = ( button->text()).toDouble();
        userIsTypingSecondNumber = true;
         newLabel = QString::number(labelNumber, 'g', 15);   // converts to string
    }
    else
    {
        if(ui->label->text().contains('.') && button->text() == "0")
        {
            newLabel = ui->label->text() + button->text();
        }
        else
        {
            labelNumber = (ui->label->text() + button->text()).toDouble();  // concatonate previous numbers to new press
            newLabel = QString::number(labelNumber, 'g', 15);   // converts to string
        }

    }

    ui->label->setText(newLabel);        //


    //  qDebug() << "test";               // qDebug is replacement for std::cout
}

void MainWindow::on_pbDot_released()
{
    checktext = ui->label->text();
    int n = checktext.length();
    for (int i = 0; i < n; i++)  // It will check if '.' is already present.
    {

        if (checktext[i] == '.')
        {
            dotStatus++;

        }

    }
    if (dotStatus == 0)  //user can only input '.' if it is not already present.
        {
            ui->label->setText(ui->label->text()+'.');
        }
}

void MainWindow::unary_operation_pressed()
{
    QPushButton* button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if (button->text() == "+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber* -1;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }

    if(button->text() == "√")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = sqrt(labelNumber) ;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }

}

void MainWindow::on_pbClr_released()
{
    ui->pbSum->setChecked(false);
    ui->pbSub->setChecked(false);
    ui->pbMult->setChecked(false);
    ui->pbDiv->setChecked(false);

    userIsTypingSecondNumber = false;

    ui->label->setText("0");
}

void MainWindow::on_pbEql_released()
{
    double labelNumber, secondNum;
    QString newLabel;

    secondNum = ui->label->text().toDouble();

    if(ui->pbSum->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pbSum->setChecked(false);
    }
    else if(ui->pbSub->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pbSub->setChecked(false);
    }
    else if(ui->pbMult->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pbMult->setChecked(false);
    }
    else if(ui->pbDiv->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pbDiv->setChecked(false);
    }
    else if(ui->pbxn->isChecked())
    {
        labelNumber = pow(firstNum, secondNum);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pbxn->setChecked(false);
    }
    else if(ui->pbnroot->isChecked())
    {
        labelNumber = pow(firstNum, (1/secondNum));
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pbnroot->setChecked(false);
    }
    userIsTypingSecondNumber = false;

}

void MainWindow::binary_operation_pressed()
{
   QPushButton* button = (QPushButton*) sender();

   firstNum = ui->label->text().toDouble();

   button->setChecked(true);


}
void MainWindow::hyperbolic_released()
{
    QPushButton* button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if (button->text() == "sh")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = std::sinh(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
       }
    else if (button->text() == "ch")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = std::cosh(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if (button->text() == "th")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = std::tanh(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::trigonometric_released()
{
    QPushButton* button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;
    if (button->text() == "Sin")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = std::sin(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
       }
    else if (button->text() == "Cos")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = std::cos(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if (button->text() == "Tan")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = std::tan(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::power_released()
{
    QPushButton* button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;
    if (button->text() == "x^2")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = (labelNumber * labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if (button->text() == "x^3")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = (labelNumber* labelNumber* labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
      }
    else if (button->text() == "x^n")
    {
        firstNum = ui->label->text().toDouble();
        newLabel = ui->label->text() + " x^n n= ";
        ui->label->setText(newLabel);
        button->setChecked(true);


     }
   }
void MainWindow::logarithmic_released()
{
    QPushButton* button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;
    if (button->text() == "log")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = std::log10(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if (button->text() == "ln")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = std::log(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if (button->text() == "e^n")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = std::exp(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::roots_released()
{
    QPushButton* button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;
    if (button->text() == "∛n")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = std::cbrt(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if (button->text() == "n√")
    {

            firstNum = ui->label->text().toDouble();
            newLabel = ui->label->text() + " n√ n= ";
            ui->label->setText(newLabel);
            button->setChecked(true);

    }
}



void MainWindow::on_pbSimp_released()
{
    CreateCalculatorWidget();
}



void MainWindow::on_pbPie_released()
{
      QString newLabel,oldLabel;
      oldLabel = newLabel = ui->label->text();
      if (oldLabel=="0")
      {
          newLabel = "3.14159";
          ui->label->setText(newLabel);
      }
      else
      {
          newLabel = ui->label->text() + "3.14159";
          ui->label->setText(newLabel);

      }

}


void MainWindow::on_pbDel_released() //deletes last character if it is present but doesnt delete initial 0
{
    QString Labeltext;
    Labeltext = ui->label->text();
    if (Labeltext != "0") //only works if labeltext is not zero
    {
        if (Labeltext.size () > 0)  Labeltext.resize (Labeltext.size () - 1);//label text size must be atleast 1
        ui->label->setText(Labeltext);
        if (Labeltext == "") ui->label->setText("0");//if all digits are zero set text 0
     }

}
void MainWindow::on_pbSpecial_released()
{
  special = new Special(this);
  special->show();


}

