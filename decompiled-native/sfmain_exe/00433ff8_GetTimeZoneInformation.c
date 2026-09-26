// 00433ff8 GetTimeZoneInformation [KERNEL32.DLL]
// programa: sfmain.exe

DWORD GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00433ff8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetTimeZoneInformation(lpTimeZoneInformation);
  return DVar1;
}


