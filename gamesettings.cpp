/// Настройки игры
/// --------------
#include "gamesettings.h"
#include "ui_gamesettings.h"

GameSettings::GameSettings(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::GameSettings) {
  ui->setupUi(this);
}

GameSettings::~GameSettings() {
  delete ui;
}
