#include "gilbarcoevents.h"

enum class GilbarcoEvent

{
  call = QEvent::User+1000,
  previous_call,
  previous_off,
  d,
  nozzle_number
};

CallEvent::CallEvent()
  : QEvent(QEvent::Type(GilbarcoEvent::call))
{}

PreviousCallEvent::PreviousCallEvent()
  : QEvent(QEvent::Type(GilbarcoEvent::previous_call))
{}

PreviousOffEvent::PreviousOffEvent()
  : QEvent(QEvent::Type(GilbarcoEvent::previous_off))
{}

DEvent::DEvent()
  : QEvent(QEvent::Type(GilbarcoEvent::d))
{}

NozzleNumberEvent::NozzleNumberEvent()
  : QEvent(QEvent::Type(GilbarcoEvent::nozzle_number))
{}
