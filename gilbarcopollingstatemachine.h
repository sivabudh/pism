#pragma once

#include <QObject>
#include <QStateMachine>

class GilbarcoPollingStateMachine : public QObject
{
  Q_OBJECT

public:
  GilbarcoPollingStateMachine(QObject * parent_);

signals:
  void newLog(QString const);

public slots:
  void start();
  void postEvent(QEvent *);

private:
  QStateMachine sm;
};

