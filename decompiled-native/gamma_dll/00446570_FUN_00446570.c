// 00446570 FUN_00446570 [Global]
// programa: gamma.dll

uint FUN_00446570(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5)

{
  HMODULE hModule;
  DWORD DVar1;
  FARPROC pFVar2;
  int iVar3;
  uint uVar4;
  int *local_14;
  
  if (param_5 == (int *)0x0) {
    return 0x80004003;
  }
  *param_5 = 0;
  if (param_3 != 0) {
    return 0x8002802b;
  }
  if (param_5 == (int *)0x0) {
    return 0x80004003;
  }
  if (*param_1 == 0) {
    hModule = FUN_004463b0();
    if (hModule == (HMODULE)0x0) {
      DVar1 = GetLastError();
      return DVar1 | 0x80070000;
    }
    pFVar2 = GetProcAddress(hModule,s_LoadRegTypeLib_0047a3dc);
    if (pFVar2 == (FARPROC)0x0) {
      DVar1 = GetLastError();
      return DVar1 | 0x80070000;
    }
    iVar3 = (*pFVar2)(&DAT_004671a8,1,0,param_4,&local_14);
    if (iVar3 < 0) {
      pFVar2 = GetProcAddress(hModule,s_LoadTypeLib_0047a3d0);
      if (pFVar2 == (FARPROC)0x0) {
        DVar1 = GetLastError();
        return DVar1 | 0x80070000;
      }
      uVar4 = (*pFVar2)(u_control_tlb_0047a3ec,&local_14);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
    }
    uVar4 = (**(code **)(*local_14 + 0x18))(local_14,param_2,param_1);
    (**(code **)(*local_14 + 8))(local_14);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
  }
  *param_5 = *param_1;
  (**(code **)(*(int *)*param_1 + 4))((int *)*param_1);
  return 0;
}


