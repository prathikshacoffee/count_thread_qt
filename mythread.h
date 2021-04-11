#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>

class mythread:public QThread
{
    Q_OBJECT


public:
   explicit mythread(QObject *parent=0,int status =0);
   void run();
   int Stopstatus;
   int count;
signals:
    void valueChanged(int );
    void statusChanged(int);

public slots :

};

#endif // MYTHREAD_H
