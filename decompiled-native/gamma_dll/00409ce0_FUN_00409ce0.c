// 00409ce0 FUN_00409ce0 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00409ce0(undefined4 param_1)

{
  char cVar1;
  byte bVar2;
  LSTATUS LVar3;
  void *pvVar4;
  int *piVar5;
  BOOL BVar6;
  DWORD DVar7;
  int iVar8;
  char *pcVar9;
  CHAR local_154 [256];
  int local_54 [2];
  int local_4c [2];
  undefined1 local_41;
  undefined1 local_25;
  
  if (DAT_0046dba0 != 0) {
    return 0;
  }
  wsprintfA(local_154,&DAT_0046dc8c,param_1);
  iVar8 = -1;
  pcVar9 = local_154;
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  LVar3 = RegSetValueA((HKEY)0x80000001,s_Software_WorldsInc_Gamma_HWND_0046dbf0,1,local_154,
                       -iVar8 - 2);
  if (LVar3 != 0) {
    pvVar4 = (void *)FUN_00403350(0x49eda8,(byte *)s_RegSetValue___failed__0046dc90);
    pvVar4 = (void *)FUN_00409ee0(pvVar4,LVar3);
    FUN_004049b0(*(void **)((int)pvVar4 + 4),local_54);
    local_41 = DAT_004890cc;
    piVar5 = (int *)FUN_00404a00(local_54);
    bVar2 = (**(code **)(*piVar5 + 0x14))(10);
    FUN_00404dc0(local_54);
    iVar8 = FUN_00404b40(pvVar4,bVar2);
    FUN_00403ac0(iVar8);
    return 0;
  }
  BVar6 = ReleaseSemaphore(DAT_004890c8,1,(LPLONG)0x0);
  if (BVar6 == 0) {
    DVar7 = GetLastError();
    pvVar4 = (void *)FUN_00403350(0x49eda8,(byte *)s_ReleaseSemaphore___failed_1___0046dca8);
    pvVar4 = (void *)FUN_00409ee0(pvVar4,DVar7);
    FUN_004049b0(*(void **)((int)pvVar4 + 4),local_4c);
    local_25 = DAT_004890cc;
    piVar5 = (int *)FUN_00404a00(local_4c);
    bVar2 = (**(code **)(*piVar5 + 0x14))(10);
    FUN_00404dc0(local_4c);
    iVar8 = FUN_00404b40(pvVar4,bVar2);
    FUN_00403ac0(iVar8);
    return 0;
  }
  return 1;
}


