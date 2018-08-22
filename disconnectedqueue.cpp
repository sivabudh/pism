#include <QTimer>

#include "disconnectedqueue.h"

DisconnectedQueue::DisconnectedQueue(QObject *parent_)
  : QObject(parent_)
{
  QTimer::singleShot(1000, [=]() {
    emit processed(this->numProcessed++);
  });
}

void DisconnectedQueue::append(const PumpServiceRequest request_)
{
  this->discs.append(request_);
}

bool DisconnectedQueue::isEmpty()
{
  return this->discs.isEmpty();
}
