#include <QState>
#include <QFinalState>

#include "pistatemachine.h"
#include "disconnectedtransitions.h"


PiStateMachine::PiStateMachine(QObject * parent_)
  : QObject(parent_)
  , discs(this)
{
  auto finalState = new QFinalState();

  {
    auto processedTransition = new DisconnectedProcessedTransition(&this->discs);
    processedTransition->setTargetState(finalState);

    auto disconnected = new QState(&this->sm);
    disconnected->addTransition(processedTransition);

    this->sm.setInitialState(disconnected);
  }

  this->sm.addState(finalState);
}

void PiStateMachine::processDisconnectedPumpRequest(const PumpID)
{

}


void PiStateMachine::start()
{
  this->sm.start();
}
