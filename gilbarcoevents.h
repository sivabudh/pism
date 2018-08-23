#pragma once

#include <QEvent>

enum class GilbarcoEvent
{
  call = QEvent::User+1000,
  previous_call,
  previous_off,
  d,
  nozzle_number
};

class CallEvent : public QEvent
{
public:
  CallEvent()
    : QEvent(QEvent::Type(GilbarcoEvent::call))
  {}
};

class PreviousCallEvent : public QEvent
{
public:
  PreviousCallEvent()
    : QEvent(QEvent::Type(GilbarcoEvent::previous_call))
  {}
};

class PreviousOffEvent : public QEvent
{
public:
  PreviousOffEvent()
    : QEvent(QEvent::Type(GilbarcoEvent::previous_off))
  {}
};

class DEvent : public QEvent
{
public:
}
