#include "gilbarcopollingtransitions.h"
#include "gilbarcoevents.h"

bool CallTransition::eventTest(QEvent * event_)
{
  return event_->type() == CallEvent::id;
}

bool PreviousOffTransition::eventTest(QEvent * event_)
{
  return event_->type() == PreviousOffEvent::id;
}

bool PreviousCallTransition::eventTest(QEvent * event_)
{
  return event_->type() == PreviousCallEvent::id;
}

bool DTransition::eventTest(QEvent * event_)
{
  return event_->type() == DEvent::id;
}

bool NozzleNumberTransition::eventTest(QEvent * event_)
{
  return event_->type() == NozzleNumberEvent::id;
}
