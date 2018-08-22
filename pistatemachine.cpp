#include <QDebug>
#include <QState>
#include <QFinalState>

#include "pistatemachine.h"
#include "disconnectedtransitions.h"


PiStateMachine::PiStateMachine(QObject * parent_)
  : QObject(parent_)
  , discs(this)
{
  auto finalState = new QFinalState();
  connect(finalState, &QState::entered, [](){
    qDebug() << "Final state entered and finished!";
  });

  {
    auto processedTransition = new DisconnectedProcessedTransition(&this->discs);
    processedTransition->setTargetState(finalState);

    auto disconnectedState = new QState(&this->sm);
    disconnectedState->addTransition(processedTransition);

    connect(disconnectedState, &QState::entered,
            &this->discs, &DisconnectedQueue::process);

    this->sm.setInitialState(disconnectedState);
  }

  this->sm.addState(finalState);

  connect(&this->discs, &DisconnectedQueue::currentPump,
          this, &PiStateMachine::currentPump);
}

void PiStateMachine::enqueueDisconnectedPumpRequest(const PumpServiceRequest request_)
{
  this->discs.append(request_);
}



void PiStateMachine::start()
{
  this->sm.start();
}
