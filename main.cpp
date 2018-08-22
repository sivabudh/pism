#include <QCoreApplication>
#include <QQueue>

#include "pitypes.h"
#include "pistatemachine.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  PiStateMachine machine(nullptr);
  machine.start();

  return a.exec();
}
