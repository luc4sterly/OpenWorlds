// 10049540 doexit [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FID_conflict___lockexit();
  if (DAT_1005bed8 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_1005bed4 = 1;
  DAT_1005bed0 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_1005f7dc != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_1005f7d8 + -4), DAT_1005f7dc <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_1005f7dc <= puVar1);
    }
    __initterm((undefined4 *)&DAT_10058014,(undefined4 *)&DAT_1005801c);
  }
  __initterm((undefined4 *)&DAT_10058020,(undefined4 *)&DAT_10058024);
  if (param_3 != 0) {
    FID_conflict___lockexit();
    return;
  }
  DAT_1005bed8 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}


