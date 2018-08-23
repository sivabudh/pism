#pragma once

#include <QEvent>


class CallEvent : public QEvent
{
public:
  CallEvent();
};

class PreviousCallEvent : public QEvent
{
public:
  PreviousCallEvent();
};

class PreviousOffEvent : public QEvent
{
public:
  PreviousOffEvent();
};

class DEvent : public QEvent
{
public:
  DEvent();
};

class NozzleNumberEvent : public QEvent
{
public:
  NozzleNumberEvent();
};
