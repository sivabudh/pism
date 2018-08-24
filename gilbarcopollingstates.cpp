#include "gilbarcopollingstates.h"

PollState::PollState(QState * parent_)
  : QState(parent_)
{

}

void PollState::onEntry(QEvent *)
{
  emit newLog("PollState");
}


ProcessCallState::ProcessCallState(QState * parent_)
  : QState(parent_)
{

}

void ProcessCallState::onEntry(QEvent *)
{
  emit newLog("ProcessCallState");
}

PreState::PreState(QState * parent_)
  : QState(parent_)
{

}

void PreState::onEntry(QEvent *)
{
  emit newLog("PreState");
}

ExternalState::ExternalState(QState * parent_)
  : QState(parent_)
{

}

void ExternalState::onEntry(QEvent *)
{
  emit newLog("ExternalState");
}
