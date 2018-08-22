#include "commandtransitions.h"
#include "commandqueue.h"

CommandNotEmptyTransition::CommandNotEmptyTransition(CommandQueue * queue_)
  : QSignalTransition(queue_, SIGNAL(notEmpty()))
{}

bool CommandNotEmptyTransition::eventTest(QEvent * e_)
{
  if(!QSignalTransition::eventTest(e_))
    return false;

  return true;
}

CommandEmptyTransition::CommandEmptyTransition(CommandQueue * queue_)
  : QSignalTransition(queue_, SIGNAL(empty()))
{}

bool CommandEmptyTransition::eventTest(QEvent * e_)
{
  if(!QSignalTransition::eventTest(e_))
    return false;

  return true;
}
