#include <QMainWindow>

#include "Controller.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  s21::CalcView view;
  s21::CalcModel model;
  s21::Controller controller{model, view};
  view.show();
  return QApplication::exec();
}