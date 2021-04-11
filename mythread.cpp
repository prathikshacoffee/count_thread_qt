#include "mythread.h"
#include<QDebug>
#include <QMutex>
mythread::mythread(QObject *parent,int status ):QThread(parent),Stopstatus(status)
  {

    count = 0;

}

void mythread::run()
{
    for(int i=count;i<=100;i++)
    {
        QMutex mutex;
        mutex.lock();
        if(this->Stopstatus){
            if(this->Stopstatus==2){
                count=0;
                i=0;
            }
            emit statusChanged(Stopstatus);
            emit valueChanged(i);
            break;
        }
        emit statusChanged(Stopstatus);
        emit valueChanged(i);
        this->msleep(500);


    }

}
