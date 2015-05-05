#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <cstring>
#include "game.h"

using namespace std;

void Game::memAlloc() {
  glass = new char* [height];

  for(int i = 0; i < height; ++i) {
    glass[i] = new char[width + 1];
    memset(glass[i], '_', sizeof(char) * width); // Строка из '_'
    glass[i][width] = 0; // заканчивается 0
  }
}

void Game::memFree() {
  for(int i = 0; i < height; ++i)
    delete[] glass[i];

  delete[] glass;
  glass = NULL;
}

Game::Game(int height, int width) : height(height), width(width) {
  memAlloc();
}

Game::~Game() {
  memFree();
}

// Сохранение игры в файл
void Game::save(QString fileName) {
  QFile f(fileName); // QFile позволяет работать с файлами
  f.open(QIODevice::WriteOnly | QIODevice::Text);
  // Сохраняем данные
  QTextStream out(&f);
  // Ширина и высота стакана
  out << width << " " << height << endl;

  // Содержимое стакана
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j)
      out << glass[i][j];

    out << endl;
  }

  f.close();
}

// Загрузка игры из файла
void Game::load(QString fileName) {
  QFile f(fileName); // Создаем объект - файл
  f.open(QIODevice::ReadOnly | QIODevice::Text); // Открываем его для чтения
  // Читаем данные
  QTextStream in(&f);
  // Считываем размер карты
  in >> width >> height;
  in.readLine();

  memFree();
  memAlloc();

  for(int i = 0; i < height; ++i) {
    in >> glass[i];
    in.readLine(); // Строчка должна была закончиться
  }

  f.close();
}
