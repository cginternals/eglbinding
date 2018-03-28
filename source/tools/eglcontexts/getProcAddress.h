
#pragma once


using ProcAddress = void(*)();


ProcAddress getProcAddress(const char * name);
