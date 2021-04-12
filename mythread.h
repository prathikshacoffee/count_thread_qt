#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>

class mythread:public QThread
{
    Q_OBJECT


public:
   //constructor
   explicit mythread(QObject *parent=0,int status =0);
   // mandatory virtual run function from QThread class
   void run();
   // Stopstatus that will take values 0, 1 or 2 for Start, Pause, Stop respectively
   int Stopstatus;
   // counter
   int count;
signals:
   // signals to emit whenver a the value of counter is changed or
   // when the status is changed
    void valueChanged(int );
    void statusChanged(int);

public slots :

};

#endif // MYTHREAD_H
