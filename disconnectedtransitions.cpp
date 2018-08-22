#include "disconnectedtransitions.h"

DisconnectedProcessedTransition::DisconnectedProcessedTransition(DisconnectedQueue * queue_)
  : QSignalTransition(queue_, SIGNAL(processed()))
  , queue(queue_)
{}

bool DisconnectedProcessedTransition::eventTest(QEvent * e_)
{
  if(!QSignalTransition::eventTest(e_))
    return false;

  return this->queue->isEmpty();
}
