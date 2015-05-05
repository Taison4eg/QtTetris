#ifndef GAME_H
#define GAME_H

#include <QObject>

// Состояние игры
class Game {
  int height, width; // Высота и ширина стакана
  char** glass; // Содержимое стакана
  void memAlloc(); // Отводим память
  void memFree(); // Очищаем память
  int score; // Счёт игры
  int speed; // Скорость игры
 public:
  Game(int height, int width);
  ~Game();
  // Сохранение игры в файл
  void save(QString fileName);
  // Загрузка игры из файла
  void load(QString fileName);
};

#endif // GAME_H
