// 004016f7 FUN_004016f7 [Global]
// programa: run.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004016f7(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_0040ba80 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_0040ba7c = 1;
  DAT_0040ba78 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0040cf90 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_0040cf8c - 4), DAT_0040cf90 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_0040cf90 <= puVar1);
    }
    FUN_00401790((undefined4 *)&DAT_00409018,(undefined4 *)&DAT_00409020);
  }
  FUN_00401790((undefined4 *)&DAT_00409024,(undefined4 *)&DAT_00409028);
  if (param_3 != 0) {
    return;
  }
  DAT_0040ba80 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}


