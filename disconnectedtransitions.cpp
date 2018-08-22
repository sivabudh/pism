#include <QDebug>
#include "disconnectedtransitions.h"

DisconnectedProcessedTransition::DisconnectedProcessedTransition(DisconnectedQueue * queue_)
  : QSignalTransition(queue_, SIGNAL(processed()))
{}

bool DisconnectedProcessedTransition::eventTest(QEvent * e_)
{
  if(!QSignalTransition::eventTest(e_))
    return false;

  // When received processed, unconditionally transition
  return true;
}
