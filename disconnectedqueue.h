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
  bool isEmpty();

signals:
  void processed();

public slots:

private:
  QQueue<PumpServiceRequest> m_discs;
};
