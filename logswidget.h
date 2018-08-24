#pragma once

#include <QGroupBox>

class QWidget;
class QPlainTextEdit;

class LogsWidget : public QGroupBox
{
  Q_OBJECT

public:
  LogsWidget(QWidget * parent_);

signals:

public slots:
  void append(QString const);

private:
  QPlainTextEdit * textEdit;
};
