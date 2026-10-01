// 10060cd0 doexit [Global]
// program: RWDL6D21.DLL

/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FID_conflict___lockexit();
  if (DAT_100796d0 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_100796cc = 1;
  DAT_100796c8 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_1007d41c != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_1007d418 + -4), DAT_1007d41c <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_1007d41c <= puVar1);
    }
    __initterm((undefined4 *)&DAT_10079014,(undefined4 *)&DAT_1007901c);
  }
  __initterm((undefined4 *)&DAT_10079020,(undefined4 *)&DAT_10079024);
  if (param_3 != 0) {
    FID_conflict___lockexit();
    return;
  }
  DAT_100796d0 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}


