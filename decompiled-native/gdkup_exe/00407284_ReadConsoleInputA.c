// 00407284 ReadConsoleInputA [KERNEL32.DLL]
// programa: gdkup.exe

BOOL ReadConsoleInputA(HANDLE hConsoleInput,PINPUT_RECORD lpBuffer,DWORD nLength,
                      LPDWORD lpNumberOfEventsRead)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00407284. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ReadConsoleInputA(hConsoleInput,lpBuffer,nLength,lpNumberOfEventsRead);
  return BVar1;
}


