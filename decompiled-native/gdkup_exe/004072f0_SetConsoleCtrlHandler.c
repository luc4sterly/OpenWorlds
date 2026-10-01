// 004072f0 SetConsoleCtrlHandler [KERNEL32.DLL]
// program: gdkup.exe

BOOL SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine,BOOL Add)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004072f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetConsoleCtrlHandler(HandlerRoutine,Add);
  return BVar1;
}


