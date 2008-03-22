#include "ds_gen.h"

#include <QFileDialog>
#include <QTextStream>
#include <QTime>
#include <QtGui>

#include <math.h>

void ds_gen::setSaveDirectory() {
    QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
    saveDirectory = QFileDialog::getExistingDirectory(this,
                    tr("QFileDialog::getExistingDirectory()"),
                    ".",
                    options);
}

void ds_gen::genDS() {
	// заполняем список уравнений и инициализируем парсеры в самый последний момент
    fillEqnsList();

    // исходя из заданных параметров, генерируем временные ряды
    // сначала в выбранной папке создаем файл с описанием того, что мы нагенерировали
    QFile fileDescr(saveDirectory+QString("/descr.info"));
    if (!fileDescr.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream outDescr(&fileDescr);
    outDescr << trUtf8("Уровень шума (noise_lvl): ")	<< ui.noise_lvlSBox->value() << "\n";
    outDescr << trUtf8("Сила связи от: ") << ui.forcecouplbSBox->value() << "\n";
    outDescr << trUtf8("Сила связи до: ") << ui.forcecoupleSBox->value() << "\n";
    outDescr << trUtf8("Сила связи шаг: ") << ui.forcecouplstepSBox->value() << "\n";
    outDescr << trUtf8("Ведомое: ") << ui.responseCBox->currentText() << "\n";
    outDescr << trUtf8("Ведущее: ") << ui.driverCBox->currentText() << "\n";
    outDescr << trUtf8("Тип связи: ") <<	ui.coupltypeCBox->currentText() << "\n";
    outDescr << trUtf8("Длина временного ряда от: ") <<	ui.serieslengthsSBox->value() << "\n";
    outDescr << trUtf8("Длина временного ряда до: ") <<	ui.serieslengtheSBox->value() << "\n";
    outDescr << trUtf8("Длина временного ряда шаг: ") <<	ui.serieslengthstepSBox->value() << "\n";
    outDescr << trUtf8("Шаг выборки от: ") << ui.seriesstepsSBox->value() << "\n";
    outDescr << trUtf8("Шаг выборки до: ") << ui.seriesstepeSBox->value() << "\n";
    outDescr << trUtf8("Шаг выборки шаг: ") << ui.seriesstepstepSBox->value() << "\n";
    outDescr << trUtf8("Метод интегрирования: ")	<< ui.methodCBox->currentText() << "\n";
    outDescr << trUtf8("Шаг интегрирования: ") << ui.intstepSBox->value() << "\n";
    outDescr << trUtf8("Тип данных: ") << ui.datatypeCBox->currentText() << "\n";
    outDescr << trUtf8("Тип временного ряда: ") << ui.timeseriestypeCBox->currentText() << "\n";
    outDescr << trUtf8("Кол-во уравнений: ") << ui.eqnsSBox->value() << "\n";
    for (int i = 0; i < startValues.size(); i++) {
        outDescr << trUtf8("Начальное значение x") << i+1 << ": " << startValues.at(i) << "\n";
    }
    outDescr << trUtf8("Уравнения:") << "\n";
    for (int i = 0; i < startValues.size(); i++) {
        outDescr << eqnsList.at(i) << "\n";
    }

    // создаем необходимые файлы и потоки данных
    QFile fileX1(saveDirectory+QString("/x1.txt"));
    QFile fileX2(saveDirectory+QString("/x2.txt"));
    QFile fileX3(saveDirectory+QString("/x3.txt"));
    QFile fileX4(saveDirectory+QString("/x4.txt"));
    QFile fileX5(saveDirectory+QString("/x5.txt"));
    QFile fileX6(saveDirectory+QString("/x6.txt"));
    if (!fileX1.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    if (!fileX2.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    if (!fileX3.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    if (!fileX4.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    if (!fileX5.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    if (!fileX6.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream outX1(&fileX1);
    QTextStream outX2(&fileX2);
    QTextStream outX3(&fileX3);
    QTextStream outX4(&fileX4);
    QTextStream outX5(&fileX5);
    QTextStream outX6(&fileX6);

    outX1.setRealNumberNotation(QTextStream::FixedNotation);
    outX2.setRealNumberNotation(QTextStream::FixedNotation);
    outX3.setRealNumberNotation(QTextStream::FixedNotation);
    outX4.setRealNumberNotation(QTextStream::FixedNotation);
    outX5.setRealNumberNotation(QTextStream::FixedNotation);
    outX6.setRealNumberNotation(QTextStream::FixedNotation);

    outX1.setRealNumberPrecision(6);
    outX2.setRealNumberPrecision(6);
    outX3.setRealNumberPrecision(6);
    outX4.setRealNumberPrecision(6);
    outX5.setRealNumberPrecision(6);
    outX6.setRealNumberPrecision(6);

    QDataStream outX1b(&fileX1);
    QDataStream outX2b(&fileX2);
    QDataStream outX3b(&fileX3);
    QDataStream outX4b(&fileX4);
    QDataStream outX5b(&fileX5);
    QDataStream outX6b(&fileX6);

    // инициализируем генератор псевдослучайных чисел
    QTime midnight(0, 0, 0);
    srand(midnight.msecsTo(QTime::currentTime()));

    // задаем начальные значения динамической системе
    QVector <double> tmpPoint;
    for (int i = 0; i < startValues.size(); i++) {
        tmpPoint.append(startValues.at(i));
    }

    // корректируем интервалы
    if (ui.forcecouplbSBox->value() > ui.forcecoupleSBox->value())
        ui.forcecoupleSBox->setValue(ui.forcecouplbSBox->value());
    if (ui.serieslengthsSBox->value() > ui.serieslengtheSBox->value())
        ui.serieslengtheSBox->setValue(ui.serieslengthsSBox->value());
    // инициализируем прогресс-бар ХЗ КАК ПОКА
    ui.progressBar->reset();
    ui.progressBar->setMinimum(0);
    if (ui.timeseriestypeCBox->currentIndex() == 0)
        ui.progressBar->setMaximum(ui.serieslengthsSBox->value()
                                   +ui.serieslengthsSBox->value()
                                   *(int)((ui.forcecoupleSBox->value()-ui.forcecouplbSBox->value())/ui.forcecouplstepSBox->value()));
    if (ui.timeseriestypeCBox->currentIndex() == 1)
        ui.progressBar->setMaximum(ui.serieslengthsSBox->value()*ui.seriesstepsSBox->value()
                                   +ui.serieslengthsSBox->value()*ui.seriesstepsSBox->value()
                                   *(int)((ui.forcecoupleSBox->value()-ui.forcecouplbSBox->value())/ui.forcecouplstepSBox->value()));

    // создаем вспомогательные переменные, чтобы много раз в цикле к объектам класса не обращаться
    double K = ui.forcecouplbSBox->value();
    int method = ui.methodCBox->currentIndex();
    double intstep = ui.intstepSBox->value();
    double noise_lvl = ui.noise_lvlSBox->value();
    double seriesstep = ui.seriesstepsSBox->value();
    int datatype = ui.datatypeCBox->currentIndex();
    int serieslength = ui.serieslengthsSBox->value();

	// а это, чтобы время выполнения расчетов вывести можно было
    QTime t;
    t.start();

    // в цикле от начального значения силы связи до конечного генерируем..
    while (K <= ui.forcecoupleSBox->value()) {
		// если необходимо держать стартовые значения постоянными
        if (ui.conststartvaluesBox->isChecked())
            for (int i = 0; i < startValues.size(); i++) tmpPoint[i] = startValues.at(i);
        // если у нас фиксированный шаг выборки, но не количество получабющихся точек в ряде
        if (ui.timeseriestypeCBox->currentIndex() == 0) {
            // генерируем по всей длине ряда значения ДС, но выбираем только каждые сколько-то значений
            while (seriesstep <= ui.seriesstepeSBox->value()) {
				// если необходимо держать стартовые значения постоянными
                if (ui.conststartvaluesBox->isChecked())
                    for (int i = 0; i < startValues.size(); i++) tmpPoint[i] = startValues.at(i);
				// если длина временного ряда задается диапазоном
                while (serieslength <= ui.serieslengtheSBox->value()) {
					// если необходимо держать стартовые значения постоянными
                    if (ui.conststartvaluesBox->isChecked())
                        for (int i = 0; i < startValues.size(); i++) tmpPoint[i] = startValues.at(i);
					// основные расчеты, пробегаемся по всей длине временного ряда
                    for (int i = 0; i < serieslength; i++) {
                        if (method == 0) // метод Эйлера
                            euler_step(tmpPoint, intstep, K, noise_lvl);
                        if (method == 1) // метод Рунге-Кутты
                            rk_step(tmpPoint, intstep, K);
                        // записываем результаты в файлы данных с учетом параметра выборки..
                        double j = i/(double)seriesstep;
                        double iptr = 0;
						// это я так шаг выборки контролирую :)
                        if (modf(j, &iptr) < 0.001) {
                            if (datatype == 0) { // типа файл "Куте"
                                outX1b << (qreal)tmpPoint.at(0);
                                outX2b << (qreal)tmpPoint.at(1);
                                outX3b << (qreal)tmpPoint.at(2);
                                outX4b << (qreal)tmpPoint.at(3);
                                outX5b << (qreal)tmpPoint.at(4);
                                outX6b << (qreal)tmpPoint.at(5);
                            }
                            if (datatype == 1) { // просто текст
                                outX1 << (double)tmpPoint.at(0) << "\n";
                                outX2 << (double)tmpPoint.at(1) << "\n";
                                outX3 << (double)tmpPoint.at(2) << "\n";
                                outX4 << (double)tmpPoint.at(3) << "\n";
                                outX5 << (double)tmpPoint.at(4) << "\n";
                                outX6 << (double)tmpPoint.at(5) << "\n";
                            }
                        }
						// прогресс растет!
                        ui.progressBar->setValue(ui.progressBar->value()+1);
                    }
					// если значения интервалов были одинаковые, то немного увеличиваем соответствующий параметр
                    if (ui.serieslengthsSBox->value() == ui.serieslengtheSBox->value()) serieslength += 1;
                    serieslength += ui.serieslengthstepSBox->value();
                }
				// если значения интервалов были одинаковые, то немного увеличиваем соответствующий параметр
                if (ui.seriesstepsSBox->value() == ui.seriesstepeSBox->value())	seriesstep += 1;
                seriesstep += ui.seriesstepstepSBox->value();
            }
        }
        // если у нас задается сколько должно получится точек в файле данных, т.е. это значение фиксировано.
        if (ui.timeseriestypeCBox->currentIndex() == 1) {
            // пробегаем по всему ряду (см. камменты выше)
            while (seriesstep <= ui.seriesstepeSBox->value()) {
                if (ui.conststartvaluesBox->isChecked())
                    for (int i = 0; i < startValues.size(); i++)
                        tmpPoint[i] = startValues.at(i);
                while (serieslength <= ui.serieslengtheSBox->value()) {
                    if (ui.conststartvaluesBox->isChecked())
                        for (int i = 0; i < startValues.size(); i++)
                            tmpPoint[i] = startValues.at(i);
                    for (int i = 0; i < serieslength*seriesstep; i++) {
                        if (method == 0) // метод Эйлера
                            euler_step(tmpPoint, intstep, K, noise_lvl);
                        if (method == 1) // метод Рунге-Кутты
                            rk_step(tmpPoint, intstep, K);
                        // записываем результаты в файлы данных с учетом параметра выборки..
                        double iptr = 0;
                        double j = i/(double)seriesstep;
                        if (modf(j, &iptr) < 0.001) {
                            if (datatype == 0) {
                                outX1b << (qreal)tmpPoint.at(0);
                                outX2b << (qreal)tmpPoint.at(1);
                                outX3b << (qreal)tmpPoint.at(2);
                                outX4b << (qreal)tmpPoint.at(3);
                                outX5b << (qreal)tmpPoint.at(4);
                                outX6b << (qreal)tmpPoint.at(5);
                            }
                            if (datatype == 1) {
                                outX1 << (double)tmpPoint.at(0) << "\n";
                                outX2 << (double)tmpPoint.at(1) << "\n";
                                outX3 << (double)tmpPoint.at(2) << "\n";
                                outX4 << (double)tmpPoint.at(3) << "\n";
                                outX5 << (double)tmpPoint.at(4) << "\n";
                                outX6 << (double)tmpPoint.at(5) << "\n";
                            }
                        }
                        ui.progressBar->setValue(ui.progressBar->value()+1);
                    }
                    if (ui.serieslengthsSBox->value() == ui.serieslengtheSBox->value()) serieslength += 1;
                    serieslength += ui.serieslengthstepSBox->value();
                }
                if (ui.seriesstepsSBox->value() == ui.seriesstepeSBox->value())	seriesstep += 1;
                seriesstep += ui.seriesstepstepSBox->value();
            }
        }
        // если у нас надо только при одном значении силы связи сделать расчеты, то специально прибавляем текущее значение, чтобы оно вышло за установленные пределы
        if (ui.forcecouplbSBox->value() == ui.forcecoupleSBox->value())	K+= 1;
        K += ui.forcecouplstepSBox->value();
    }
	// обнуляем прогрессбар
    ui.progressBar->reset();
	// показываем время затраченное на операцию
    QString str = QString("%1").arg(t.elapsed());
    ui.elapsedTime->setText(QString(trUtf8("Выполнено за: "))+str+QString(trUtf8("мс")));
}

double ds_gen::gauss() {
	// взятое из книги Кнута.
    double x;
    int i, N_cycle = 10;
    x = 0.0;
    for (i = 0; i < N_cycle; i++) {
        x = x + rand()/(RAND_MAX+1.0);
    }
    x = x-0.5*N_cycle;
    x = x/sqrt(N_cycle/12.0);
    return x ;
}

double ds_gen::f(int &i, double &x, QVector<double>& y, double &K) {
	if (ui.methodCBox->currentIndex() == 1) {
		// для совместимости с методом Рунге-Кутта вместо y.a(0) подставляем x
		vars[0] = x;
		// заполняем массив переменными (из массива vars они автоматически подхватятся парсерами)
		for (int j = 1; j < y.size(); j++) {
			vars[j] = y.at(j);
		}
	}
	if (ui.methodCBox->currentIndex() == 0) {
		// заполняем массив переменными (из массива vars они автоматически подхватятся парсерами)
		for (int j = 0; j < y.size(); j++) {
			vars[j] = y.at(j);
		}
	}
	// последний элемент vars зарезервирован для значения силы связи
    vars[y.size()] = K;
	// вычисляем только нужный парсер
    return parsers.at(i)->Eval();
}

void ds_gen::euler_step(QVector<double>& y, double &h, double &K, double &noise_lvl) {
    float f_pred, u_n, u_n1;
    // временный массив значений переменных
    QVector <double> ytmp;
    ytmp.resize(eqnsNum);
    // для совместимости с Р-К
    double x = y.at(0);
    // пробегаемся и вычисляем новые значения для каждого уравнения
    for (int i = 0; i < eqnsNum; i++) {
        // новое состояние ДС
        f_pred = f(i, x, y, K);
        // текущее состояние ДС
        u_n = y[i];
        // итог - то что было, плюс то что будет, с поправкой на шаг интегрирования
        u_n1 = u_n + h*f_pred+noise_lvl*gauss()*sqrt(h);
        // добавляем новое рассчитанное состояние во временный массив
        ytmp[i] = u_n1;
    }
    // переносим то что получилось в то, что было
    for (int i = 0; i < eqnsNum; i++) {
        y[i] = ytmp.at(i);
    }
}

void ds_gen::rk_step(QVector<double>& y, double &h, double &K) {
    int i;
    QVector<double> yt, k1, k2, k3, k4;
    double x = y.at(0);
    for (i = 0; i < eqnsNum; i++) {
        k1.append(h*f(i, x, y, K));
    }
    for (i = 0; i < eqnsNum; i++) {
        yt.append(y.at(i)+0.5*k1.at(i));
    }
    for (i = 0; i < eqnsNum; i++) {
        double tmp = x+k1.at(0)*0.5;
        k2.append(h*f(i, tmp, y, K));
    }
    yt.clear();
    for (i = 0; i < eqnsNum; i++) {
        yt.append(y.at(i)+0.5*k2.at(i));
    }
    for (i = 0; i < eqnsNum; i++) {
        double tmp = x+k2.at(0)*0.5;
        k3.append(h*f(i, tmp, y, K));
    }
    yt.clear();
    for (i = 0; i < eqnsNum; i++) {
        yt.append(y.at(i)+k3.at(i));
    }
    for (i = 0; i < eqnsNum; i++) {
        double tmp = x+k3.at(0)*0.5;
        k4.append(h*f(i, tmp, y, K));
    }
    for (i = 0; i < eqnsNum; i++) {
        y[i] = y.at(i)+double(k1.at(i)+2.0*k2.at(i)
                              +2.0*k3.at(i)+k4.at(i))/double(6);
    }
}

void ds_gen::drawGraph() {
	// отрисовываем только помеченные графики
    chart->removeSeries();

	for( int i = 0; i < chkSeriesWidgets.size(); i++){
		if (chkSeriesWidgets.at(i)->isChecked()) chart->addSeries(series.at(i));
	}

    chart->autoscale();
    chart->update();
}

void ds_gen::prepareData() {
	// считываем данные из файлов и заполняем соответствующие серии графиков
	for (int i = 0; i < series.size(); i++) {
		series.at(i)->clear();
	}
    if (ui.datatypeCBox->currentIndex() == 1) {
		for (int i = 0; i < series.size(); i++) {
			QFile fileX1(saveDirectory+QString("/x%1.txt").arg(i+1));
			fileX1.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream inX1(&fileX1);
			int j = 0;
			while (!inX1.atEnd()) {
				QString line = inX1.readLine();
				series.at(i)->add(j, line.toFloat());
				j++;
			}
		}
    }
	if (ui.datatypeCBox->currentIndex() == 0) {
		for (int i = 0; i < series.size(); i++) {
			QFile fileX1(saveDirectory+QString("/x%1.txt").arg(i+1));
			fileX1.open(QIODevice::ReadOnly);
			QDataStream inX1(&fileX1);
			int j = 0;
			while (!inX1.atEnd()) {
				qreal x;
				inX1 >> x;
				series.at(i)->add(j, x);
				j++;
			}
		}
	}
	// и рисуем сразу :)
    drawGraph();
}

void ds_gen::openProfile() {
	// открываем файл профиля
    QString profileFileName = QFileDialog::getOpenFileName(this,
                              trUtf8("Выберите файл с профилем"),
                              ".",
                              tr("*.*"));
    QFile profileFile(profileFileName);
    if (!profileFile.open(QIODevice::ReadOnly | QIODevice::Text)) return;
	// в профиле все параметры задаются через двоеточие, чем мы и воспользуемся (конфиг чувствителен к регистру)
    QTextStream in(&profileFile);
    QString line;
    line = in.readLine();
    ui.noise_lvlSBox->setValue(line.split(":", QString::SkipEmptyParts).last().toFloat());
    line = in.readLine();
    ui.forcecouplbSBox->setValue(line.split(":", QString::SkipEmptyParts).last().toFloat());
    line = in.readLine();
    ui.forcecoupleSBox->setValue(line.split(":", QString::SkipEmptyParts).last().toFloat());
    line = in.readLine();
    ui.forcecouplstepSBox->setValue(line.split(":", QString::SkipEmptyParts).last().toFloat());
    line = in.readLine();
    ui.responseCBox->setCurrentIndex(ui.responseCBox->findText(line.split(":", QString::SkipEmptyParts).last().trimmed()));
    line = in.readLine();
    ui.driverCBox->setCurrentIndex(ui.driverCBox->findText(line.split(":", QString::SkipEmptyParts).last().trimmed()));
    line = in.readLine();
    ui.coupltypeCBox->setCurrentIndex(ui.coupltypeCBox->findText(line.split(":", QString::SkipEmptyParts).last().trimmed()));
    line = in.readLine();
    ui.serieslengthsSBox->setValue(line.split(":", QString::SkipEmptyParts).last().toInt());
    line = in.readLine();
    ui.serieslengtheSBox->setValue(line.split(":", QString::SkipEmptyParts).last().toInt());
    line = in.readLine();
    ui.serieslengthstepSBox->setValue(line.split(":", QString::SkipEmptyParts).last().toInt());
    line = in.readLine();
    ui.seriesstepsSBox->setValue(line.split(":", QString::SkipEmptyParts).last().toInt());
    line = in.readLine();
    ui.seriesstepeSBox->setValue(line.split(":", QString::SkipEmptyParts).last().toInt());
    line = in.readLine();
    ui.seriesstepstepSBox->setValue(line.split(":", QString::SkipEmptyParts).last().toInt());
    line = in.readLine();
    ui.methodCBox->setCurrentIndex(ui.methodCBox->findText(line.split(":", QString::SkipEmptyParts).last().trimmed()));
    line = in.readLine();
    ui.intstepSBox->setValue(line.split(":", QString::SkipEmptyParts).last().toFloat());
    line = in.readLine();
    ui.datatypeCBox->setCurrentIndex(ui.datatypeCBox->findText(line.split(":", QString::SkipEmptyParts).last().trimmed()));
    line = in.readLine();
    ui.timeseriestypeCBox->setCurrentIndex(ui.timeseriestypeCBox->findText(line.split(":", QString::SkipEmptyParts).last().trimmed()));
    line = in.readLine();
    ui.eqnsSBox->setValue(line.split(":", QString::SkipEmptyParts).last().toInt());
    startValues.clear();
    for (int i = 0; i < ui.eqnsSBox->value(); i++) {
        line = in.readLine();
        startValues.append(line.split(":", QString::SkipEmptyParts).last().toFloat());
        startVsWidgets.at(i)->setValue(line.split(":", QString::SkipEmptyParts).last().toFloat());
    }
    line = in.readLine();
    ui.dssummaryTEdit->setText("");
    eqnsList.clear();
    for (int i = 0; i < startValues.size(); i++) {
        line = in.readLine();
        ui.dssummaryTEdit->setText(ui.dssummaryTEdit->toPlainText()+line+"\n");
        eqnsList.append(line);
    }
}

void ds_gen::saveProfile() {
	// открываем файл куда сохранять
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    QString profileFileName;
    QStringList strl;
    if (dialog.exec())
        strl = dialog.selectedFiles();
    profileFileName = strl.at(0);
    QFile profileFile(profileFileName);
    if (!profileFile.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream out(&profileFile);
	// сохраняем в том же порядке, в каком и считывали
    out << trUtf8("Уровень шума (noise_lvl): ")	<< ui.noise_lvlSBox->value() << "\n";
    out << trUtf8("Сила связи от: ") << ui.forcecouplbSBox->value() << "\n";
    out << trUtf8("Сила связи до: ") << ui.forcecoupleSBox->value() << "\n";
    out << trUtf8("Сила связи шаг: ") << ui.forcecouplstepSBox->value() << "\n";
    out << trUtf8("Ведомое: ") << ui.responseCBox->currentText() << "\n";
    out << trUtf8("Ведущее: ") << ui.driverCBox->currentText() << "\n";
    out << trUtf8("Тип связи: ") <<	ui.coupltypeCBox->currentText() << "\n";
    out << trUtf8("Длина временного ряда от: ") <<	ui.serieslengthsSBox->value() << "\n";
    out << trUtf8("Длина временного ряда до: ") <<	ui.serieslengtheSBox->value() << "\n";
    out << trUtf8("Длина временного ряда шаг: ") <<	ui.serieslengthstepSBox->value() << "\n";
    out << trUtf8("Шаг выборки от: ") << ui.seriesstepsSBox->value() << "\n";
    out << trUtf8("Шаг выборки до: ") << ui.seriesstepeSBox->value() << "\n";
    out << trUtf8("Шаг выборки шаг: ") << ui.seriesstepstepSBox->value() << "\n";
    out << trUtf8("Метод интегрирования: ")	<< ui.methodCBox->currentText() << "\n";
    out << trUtf8("Шаг интегрирования: ") << ui.intstepSBox->value() << "\n";
    out << trUtf8("Тип данных: ") << ui.datatypeCBox->currentText() << "\n";
    out << trUtf8("Тип временного ряда: ") << ui.timeseriestypeCBox->currentText() << "\n";
    out << trUtf8("Кол-во уравнений: ") << ui.eqnsSBox->value() << "\n";
    for (int i = 0; i < startValues.size(); i++) {
        out << trUtf8("Начальное значение x") << i+1 << ": " << startValues.at(i) << "\n";
    }
    out << trUtf8("Уравнения:") << "\n";
    for (int i = 0; i < startValues.size(); i++) {
        out << eqnsList.at(i) << "\n";
    }
}

void ds_gen::newProfile() {
	// создание профиля == обнуление в дефаулт интерфейса :)
    ui.noise_lvlSBox->setValue(0.0);
    ui.forcecouplbSBox->setValue(0.0);
    ui.forcecoupleSBox->setValue(0.0);
    ui.forcecouplstepSBox->setValue(0);
    ui.responseCBox->setCurrentIndex(0);
    ui.driverCBox->setCurrentIndex(0);
    ui.coupltypeCBox->setCurrentIndex(0);
    ui.serieslengthsSBox->setValue(0);
    ui.serieslengtheSBox->setValue(0);
    ui.serieslengthstepSBox->setValue(0);
    ui.seriesstepsSBox->setValue(0);
    ui.seriesstepeSBox->setValue(0);
    ui.seriesstepstepSBox->setValue(0);
    ui.methodCBox->setCurrentIndex(0);
    ui.intstepSBox->setValue(0.0);
    ui.datatypeCBox->setCurrentIndex(0);
    ui.timeseriestypeCBox->setCurrentIndex(0);
    ui.dssummaryTEdit->setText(QString(""));
}

void ds_gen::fillEqnsList() {
	// то что написано в редакторе, разделяем на уравнения
    QString completeList = ui.dssummaryTEdit->toPlainText();
	eqnsList = completeList.split("\n", QString::SkipEmptyParts);
	// заполняем комбобоксы с выбором переменных в которые можно связь вставить
    ui.responseCBox->clear();
    ui.driverCBox->clear();
    for (int i = 0; i < eqnsList.size()-1; i++) {
        ui.responseCBox->addItem(QString("x%1").arg(i+1));
        ui.driverCBox->addItem(QString("x%1").arg(i+1));
    }
    // заполняем вектор парсерами (по парсеру на каждое уравнение)
    vars.resize(eqnsList.size()+1);
    parsers.clear();
    parsers.resize(0);
    for (int i = 0; i < eqnsList.size(); i++) {
		// парсеры создаем указателями и пихаем в вектор
        myParser *parserI = new myParser;
        parsers.append(parserI);
		// текущее уравнение проверяем на участие в связи с другим уравнением ;)
        QString eqi = eqnsList.at(i);
        if (ui.responseCBox->currentIndex() == i) {
            if (ui.coupltypeCBox->currentIndex() == 0) {
                eqi += QString("+K*%1").arg(ui.driverCBox->currentIndex()+1);
            }
			// связь может быть 2х типов ))
            if (ui.coupltypeCBox->currentIndex() == 1) {
                eqi += QString("+K*(%1-%2)").arg(ui.driverCBox->currentIndex()+1).arg(i+1);
            }
        }
		// каждому парсеру по уравнению
        parserI->SetExpr(eqi.toAscii().data());
        for (int j = 0; j < eqnsList.size(); j++) {
			// определяем переменные парсера. это будут буковки вида x1 x2 x3 etc..
            QString str = QString("x%1").arg(j+1);
            parserI->DefineVar(str.toAscii().data(), &vars[j]);
        }
		// ну и коэффициент силы связи
        parserI->DefineVar("K", &vars[eqnsList.size()]);
    }
}

void ds_gen::fillStartValues() {
	// заполняем вектор начальных значений
    startValues.clear();
    for (int i = 0; i < ui.eqnsSBox->value(); i++) {
        startValues.append(startVsWidgets.at(i)->value());
    }
}

void ds_gen::setEqnsNum() {
	// в ответ на смену количества уравнений создаем нужное количество спинбоксов
    for (int i = 0; i < startVsWidgets.size(); i++) {
        delete startVsWidgets.at(i);
    }
	for (int i = 0; i < chkSeriesWidgets.size(); i++) {
		delete chkSeriesWidgets.at(i);
	}
	for (int i = 0; i < series.size(); i++) {
		delete series.at(i);
	}
    startVsWidgets.clear();
	chkSeriesWidgets.clear();
	series.clear();
    for (int i = 0; i < ui.eqnsSBox->value(); i++) {
        QDoubleSpinBox *spBox;
        spBox = new QDoubleSpinBox(this);
		ZSimpleSeries *x1Graph;
		x1Graph = new ZSimpleSeries("");
		x1Graph->setColor(QColor::fromHsv(qrand() % 256, 255, 190));
		series.append(x1Graph);
		QCheckBox *chkBox;
		chkBox = new QCheckBox(this);
		chkBox->setText(QString("x%1").arg(i+1));
        ui.gridLayout2->addWidget(spBox, i+1, 0, 1, 1);
		ui.gridLayout8->addWidget(chkBox, (i%3), (i/3));
        connect(spBox, SIGNAL(valueChanged(double)), this, SLOT(fillStartValues()));
		connect(chkBox, SIGNAL(clicked(bool)), this, SLOT(drawGraph()));
        startVsWidgets.append(spBox);
		chkSeriesWidgets.append(chkBox);
    }
    eqnsNum = ui.eqnsSBox->value();
}

ds_gen::ds_gen(QWidget *parent)
        : QMainWindow(parent) {
    ui.setupUi(this);
	// сразу обнуляем интерфейс
    newProfile();

    // диалог выбора директории
    QFileDialog dialog(this);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setFileMode(QFileDialog::DirectoryOnly);

    // диалог выбора директории будет вызываться по нажатию кнопки..
    saveDirectory = ".";
    connect(ui.folderchooseButt, SIGNAL(clicked()),	this, SLOT(setSaveDirectory()));

    // соединяем кнопку запуска счета с соответствующей функцией
    connect(ui.generateButt, SIGNAL(clicked()),	this, SLOT(genDS()));

    // инициализируем прогрессбар
    ui.progressBar->setValue(0);
    ui.progressBar->reset();

    // по нажатию кнопки "Рисовать" будзаполнятся серии данных графиков ))
    connect(ui.drawGraphButt, SIGNAL(clicked()), this, SLOT(prepareData()));

    // обрабатываем нажатие пунктов меню
    connect(ui.action, SIGNAL(triggered()), this, SLOT(openProfile()));
    connect(ui.action_2, SIGNAL(triggered()), this, SLOT(saveProfile()));
    connect(ui.action_3, SIGNAL(triggered()), this, SLOT(newProfile()));

    // тоже самое и про количество уравнений
    connect(ui.eqnsSBox, SIGNAL(valueChanged(int)), this, SLOT(setEqnsNum()));

	// создаем и настраиваем график
    chart = new ZChart();
    chart->setBorderType(0);
    chart->setGraphPanelBorderType(0);
    chart->setMargin(2);
    chart->setSpacing(2);
    chart->setFirstText("");
    chart->setTitle(trUtf8("первый график"));
    chart->setXRange(-10, 10);
    chart->setYRange(-10, 10);
    chart->setAxesName("x", "y");
    chart->showLegend(false);
    chart->setAutoscale(true);

	// добавляем его в нужный лайоут
    ui.gridLayout7->addWidget(chart, 1, 0, 4, 2);
}

ds_gen::~ds_gen() {

}
