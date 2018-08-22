#pragma once

#include <QObject>
#include <QQueue>

#include "pitypes.h"

class CommandQueue : public QObject
{

  Q_OBJECT
public:
  explicit CommandQueue(QObject *parent_);

  void append(PITHUNDER::Messages const);

signals:
  void currentPump(PumpID const);
  void notEmpty();
  void empty();

public slots:
  void process();

private:
  QQueue<PITHUNDER::Messages> queue;
};
