#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settings.h"
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  void on_about_triggered();

  void on_saveGame_triggered();

  void on_loadGame_triggered();

  void on_gameSettings_triggered();

 private:
  Ui::MainWindow* ui;

  Settings settings;
  Game* game;
};

#endif // MAINWINDOW_H
