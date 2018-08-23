#include "gilbarcopollingtransitions.h"

bool CallTransition::eventTest(QEvent *)
{
  return false;
}

bool PreviousOffTransition::eventTest(QEvent *)
{
  return false;
}

bool PreviousCallTransition::eventTest(QEvent *)
{
  return false;
}

bool DTransition::eventTest(QEvent *)
{
  return false;
}

bool NozzleNumberTransition::eventTest(QEvent *)
{
  return false;
}
