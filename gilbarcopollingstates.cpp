#include "gilbarcopollingstates.h"

PollState::PollState(QState * parent_)
  : QState(parent_)
{

}

void PollState::onEntry(QEvent *)
{
  // TODO: Implemented with action of state
}

ProcessCallState::ProcessCallState(QState * parent_)
  : QState(parent_)
{

}

void ProcessCallState::onEntry(QEvent *)
{
  // TODO: Implemented with action of state
}

PreState::PreState(QState * parent_)
  : QState(parent_)
{

}

void PreState::onEntry(QEvent *)
{
  // TODO: Implemented with action of state
}

ExternalState::ExternalState(QState * parent_)
  : QState(parent_)
{

}

void ExternalState::onEntry(QEvent *)
{
  // TODO: Implemented with action of state
}
