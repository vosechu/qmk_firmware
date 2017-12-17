

#pragma once

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

// wiring of each half
#undef  MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }
#undef  MATRIX_COL_PINS
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1 }

#endif
