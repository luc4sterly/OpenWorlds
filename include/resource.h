#ifndef RESOURCE_H
#define RESOURCE_H

#include "windows_compat.h"

/**
 * Initialize the game, load resources and start the main logic.
 *
 * Parameters
 *   hInstance – handle of the module (passed from entry())
 *   param2    – currently unused flag (original code passes 0)
 *   cmdLine   – command‑line arguments string (may include /S flag)
 *
 * Returns a status code that is used as the process exit code.
 */
unsigned int GameInit(HMODULE hInstance, int param2, char *cmdLine);

#endif // RESOURCE_H