#pragma once

#include <QEvent>

class CallEvent : public QEvent
{
public:
  static const int id = QEvent::User+100;

public:
  CallEvent();
};

class PreviousCallEvent : public QEvent
{
public:
  static const int id = QEvent::User+101;

public:
  PreviousCallEvent();
};

class PreviousOffEvent : public QEvent
{
public:
  static const int id = QEvent::User+102;

public:
  PreviousOffEvent();
};

class DEvent : public QEvent
{
public:
  static const int id = QEvent::User+103;

public:
  DEvent();
};

class NozzleNumberEvent : public QEvent
{
public:
  static const int id = QEvent::User+104;

public:
  NozzleNumberEvent();
};
