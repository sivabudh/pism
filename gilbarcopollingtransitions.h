#pragma once

#include <QSignalTransition>

class CallTransition : public QSignalTransition
{
public:
  bool eventTest(QEvent *) override;
};


class PreviousOffTransition : public QSignalTransition
{
public:
  bool eventTest(QEvent *) override;
};

class PreviousCallTransition : public QSignalTransition
{
public:
  bool eventTest(QEvent *) override;
};

class DTransition : public QSignalTransition
{
public:
  bool eventTest(QEvent *) override;
};

class NozzleNumberTransition : public QSignalTransition
{
public:
  bool eventTest(QEvent *) override;
};

