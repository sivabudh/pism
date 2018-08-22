#include "disconnectedqueue.h"

DisconnectedQueue::DisconnectedQueue(QObject *parent_)
  : QObject(parent_)
{
}

void DisconnectedQueue::append(const PumpServiceRequest request_)
{
  this->discs.append(request_);
}

bool DisconnectedQueue::isEmpty()
{
  return this->discs.isEmpty();
}

void DisconnectedQueue::process()
{
  if(!this->discs.isEmpty())
  {
    auto pumpRequest = this->discs.dequeue();
    emit currentPump(pumpRequest.pumpId);
  }

  emit processed();
}
