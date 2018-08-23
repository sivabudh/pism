#include "gilbarcoevents.h"


CallEvent::CallEvent()
  : QEvent(QEvent::Type(this->id))
{}

PreviousCallEvent::PreviousCallEvent()
  : QEvent(QEvent::Type(this->id))
{}

PreviousOffEvent::PreviousOffEvent()
  : QEvent(QEvent::Type(this->id))
{}

DEvent::DEvent()
  : QEvent(QEvent::Type(this->id))
{}

NozzleNumberEvent::NozzleNumberEvent()
  : QEvent(QEvent::Type(this->id))
{}
