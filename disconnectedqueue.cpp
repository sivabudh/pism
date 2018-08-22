#include "disconnectedqueue.h"

DisconnectedQueue::DisconnectedQueue(QObject *parent_)
  : QObject(parent_)
{

}

void DisconnectedQueue::append(const PumpServiceRequest request_)
{
  this->m_discs.append(request_);
}

bool DisconnectedQueue::isEmpty()
{
  return this->m_discs.isEmpty();
}
