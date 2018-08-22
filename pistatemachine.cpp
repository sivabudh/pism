#include <QDebug>
#include <QState>
#include <QFinalState>

#include "pistatemachine.h"
#include "disconnectedtransitions.h"
#include "commandtransitions.h"


PiStateMachine::PiStateMachine(QObject * parent_)
  : QObject(parent_)
  , discs(this)
  , comms(this)
{
  auto disconnectedState = new QState(&this->sm);
  auto commandState = new QState(&this->sm);
  auto finalState = new QFinalState(&this->sm);

  {
    this->sm.setInitialState(disconnectedState);

    connect(disconnectedState, &QState::entered,
            &this->discs, &DisconnectedQueue::process);

    {
      auto outTransition = new DisconnectedProcessedTransition(&this->discs);
      disconnectedState->addTransition(outTransition);
      outTransition->setTargetState(commandState);
    }

    connect(&this->discs, &DisconnectedQueue::currentPump,
            this, &PiStateMachine::currentPump);
  }
  {
    this->sm.addState(commandState);

    connect(commandState, &QState::entered,
            &this->comms, &CommandQueue::process);

    {
      auto loopTransition = new CommandNotEmptyTransition(&this->comms);
      commandState->addTransition(loopTransition);
      loopTransition->setTargetState(commandState);
    }
    {
      auto outTransition = new CommandEmptyTransition(&this->comms);
      commandState->addTransition(outTransition);
      outTransition->setTargetState(finalState);
    }

    connect(&this->comms, &CommandQueue::currentPump,
            this, &PiStateMachine::currentPump);
  }
  {
    this->sm.addState(finalState);

    connect(finalState, &QState::entered, [](){
      qDebug() << "Final state entered and finished!";
    });
  }
}

void PiStateMachine::enqueueDisconnectedPumpRequest(const PumpServiceRequest request_)
{
  this->discs.append(request_);
}

void PiStateMachine::enqueueCommand(const PITHUNDER::Messages command_)
{
  this->comms.append(command_);
}


void PiStateMachine::start()
{
  this->sm.start();
}

void PiStateMachine::stop()
{
  this->sm.stop();
}
