#include "mythread.h"
#include<QDebug>
#include <QMutex>

// contructor, the private value count is set to zero when the thread
// instance is created
mythread::mythread(QObject *parent,int status ):QThread(parent),Stopstatus(status)
  {

    count = 0;

}

// The virutal run function inheretied from Qthread class is defined here
// this is a mandatory function to define and we write the logic here
// for what should happen when the thread is run

void mythread::run()
{
    for(int i=count;i<=100;i++)
    {
        QMutex mutex;
        mutex.lock();
        // while emitting the signal or writing values to count we lock
        // this thread so that no other emit or write operation is performed
        // by other threads if any
        if(this->Stopstatus){
            // This condition of resetting the counter when stop button is clicked
            // is added here because once stop is clicked immediately a signal is emitted
            // from this run function before actually the count value being changed in the push
            // button, hence only on the second click the count value displayed on the window
            // was getting resetted to 0, hence resetting the count value here as well
            // when the status is changed.
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
        // sleep for half a second.
        this->msleep(500);


    }

}
