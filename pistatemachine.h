#pragma once

#include <QObject>
#include <QQueue>
#include <QStateMachine>

#include "pitypes.h"
#include "disconnectedqueue.h"

class PiStateMachine : public QObject
{
  Q_OBJECT

public:
  PiStateMachine(QObject * parent_);

public slots:
  void processDisconnectedPumpRequest(PumpID const);

public slots:
  void start();

private:
  QStateMachine sm;

private:
  DisconnectedQueue discs;
};
