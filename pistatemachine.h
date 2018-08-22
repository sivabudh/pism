#ifndef PISTATEMACHINE_H
#define PISTATEMACHINE_H

#include <QObject>

class PiStateMachine : public QObject
{
  Q_OBJECT
public:
  explicit PiStateMachine(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PISTATEMACHINE_H