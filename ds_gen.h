#ifndef DS_GEN_H
#define DS_GEN_H

#include <QtGui/QMainWindow>
#include "ui_ds_gen.h"

#include "zchart.h"
#include "parser.h"

#include <QVarLengthArray>

class ds_gen : public QMainWindow
{
    Q_OBJECT

public:
   /**
    * Конструктор основного класса приложения
    * @param parent  родительский виджет
    */
   ds_gen(QWidget *parent = 0);
    /**
     * Деструктор (пустой :) )
     */
    ~ds_gen();

private:
	/**
     * Функция реализует элементарный шаг интегрирования методом Эйлера
	 * @param  y  Вектор текущих значений, а потом там будут хранится следующий шаг
	 * @param  h  Шаг интегрирования
	 * @param  K  Сила связи
	 * @param  noise_lvl  Уровень шума
	 */
	void euler_step(QVector<double>& y, double& h, double& K, double& noise_lvl);
	/**
	 *    Функция реализует элементарный шаг интегрирования методом Рунге-Кутта
	 * @param  y  Вектор текущих значений, а потом там будут хранится следующий шаг
	 * @param  h  Шаг интегрирования
	 * @param  K  Сила связи
	 */
	void rk_step(QVector<double>& y, double& h, double& K);
	/**
	 *    Возвращает результат вычисления i-го уравнения системы для текущего момента
	 * @param  i  Номер уравнения
	 * @param  x  Переменная используется только в методе Рунге-Кутта для промежуточных шагов
	 * @param  y  Вектор значений нашей системы
	 * @param  K  Сила связи
	 * @return Возвращается вычисленное значение i-го уравнения
	 */
	double f(int& i, double& x, QVector<double>& y, double& K);
	/**
	 *    Функция реализует распределенный по Гауссу белый шум
	 * @return Возвращается значение распределенного по Гауссу булого шума
	 */
	double gauss();
	/**
	 * Класс интерфейса
	 */
    Ui::ds_genClass ui;
	/**
	 * Папка, где будут сохранятся файлы данных
	 */
    QString saveDirectory;
   	/**
	 * Начальные значения системы уравнений
	 */
	QVector <double> startValues;
	/**
	 * Спинбоксы, хранящие начальные значения системы уравнений
	 */
	QVector <QDoubleSpinBox *> startVsWidgets;
	/**
	 * Список уравнений системы
	 */
    QStringList eqnsList;
	/**
	 * Парсеры (по одному на каждое уравнение)
	 */
    QVector <myParser*> parsers;
	/**
	 * Используется для передачи параметров парсерам
	 */
    QVector <double> vars;
	/**
	 * Количество уравнений системы
	 */
    int eqnsNum;
   	/**
	 * График и соответствующие серии графиков
	 */
    ZChart *chart;
	/**
	 * Серии графиков (ведь неизвестно, сколько их будет ;) )
	 */
	QVector <ZSimpleSeries*> series;
	/**
	 * Виджеты, включающие те или иные серии графиков
	 */
	QVector <QCheckBox*> chkSeriesWidgets;

private slots:
    /**
     * Устанавливает глобально имя папки, куда сохранять файлы данных
     */
    void setSaveDirectory();
    /**
	 * Основная функция для генерации данных
     */
    void genDS();
    /**
	 * Строим графики
     */
    void drawGraph();
    /**
	 * Заполняем серии графиков данными из файлов
     */
    void prepareData();
    /**
	 * Открываем файл с профилем
     */
    void openProfile();
    /**
	 * Сохраняем профиль в файл
     */
    void saveProfile();
    /**
	 * Создаем новый профиль (просто обнуляем интерфейс)
     */
    void newProfile();
    /**
	 * Заполняем список уравнений и подготавливаем парсеры
     */
    void fillEqnsList();
    /**
	 * Задаем количество уравнений и делаем соответствующие приготовления
     */
    void setEqnsNum();
    /**
	 * Заполняем вектор начальных значений
     */
    void fillStartValues();
};

#endif // DS_GEN_H
