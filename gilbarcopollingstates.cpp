#include "gilbarcopollingstates.h"

PollState::PollState(QState * parent_)
  : QState(parent_)
{

}

void PollState::onEntry(QEvent *)
{

}

ProcessCallState::ProcessCallState(QState * parent_)
  : QState(parent_)
{

}

void ProcessCallState::onEntry(QEvent *)
{

}

PreState::PreState(QState * parent_)
  : QState(parent_)
{

}

void PreState::onEntry(QEvent *)
{

}

ExternalState::ExternalState(QState * parent_)
  : QState(parent_)
{

}

void ExternalState::onEntry(QEvent *)
{

}
