#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mythread.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mthread=new mythread(this, 0);
    //connect two signals and slots, one to notify value changed and
    // one to notify the change in status
    connect(mthread,SIGNAL(valueChanged(int)),this,SLOT(onValueChanged(int)));
    connect(mthread,SIGNAL(statusChanged(int)),this,SLOT(onStatusChanged(int)));
}
// whenever value changed signal is emitted the corresponding count value is displayed
void MainWindow::onValueChanged(int count)
{
    ui->label->setText("Count:  " + QString::number(count));
    mthread->count = count;
}

//whenver status changed signal is emitted, changed status is updated
// we have two status, Not Running when the counter thread is not running
// It shows Not Running for two states, stop state and pause state.
// Running status is shown the window when the counter is running and count
// value is getting updated.
void MainWindow::onStatusChanged(int status)
{
    QString running;
    if(status){
        running = "Not Running";
    }
    else
        running = "Running";
    ui->label_2->setText("Status:  " + running);

}

// We have 3 status values
// 0 -> Start and when the counter is running
// 1 -> Paused, when counter is paused but the value is not resetted to 0
// 2 -> Stop, when the counter is stopped and resetted to zero. It will
//      start again when start button is clicked.
void MainWindow ::on_pushButton_clicked()
{
    mthread->Stopstatus=0;
    mthread->start();
}

void MainWindow ::on_pushButton_2_clicked()
{
    mthread->Stopstatus=1;

}

// Here we reset the counter value to 0
void MainWindow ::on_pushButton_3_clicked()
{
    mthread->count = 0;
    mthread->Stopstatus=2;
    ui->label->setText("Count:  " + QString::number(mthread->count));
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}
