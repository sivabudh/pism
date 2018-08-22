#include <QDebug>
#include "disconnectedtransitions.h"

DisconnectedProcessedTransition::DisconnectedProcessedTransition(DisconnectedQueue * queue_)
  : QSignalTransition(queue_, SIGNAL(processed(int)))
  , queue(queue_)
{}

bool DisconnectedProcessedTransition::eventTest(QEvent * e_)
{
  if(!QSignalTransition::eventTest(e_))
    return false;

  auto se = static_cast<QStateMachine::SignalEvent*>(e_);
  auto numDisconnectedProcessed = se->arguments().at(0).toInt();

  auto transitionToNextState = this->queue->isEmpty() || numDisconnectedProcessed >= 1;
  qDebug() << transitionToNextState;
  return transitionToNextState;
}
