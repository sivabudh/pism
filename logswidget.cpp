#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPlainTextEdit>

#include "logswidget.h"

LogsWidget::LogsWidget(QWidget *parent_)
  : QGroupBox(parent_)
{
  this->setTitle("Logs");

  this->textEdit = new QPlainTextEdit();
  this->textEdit->setReadOnly(true);

  auto layout = new QGridLayout;
  layout->addWidget(this->textEdit);
  layout->setContentsMargins(1, 1, 1, 1);

  this->setLayout(layout);
}

void LogsWidget::append(const QString newText_)
{
  this->textEdit->appendPlainText(newText_);
}
