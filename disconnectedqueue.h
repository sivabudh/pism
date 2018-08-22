#pragma once

#include <QObject>
#include <QQueue>

#include "pitypes.h"

class DisconnectedQueue : public QObject
{
  Q_OBJECT

public:
  DisconnectedQueue(QObject *parent_);

  void append(PumpServiceRequest const);

signals:
  void currentPump(PumpID const);
  void processed();

public slots:
  void process();

private:
  QQueue<PumpServiceRequest> discs;
};
