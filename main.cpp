#include <QCoreApplication>
#include <QQueue>
#include <QDebug>

#include "pitypes.h"
#include "pistatemachine.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  PiStateMachine machine(nullptr);
  machine.enqueueDisconnectedPumpRequest(PumpServiceRequest {
    2
  });

  QObject::connect(&machine, &PiStateMachine::currentPump,
                  [](PumpID const pumpId_) {
    qDebug() << QString("Current Pump is: %1").arg(pumpId_);
  });


  machine.start();

  return a.exec();
}
