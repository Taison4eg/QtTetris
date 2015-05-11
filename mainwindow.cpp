#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent> // Нажатия кнопок на клавиатуре
#include <QDebug> // Вывод в отладочную консоль
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "game.h"
#include "gamesettings.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
  game = new Game(settings.glassWidth(), settings.glassHeight());
}

MainWindow::~MainWindow() {
  delete game;
  delete ui;
}

void MainWindow::on_about_triggered() {
  About about;
  // Модальное окно - пока не закроешь,
  // остальное приложение блокируется
  about.exec();
}

void MainWindow::on_saveGame_triggered() {
  QString filename = QFileDialog::getSaveFileName(
                       this, "Сохранить игру", "",
                       "Тетрис (*.tetris)");

  if(filename.isEmpty())
    return;

  try {
    game->save(filename);
  } catch(QString error) {
    // critical(QWidget * parent, const QString & title,
    // const QString & text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton)
    QMessageBox::critical(this, "Ошибка при сохранении файла", error);
  }
}

void MainWindow::on_loadGame_triggered() {
  QString filename = QFileDialog::getOpenFileName(
                       this, "Загрузить игру", "",
                       "Тетрис (*.tetris)");

  try {
    game->load(filename);
  } catch(QString error) {
    QMessageBox::critical(this, "Ошибка при чтении файла", error);
  }

  //updateWindow();
}

void MainWindow::on_gameSettings_triggered() {
  GameSettings form(this, settings);
  form.exec();
}

// При нажатии на кнопку на клавиатуре
void MainWindow::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Left: // Двигаем фигуру влево
      qDebug() << "Left";
      break;

    case Qt::Key_Right: // Двигаем фигуру вправо
      qDebug() << "Right";
      break;

    case Qt::Key_Down: // Приземляем фигуру
      qDebug() << "Down - landed figure";
      break;

    case Qt::Key_Up: // Поворачиваем фигуру
      qDebug() << "Up - rotate";
      break;

    case Qt::Key_Space: // Пробел - пауза
      qDebug() << "Game pause";
      break;
  }

  // Вызываем стандартный обработчик нажатий
  QMainWindow::keyPressEvent(event);
}

