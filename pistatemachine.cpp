#include <QState>

#include "pistatemachine.h"
#include "disconnectedtransitions.h"


PiStateMachine::PiStateMachine(QObject * parent_)
  : QObject(parent_)
  , discs(this)
{
  auto disconnected = new QState(&this->sm);
  disconnected->addTransition(
        new DisconnectedProcessedTransition(&this->discs)
  );
}

void PiStateMachine::processClientCommand(const PITHUNDER::Messages)
{

}

void PiStateMachine::processConnectedPumpRequest(const PumpID)
{

}

void PiStateMachine::start()
{
  this->sm.start();
}

void PiStateMachine::processDisconnectedPumpRequest(const PumpID)
{

}

void PiStateMachine::resume()
{

}
