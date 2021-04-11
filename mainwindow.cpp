#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mythread.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mthread=new mythread(this, 0);
    connect(mthread,SIGNAL(valueChanged(int)),this,SLOT(onValueChanged(int)));
    connect(mthread,SIGNAL(statusChanged(int)),this,SLOT(onStatusChanged(int)));
}

void MainWindow::onValueChanged(int count)
{
    ui->label->setText("Count:  " + QString::number(count));
    mthread->count = count;
}

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


void MainWindow ::on_pushButton_clicked()
{
    mthread->Stopstatus=0;
    mthread->start();
}

void MainWindow ::on_pushButton_2_clicked()
{
    mthread->Stopstatus=1;

}
void MainWindow ::on_pushButton_3_clicked()
{
    mthread->count = 0;
    mthread->Stopstatus=2;
    ui->label->setText("Count:  " + QString::number(mthread->count));
}
MainWindow::~MainWindow()
{
    delete ui;
}
