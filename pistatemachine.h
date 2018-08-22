#pragma once

#include <QObject>
#include <QQueue>
#include <QStateMachine>

#include "pitypes.h"
#include "disconnectedqueue.h"
#include "commandqueue.h"

class PiStateMachine : public QObject
{
  Q_OBJECT

public:
  PiStateMachine(QObject * parent_);

signals:
  void currentPump(PumpID const);

public slots:
  void enqueueDisconnectedPumpRequest(PumpServiceRequest const);
  void enqueueCommand(PITHUNDER::Messages const);

public slots:
  void start();
  void stop();

private:
  QStateMachine sm;

private:
  DisconnectedQueue discs;
  CommandQueue comms;
};
