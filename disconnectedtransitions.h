#pragma once

#include <QSignalTransition>

class DisconnectedQueue;

class DisconnectedProcessedTransition : public QSignalTransition
{
public:
  DisconnectedProcessedTransition(DisconnectedQueue *);

  bool eventTest(QEvent *) override;
};
