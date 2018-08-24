#include <QGridLayout>
#include <QPushButton>

#include "gilbarcowidget.h"
#include "gilbarcoevents.h"

GilbarcoWidget::GilbarcoWidget(QWidget * parent_)
  : QWidget(parent_)
{
  this->logs = new LogsWidget(this);

  auto callBtn = new QPushButton("Call", this);
  connect(callBtn, &QPushButton::clicked, [=]() {
    emit buttonClicked(new CallEvent);
  });
  auto previousOffBtn = new QPushButton("Previous Off", this);
  connect(previousOffBtn, &QPushButton::clicked, [=]() {
    emit buttonClicked(new PreviousOffEvent);
  });
  auto previousCallBtn = new QPushButton("Previous Call", this);
  connect(callBtn, &QPushButton::clicked, [=]() {
    emit buttonClicked(new CallEvent);
  });
  auto dBtn = new QPushButton("D", this);
  connect(dBtn, &QPushButton::clicked, [=]() {
    emit buttonClicked(new DEvent);
  });
  auto nozzleNumberBtn = new QPushButton("Nozzle Number", this);
  connect(nozzleNumberBtn, &QPushButton::clicked, [=]() {
    emit buttonClicked(new NozzleNumberEvent);
  });

  auto layout = new QGridLayout;
  layout->setContentsMargins(1, 1, 1, 1);
  layout->addWidget(logs, 0, 0);
  layout->addWidget(callBtn, 1, 0);
  layout->addWidget(previousOffBtn, 2, 0);
  layout->addWidget(previousCallBtn, 3, 0);
  layout->addWidget(dBtn, 4, 0);
  layout->addWidget(nozzleNumberBtn, 5, 0);

  this->setLayout(layout);
  this->setWindowTitle("Gilbarco Protocol Tester");
}
