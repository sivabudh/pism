#pragma once

#include <QWidget>

#include "logswidget.h"

class GilbarcoWidget : public QWidget
{
  Q_OBJECT

public:
  explicit GilbarcoWidget(QWidget *parent_ = nullptr);

public:
  LogsWidget * logs;

signals:
  void buttonClicked(QEvent *);

private:
};
