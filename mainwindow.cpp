#include <QFileDialog>
#include <QMessageBox>
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
