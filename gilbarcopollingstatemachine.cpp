#include <QDebug>
#include <QState>
#include <QFinalState>

#include "gilbarcopollingstatemachine.h"

GilbarcoPollingStateMachine::GilbarcoPollingStateMachine(QObject * parent_)
  : QObject(parent_)
{

  auto pollState = new QState(&this->sm);
  auto processCallState = new QState(&this->sm);
  auto preState = new QState(&this->sm);
  auto externalState = new QState(&this->sm);
  auto finalState = new QFinalState(&this->sm);

  {
    this->sm.setInitialState(pollState);

    {
      auto callTransition = new CallTransition();
      pollState->addTransition(callTransition);
      callTransition->setTargetState(processCallState);
    }
  }
  {
    this->sm.addState(processCallState);

    {
      auto offTransition = new PreviousOffTransition();
      processCallState->addTransition(offTransition);
      offTransition->setTargetState(preState);
    }
    {
      auto callTransition = new PreviousCallTransition();
      processCallState->addTransition(callTransition);
      callTransition->setTargetState(finalState);
    }
  }
  {
    this->sm.addState(preState);

    {
      auto dTransition = new DTransition();
      preState->addTransition(dTransition);
      dTransition->setTargetState(preState);
    }
  }
  {
    this->sm.addState(externalState);

    {
      auto nozzleNumberTransition = new NozzleNumberTransition();
      externalState->addTransition(nozzleNumberTransition);
      nozzleNumberTransition->setTargetState(finalState);
    }
  }
  {
    this->sm.addState(finalState);

    connect(finalState, &QState::entered, [](){
      qDebug() << "Final state entered and is finished!";
    });
  }
}

void GilbarcoPollingStateMachine::start()
{

}
