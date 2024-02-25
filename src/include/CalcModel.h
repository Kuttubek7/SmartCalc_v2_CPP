#ifndef CPP3_SMARTCALC_V2_0_1_CALCMODEL_H
#define CPP3_SMARTCALC_V2_0_1_CALCMODEL_H

#include <list>
#include <stack>
#include <string>
#include <unordered_map>

namespace s21 {

/**
 * @brief Класс CalcModel представляет модель для вычисления арифметических
 * выражений и функций.
 */
using namespace std;
class CalcModel {
 public:
  /**
   * @brief Конструктор по умолчанию для объекта CalcModel.
   */
  CalcModel();

  /**
   * @brief Выполняет вычисление арифметического выражения.
   *
   * @param expr Строковое представление арифметического выражения.
   * @return Результат вычисления выражения.
   */
  [[nodiscard]] double Calculate(const string& expr) const;

  /**
   * @brief Обновляет значение переменной x для последующих вычислений.
   *
   * @param new_x Новое значение переменной x.
   */
  void UpdateX(double new_x) noexcept;

 private:
  double x_;  ///< Значение переменной x.

  const unordered_map<string, int> op_priority_{
      ///< Приоритеты операторов.
      {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"%", 2}, {"^", 3}, {"(", 0}};

  const unordered_map<string, int> func_priority_{
      ///< Приоритеты функций.
      {"sin", 4},  {"cos", 4},  {"tan", 4}, {"asin", 4}, {"acos", 4},
      {"atan", 4}, {"sqrt", 4}, {"ln", 4},  {"log", 4},
  };

  /**
   * @brief Преобразует выражение в постфиксную форму.
   *
   * @return Список строк с выражением в постфиксной форме.
   */
  [[nodiscard]] list<string> GetPostfixExpr(const string& expr) const;

  /**
   * @brief Анализирует входное арифметическое выражение.
   *
   * @return Список строк с анализированным выражением.
   */
  static list<string> Parse(const string& expr) noexcept;

  /**
   * @brief Выполняет операцию между двумя операндами.
   *
   * @param op Оператор (например, "+", "-", "*", "/").
   * @param a Первый операнд.
   * @param b Второй операнд.
   * @return Результат операции.
   */
  static double Execute(const string& op, double a, double b);

  /**
   * @brief Выполняет функцию на заданном значении.
   *
   * @param func Название функции (например, "sin", "cos").
   * @param x Значение аргумента функции.
   * @return Результат функции.
   */
  static double Execute(const string& func, double x);

  /**
   * @brief Проверяет, является ли строка числом с плавающей точкой.
   *
   * @param str Строка для проверки.
   * @return true, если строка представляет число, в противном случае - false.
   */
  static bool IsDouble(const string& str) noexcept;

  /**
   * @brief Проверяет, является ли строка оператором.
   *
   * @param str Строка для проверки.
   * @return true, если строка представляет оператор, в противном случае -
   * false.
   */
  [[nodiscard]] bool IsOperator(const string& str) const noexcept;

  /**
   * @brief Проверяет, является ли строка функцией.
   *
   * @param str Строка для проверки.
   * @return true, если строка представляет функцию, в противном случае - false.
   */
  [[nodiscard]] bool IsFunction(const string& str) const noexcept;

  /**
   * @brief Получает приоритет оператора или функции.
   *
   * @param str Строка с оператором или функцией.
   * @return Приоритет оператора или функции.
   */
  [[nodiscard]] int GetPriority(const string& str) const noexcept;

  /**
   * @brief Проверяет и валидирует арифметическое выражение.
   *
   * @param expr Список строк с арифметическим выражением.
   */
  static void ValidateExpr(list<string>& expr);
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CALCMODEL_H
