#include "Controller.h"

#include <QInputDialog>

s21::Controller::Controller(s21::CalcModel& model, CalcView& view)
    : model_(model), view_(view), graph_(nullptr) {
  connect(&view_, &CalcView::SigExecuteButton, this,
          &Controller::OnExecuteButtonClicked);
  connect(&view_, &CalcView::SigGraphButton, this,
          &Controller::OnGraphButtonClicked);
}

void s21::Controller::OnExecuteButtonClicked() {
  try {
    double x = 0;
    if (view_.GetText().contains("X"))
      x = QInputDialog::getDouble(&view_, tr("Введите X"), tr("X = "));
    auto result = Execute(view_.GetText(), x);
    view_.SetText(QString::number(result));
  } catch (std::invalid_argument& ex) {
    view_.SetText(ex.what());
  }
}

double s21::Controller::Execute(const QString& expr, double x) {
  try {
    model_.UpdateX(x);
    auto result = model_.Calculate(expr.toStdString());
    return result;
  } catch (...) {
    throw std::invalid_argument("ERROR");
  }
}

void s21::Controller::OnGraphButtonClicked() {
  graph_ = new GraphView(view_.GetText());
  connect(graph_, &GraphView::ExecuteSig, this, &Controller::OnExecute);
  graph_->PlotGraph();
  graph_->setAttribute(Qt::WA_DeleteOnClose);
  graph_->exec();
}
void s21::Controller::OnExecute(const QString& expr, double x) {
  try {
    auto new_y = Execute(expr, x);
    graph_->UpdateY(new_y);
  } catch (...) {
    graph_->UpdateY(0.0);
  }
}
