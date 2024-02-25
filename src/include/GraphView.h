#ifndef CPP3_SMARTCALC_V2_0_1_GRAPHVIEW_H
#define CPP3_SMARTCALC_V2_0_1_GRAPHVIEW_H

#include <QDialog>

#include "qcustomplot.h"
#include "ui_graph.h"

namespace s21 {
class GraphView : public QDialog {
  Q_OBJECT

 signals:
  void ExecuteSig(const QString& expr, double x);

 public:
  explicit GraphView(const QString& expr, QMainWindow* parent = nullptr);
  ~GraphView() override;

  void UpdateY(double y);
  void PlotGraph();

 private:
  Ui::Graph* ui_;
  QCustomPlot* plot_;
  const QString& expr_;
  double y_;

 private slots:
  void on_plotButton_clicked();
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_GRAPHVIEW_H
