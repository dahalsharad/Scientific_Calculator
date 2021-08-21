#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "special.h"
#include "constants.h"
#include "uc.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
         ~MainWindow();

    private:
        Ui::MainWindow *ui;

        void CreateCalculatorWidget();
        Special *special;
        uc *UC;
        constants *Constants;
    public slots:
        void constantsSelect();
        void ucSelect();
        void planks();
        void cm_m();


    private slots:
        void digit_pressed();    // slot is code that executes when signal is emitted

        void on_pbDot_released();
        void unary_operation_pressed();
        void on_pbClr_released();
        void on_pbEql_released();
        void binary_operation_pressed();
        void hyperbolic_released();
        void trigonometric_released();
        void logarithmic_released();
        void power_released();
        void roots_released();

        void on_pbSimp_released();
        void on_pbPie_released();
        void on_pbDel_released();
        void on_pbSpecial_released();

};

#endif // MAINWINDOW_H
