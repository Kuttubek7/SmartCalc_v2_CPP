#ifndef CPP3_SMARTCALC_V2_0_1_CONTROLLER_H
#define CPP3_SMARTCALC_V2_0_1_CONTROLLER_H

#include <QObject>

#include "CalcModel.h"
#include "CalcView.h"
#include "GraphView.h"

namespace s21 {
class Controller : public QObject {
  Q_OBJECT

 public:
  Controller(CalcModel& model, CalcView& view);

 private slots:
  void OnExecuteButtonClicked();
  void OnGraphButtonClicked();
  void OnExecute(const QString& expr, double x);

 private:
  CalcModel& model_;
  CalcView& view_;
  GraphView* graph_;

  double Execute(const QString& expr, double x);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CONTROLLER_H
