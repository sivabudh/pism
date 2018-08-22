#pragma once

#include <QObject>
#include <QQueue>
#include <QStateMachine>

#include "pitypes.h"

class PiStateMachine : public QObject
{
  Q_OBJECT

public:
  explicit PiStateMachine(QObject *parent = nullptr);

public slots:
  void processDisconnectedPumpRequest(PumpID const);
  void processClientCommand(PITHUNDER::Messages const);
  void processConnectedPumpRequest(PumpID const);

signals:
  void currentPump(PumpID const);

public slots:
  void start();
  void resume();

private:
  QStateMachine sm;

private:
  QQueue<PumpServiceRequest> discs;
  QQueue<PITHUNDER::Messages> comms;
  QQueue<PumpServiceRequest> conns;
};
