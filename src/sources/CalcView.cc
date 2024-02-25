#include "CalcView.h"
s21::CalcView::CalcView() : QMainWindow(nullptr), ui_(new Ui::SmartCalc) {
  ui_->setupUi(this);
  connect(ui_->equalButton, &QPushButton::clicked, this,
          &CalcView::SigExecuteButton);
  connect(ui_->graphButton, &QPushButton::clicked, this,
          &CalcView::SigGraphButton);
}

s21::CalcView::~CalcView() { delete ui_; }

void s21::CalcView::on_enterButtonGroup_buttonClicked(QAbstractButton *button) {
  if (GetText() == "0" || GetText() == "ERROR" || GetText() == "nan" ||
      GetText() == "inf")
    SetText(button->text());
  else
    SetText(GetText() + button->text());
}
void s21::CalcView::SetText(const QString &text) {
  ui_->lineEdit->setText(text);
}
QString s21::CalcView::GetText() { return ui_->lineEdit->text(); }

void s21::CalcView::on_ACButton_clicked() { SetText("0"); }
void s21::CalcView::on_divButton_clicked() { SetText(GetText() + "/"); }
void s21::CalcView::on_mulButton_clicked() { SetText(GetText() + "*"); }
