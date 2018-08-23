#pragma once

#include <QObject>
#include <QStateMachine>

class GilbarcoPollingStateMachine : public QObject
{
  Q_OBJECT

public:
  GilbarcoPollingStateMachine(QObject * parent_);

public slots:
  void start();


private:
  QStateMachine sm;
};

