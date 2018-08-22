#include "commandqueue.h"

CommandQueue::CommandQueue(QObject *parent_)
  : QObject(parent_)
{}

void CommandQueue::append(const PITHUNDER::Messages command_)
{
  this->queue.append(command_);
}

void CommandQueue::process()
{
  if(!this->queue.isEmpty())
  {
    auto pumpRequest = this->queue.dequeue();
    emit currentPump(pumpRequest.pumpId);
  }

  if(this->queue.isEmpty())
    emit empty();
  else
    emit notEmpty();
}
