#include <QDebug>
#include <QFinalState>

#include "gilbarcopollingstatemachine.h"
#include "gilbarcopollingtransitions.h"
#include "gilbarcopollingstates.h"

GilbarcoPollingStateMachine::GilbarcoPollingStateMachine(QObject * parent_)
  : QObject(parent_)
{

  auto pollState = new PollState(&this->sm);
  auto processCallState = new ProcessCallState(&this->sm);
  auto preState = new PreState(&this->sm);
  auto externalState = new ExternalState(&this->sm);
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
    {
      auto dTransition = new DTransition();
      preState->addTransition(dTransition);
      dTransition->setTargetState(externalState);
    }
  }
  {
    {
      auto nozzleNumberTransition = new NozzleNumberTransition();
      externalState->addTransition(nozzleNumberTransition);
      nozzleNumberTransition->setTargetState(finalState);
    }
  }
  {
    connect(finalState, &QState::entered, [=](){
      emit newLog("Final state entered and is finished!");
    });
  }

  connect(pollState, &PollState::newLog, this, &GilbarcoPollingStateMachine::newLog);
  connect(processCallState, &ProcessCallState::newLog, this, &GilbarcoPollingStateMachine::newLog);
  connect(preState, &PreState::newLog, this, &GilbarcoPollingStateMachine::newLog);
  connect(externalState, &ExternalState::newLog, this, &GilbarcoPollingStateMachine::newLog);
}

void GilbarcoPollingStateMachine::start()
{
  this->sm.start();
}

void GilbarcoPollingStateMachine::postEvent(QEvent * event_)
{
  this->sm.postEvent(event_);
}
