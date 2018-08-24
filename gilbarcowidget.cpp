#include <QGridLayout>

#include "gilbarcowidget.h"

GilbarcoWidget::GilbarcoWidget(QWidget * parent_)
  : QWidget(parent_)
{
  this->logs = new LogsWidget(this);

  auto layout = new QGridLayout;
  layout->setContentsMargins(1, 1, 1, 1);
  layout->addWidget(logs, 0, 0);

  this->setLayout(layout);
  this->setWindowTitle("Gilbarco Protocol Tester");
}
