﻿#pragma once

#define S_SAFE_DELETE(x)	if (x != nullptr) { delete x; x = nullptr; }
#define S_SAFE_DELETE_ARRAY(x)	if (x != nullptr) { delete[] x; x = nullptr; }
#define S_SAFE_FREE(x)	if (x != nullptr) { free(x); x = nullptr; }
