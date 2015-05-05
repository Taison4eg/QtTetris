#include "settings.h"

const QString Settings::GlassHeight = "glass/height";
const QString Settings::GlassWidth = "glass/width";

Settings::Settings() : QSettings("tetris.ini", QSettings::IniFormat) {
}
