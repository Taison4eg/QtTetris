#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

// Настройки игры
class Settings : public QSettings {
  static const QString GlassHeight;
  static const QString GlassWidth;
 public:
  Settings();

  // Ширина стакана
  int glassWidth() {
    return this->value(GlassWidth, 10).toInt();
  }

  void setGlassWidth(int v) {
    this->setValue(GlassWidth, v);
  }

  // Высота стакана
  int glassHeight() {
    return this->value(GlassHeight, 20).toInt();
  }

  void setGlassHeight(int v) {
    this->setValue(GlassHeight, v);
  }
};

#endif // SETTINGS_H
