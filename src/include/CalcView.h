#ifndef CPP3_SMARTCALC_V2_0_1_CALCVIEW_H
#define CPP3_SMARTCALC_V2_0_1_CALCVIEW_H

#include <QMainWindow>

#include "ui_calc.h"

namespace s21 {
class CalcView : public QMainWindow {
  Q_OBJECT

 public:
  CalcView();
  ~CalcView() override;

  void SetText(const QString &text);
  QString GetText();
 signals:
  void SigExecuteButton();
  void SigGraphButton();

 private slots:
  void on_enterButtonGroup_buttonClicked(QAbstractButton *button);
  void on_ACButton_clicked();
  void on_divButton_clicked();
  void on_mulButton_clicked();

 private:
  Ui::SmartCalc *ui_;
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_1_CALCVIEW_H
