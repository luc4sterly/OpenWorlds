// 00404740 _Java_NET_worlds_network_NetUpdate_CreateProcSpecial@16 [Global]
// program: gamma.dll

uint _Java_NET_worlds_network_NetUpdate_CreateProcSpecial_16
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  DWORD DVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  BOOL BVar5;
  void *pvVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  _STARTUPINFOA *p_Var10;
  byte *pbVar11;
  byte *pbVar12;
  byte local_2ac [512];
  _PROCESS_INFORMATION local_ac;
  _STARTUPINFOA local_9c;
  int local_58 [2];
  int local_50 [2];
  undefined1 local_45;
  undefined1 local_29;
  
                    /* 0x4740  181  _Java_NET_worlds_network_NetUpdate_CreateProcSpecial@16 */
  DVar2 = GetCurrentProcessId();
  uVar3 = (**(code **)(*param_1 + 0x2a4))(param_1,param_3,0,DVar2);
  uVar4 = (**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
  wsprintfA((LPSTR)local_2ac,s__s__s__lu_0046d620,uVar3,uVar4,DVar2);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,uVar3);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_4,uVar4);
  p_Var10 = &local_9c;
  for (iVar9 = 0x11; iVar9 != 0; iVar9 = iVar9 + -1) {
    p_Var10->cb = 0;
    p_Var10 = (_STARTUPINFOA *)&p_Var10->lpReserved;
  }
  local_9c.cb = 0x44;
  BVar5 = CreateProcessA((LPCSTR)0x0,(LPSTR)local_2ac,(LPSECURITY_ATTRIBUTES)0x0,
                         (LPSECURITY_ATTRIBUTES)0x0,0,8,(LPVOID)0x0,(LPCSTR)0x0,&local_9c,&local_ac)
  ;
  if (BVar5 == 0) {
    DVar2 = GetLastError();
    pbVar11 = local_2ac;
    pbVar12 = &DAT_0046d62c;
    iVar9 = FUN_00403350(0x49eda8,(byte *)s_Internal_error___can_t_execute___0046d630);
    iVar9 = FUN_00403350(iVar9,pbVar11);
    pvVar6 = (void *)FUN_00403350(iVar9,pbVar12);
    FUN_004049b0(*(void **)((int)pvVar6 + 4),local_58);
    local_45 = DAT_0048908d;
    piVar7 = (int *)FUN_00404a00(local_58);
    bVar1 = (**(code **)(*piVar7 + 0x14))(10);
    FUN_00404dc0(local_58);
    iVar9 = FUN_00404b40(pvVar6,bVar1);
    FUN_00403ac0(iVar9);
    FormatMessageA(0x1200,(LPCVOID)0x0,DVar2,0,(LPSTR)local_2ac,0x200,(va_list *)0x0);
    pvVar6 = (void *)FUN_00403350(0x49eda8,local_2ac);
    FUN_004049b0(*(void **)((int)pvVar6 + 4),local_50);
    local_29 = DAT_0048908d;
    piVar7 = (int *)FUN_00404a00(local_50);
    bVar1 = (**(code **)(*piVar7 + 0x14))(10);
    FUN_00404dc0(local_50);
    iVar9 = FUN_00404b40(pvVar6,bVar1);
    uVar8 = FUN_00403ac0(iVar9);
    return uVar8 & 0xffffff00;
  }
  WaitForInputIdle(local_ac.hProcess,0xffffffff);
  CloseHandle(local_ac.hProcess);
  BVar5 = CloseHandle(local_ac.hThread);
  return CONCAT31((int3)((uint)BVar5 >> 8),1);
}


