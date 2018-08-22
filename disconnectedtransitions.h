#pragma once

#include <QStateMachine>
#include <QSignalTransition>

#include "disconnectedqueue.h"

class DisconnectedProcessedTransition : public QSignalTransition
{
public:
  DisconnectedProcessedTransition(DisconnectedQueue * queue_);

  bool eventTest(QEvent * e_) override;
};
