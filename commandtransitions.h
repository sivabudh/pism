#pragma once

#include <QSignalTransition>

class CommandQueue;

class CommandNotEmptyTransition : public QSignalTransition
{
public:
  CommandNotEmptyTransition(CommandQueue *);

  bool eventTest(QEvent *) override;
};


class CommandEmptyTransition : public QSignalTransition
{
public:
  CommandEmptyTransition(CommandQueue *);

  bool eventTest(QEvent *) override;
};
