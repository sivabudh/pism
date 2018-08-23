#include <QApplication>
#include <QQueue>
#include <QDebug>
#include <QTimer>

#include "pitypes.h"
#include "pistatemachine.h"
#include "gilbarcopollingstatemachine.h"

void testPiStateMachine()
{
  PiStateMachine machine(nullptr);
  machine.enqueueDisconnectedPumpRequest(PumpServiceRequest {
    2
  });
  machine.enqueueCommand(PITHUNDER::Messages {
    4
  });

  QObject::connect(&machine, &PiStateMachine::currentPump, [&](PumpID const pumpId_) {
    qDebug() << QString("Current Pump is: %1").arg(pumpId_);

    // Stop because we want the state machine to be paused
    machine.stop();

    // Then, once it's ready again, we restart!
    QTimer::singleShot(1500, [&](){
      machine.start();
    });
  });


  machine.start();
}

void testGilbarcoPolling()
{
  GilbarcoPollingStateMachine machine(nullptr);

  machine.start();
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  testGilbarcoPolling();

  return a.exec();
}
