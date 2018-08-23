#pragma once

#include <QState>

#include "gilbarcoevents.h"

class PollState : public QState
{
public:
  PollState(QState *);

protected:

};


class ProcessCallState : public QState
{
public:
  ProcessCallState(QState *);

protected:
  void onEntry(QEvent *) override;
};


class PreState : public QState
{
public:
  PreState(QState *);

protected:
  void onEntry(QEvent *) override;
};


class ExternalState : public QState
{
public:
  ExternalState(QState *);

protected:
  void onEntry(QEvent *) override;
};
