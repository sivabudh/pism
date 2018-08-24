#pragma once

#include <QState>
#include <QString>

#include "gilbarcoevents.h"

class PollState : public QState
{
  Q_OBJECT

public:
  PollState(QState *);

signals:
  void newLog(QString const);

protected:
  void onEntry(QEvent *) override;
};


class ProcessCallState : public QState
{
  Q_OBJECT

public:
  ProcessCallState(QState *);


signals:
  void newLog(QString const);

protected:
  void onEntry(QEvent *) override;
};


class PreState : public QState
{
  Q_OBJECT

public:
  PreState(QState *);

signals:
  void newLog(QString const);

protected:
  void onEntry(QEvent *) override;
};


class ExternalState : public QState
{
  Q_OBJECT

public:
  ExternalState(QState *);

signals:
  void newLog(QString const);

protected:
  void onEntry(QEvent *) override;
};
