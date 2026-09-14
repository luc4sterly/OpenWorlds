// 0040e740 FUN_0040e740 [Global]
// programa: gamma.dll

FARPROC __cdecl FUN_0040e740(short *param_1,byte *param_2,LPCSTR param_3,FARPROC param_4)

{
  BOOL BVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  DWORD DVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  _MEMORY_BASIC_INFORMATION local_30;
  DWORD local_14;
  
  BVar1 = IsBadCodePtr(param_4);
  if (BVar1 != 0) {
    return (FARPROC)0x0;
  }
  hModule = GetModuleHandleA((LPCSTR)param_2);
  pFVar2 = GetProcAddress(hModule,param_3);
  if (pFVar2 == (FARPROC)0x0) {
    return (FARPROC)0x0;
  }
  DVar3 = GetVersion();
  if ((DVar3 & 0xc0000000) == 0x80000000) {
    FUN_00402800(s_nWindow_0046e8c4,0x736);
  }
  BVar1 = IsBadReadPtr(param_1,0x40);
  if (BVar1 != 0) {
    return (FARPROC)0x0;
  }
  if (*param_1 != 0x5a4d) {
    return (FARPROC)0x0;
  }
  piVar5 = (int *)((int)param_1 + *(int *)(param_1 + 0x1e));
  BVar1 = IsBadReadPtr(piVar5,0xf8);
  if (BVar1 != 0) {
    return (FARPROC)0x0;
  }
  if (*piVar5 != 0x4550) {
    return (FARPROC)0x0;
  }
  piVar6 = (int *)((int)param_1 + piVar5[0x20]);
  if (piVar6 == piVar5) {
    return (FARPROC)0x0;
  }
  while ((piVar6[3] != 0 &&
         (iVar4 = FUN_004508c0((byte *)(piVar6[3] + (int)param_1),param_2), iVar4 != 0))) {
    piVar6 = piVar6 + 5;
  }
  if (piVar6[3] == 0) {
    return (FARPROC)0x0;
  }
  piVar5 = (int *)((int)param_1 + piVar6[4]);
  while( true ) {
    if ((FARPROC)*piVar5 == (FARPROC)0x0) {
      return (FARPROC)0x0;
    }
    if ((FARPROC)*piVar5 == pFVar2) break;
    piVar5 = piVar5 + 1;
  }
  VirtualQuery(piVar5,&local_30,0x1c);
  BVar1 = VirtualProtect(local_30.BaseAddress,local_30.RegionSize,4,&local_30.Protect);
  if (BVar1 != 0) {
    *piVar5 = (int)param_4;
    VirtualProtect(local_30.BaseAddress,local_30.RegionSize,local_30.Protect,&local_14);
    return pFVar2;
  }
  return (FARPROC)0x0;
}


