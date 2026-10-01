// 004098b0 _Java_NET_worlds_console_Startup_synchronizeStartup@16 [Global]
// program: gamma.dll

/* WARNING: Type propagation algorithm not settling */

uint _Java_NET_worlds_console_Startup_synchronizeStartup_16
               (int *param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  char cVar1;
  byte bVar2;
  DWORD DVar3;
  void *pvVar4;
  int *piVar5;
  LSTATUS LVar6;
  HWND hWnd;
  char *pcVar7;
  LRESULT LVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  CHAR local_1f8 [256];
  LONG local_f8 [2];
  int local_f0;
  char *local_ec;
  int local_e8 [2];
  int local_e0 [2];
  int local_d8 [2];
  int local_d0 [2];
  int local_c8 [2];
  int local_c0 [2];
  undefined1 local_b5;
  undefined1 local_99;
  undefined1 local_7d;
  undefined1 local_61;
  undefined1 local_45;
  undefined1 local_29;
  
                    /* 0x98b0  70  _Java_NET_worlds_console_Startup_synchronizeStartup@16 */
  DAT_004890c8 = CreateSemaphoreA((LPSECURITY_ATTRIBUTES)0x0,0,1,
                                  s_GammaUniqueStartupSemaphore_kjsd_0046dba4);
  DVar3 = GetLastError();
  if (DAT_004890c8 == (HANDLE)0x0) {
    pvVar4 = (void *)FUN_00403350(0x49eda8,(byte *)s_CreateSemaphore___failed__0046dbd4);
    pvVar4 = (void *)FUN_00409ee0(pvVar4,DVar3);
    FUN_004049b0(*(void **)((int)pvVar4 + 4),local_e8);
    local_b5 = DAT_004890cc;
    piVar5 = (int *)FUN_00404a00(local_e8);
    bVar2 = (**(code **)(*piVar5 + 0x14))(10);
    FUN_00404dc0(local_e8);
  }
  else {
    if (DVar3 == 0) {
      DAT_0046dba0 = 0;
      return 1;
    }
    if (DVar3 == 0xb7) {
      if (param_4 != '\0') {
        DAT_0046dba0 = 1;
        return 0;
      }
      DVar3 = WaitForSingleObject(DAT_004890c8,20000);
      if (DVar3 == 0) {
        local_f8[0] = 0x100;
        LVar6 = RegQueryValueA((HKEY)0x80000001,s_Software_WorldsInc_Gamma_HWND_0046dbf0,local_1f8,
                               local_f8);
        if (LVar6 == 0) {
          hWnd = (HWND)FUN_00454270((int)local_1f8);
          pcVar7 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
          local_f0 = -1;
          local_f8[1] = 0;
          pcVar11 = pcVar7;
          do {
            if (local_f0 == 0) break;
            local_f0 = local_f0 + -1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar1 != '\0');
          local_f0 = -1 - local_f0;
          local_ec = pcVar7;
          LVar8 = SendMessageA(hWnd,0x4a,0,(LPARAM)(local_f8 + 1));
          (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pcVar7);
          uVar10 = ReleaseSemaphore(DAT_004890c8,1,(LPLONG)0x0);
          if (uVar10 != 0) {
            DAT_0046dba0 = 1;
            goto LAB_00409cd1;
          }
          pvVar4 = (void *)FUN_00403350(0x49eda8,(byte *)s_ReleaseSemaphore___failed_2___0046dc2c);
          pvVar4 = (void *)FUN_00409ee0(pvVar4,LVar8);
          FUN_004049b0(*(void **)((int)pvVar4 + 4),local_d8);
          local_7d = DAT_004890cc;
          piVar5 = (int *)FUN_00404a00(local_d8);
          bVar2 = (**(code **)(*piVar5 + 0x14))(10);
          FUN_00404dc0(local_d8);
        }
        else {
          pvVar4 = (void *)FUN_00403350(0x49eda8,(byte *)s_RegQueryValue___failed__0046dc10);
          pvVar4 = (void *)FUN_00409ee0(pvVar4,LVar6);
          FUN_004049b0(*(void **)((int)pvVar4 + 4),local_e0);
          local_99 = DAT_004890cc;
          piVar5 = (int *)FUN_00404a00(local_e0);
          bVar2 = (**(code **)(*piVar5 + 0x14))(10);
          FUN_00404dc0(local_e0);
        }
      }
      else if (DVar3 == 0x102) {
        pvVar4 = (void *)FUN_00403350(0x49eda8,(byte *)s_WaitForSingleObject____TIMEOUT__0046dc4c);
        FUN_004049b0(*(void **)((int)pvVar4 + 4),local_d0);
        local_61 = DAT_004890cc;
        piVar5 = (int *)FUN_00404a00(local_d0);
        bVar2 = (**(code **)(*piVar5 + 0x14))(10);
        FUN_00404dc0(local_d0);
      }
      else {
        pvVar4 = (void *)FUN_00403350(0x49eda8,(byte *)s_WaitForSingleObject___failed__0046dc6c);
        pvVar4 = (void *)FUN_00409ee0(pvVar4,DVar3);
        FUN_004049b0(*(void **)((int)pvVar4 + 4),local_c8);
        local_45 = DAT_004890cc;
        piVar5 = (int *)FUN_00404a00(local_c8);
        bVar2 = (**(code **)(*piVar5 + 0x14))(10);
        FUN_00404dc0(local_c8);
      }
    }
    else {
      pvVar4 = (void *)FUN_00403350(0x49eda8,(byte *)s_CreateSemaphore___failed__0046dbd4);
      pvVar4 = (void *)FUN_00409ee0(pvVar4,DVar3);
      FUN_004049b0(*(void **)((int)pvVar4 + 4),local_c0);
      local_29 = DAT_004890cc;
      piVar5 = (int *)FUN_00404a00(local_c0);
      bVar2 = (**(code **)(*piVar5 + 0x14))(10);
      FUN_00404dc0(local_c0);
    }
  }
  iVar9 = FUN_00404b40(pvVar4,bVar2);
  uVar10 = FUN_00403ac0(iVar9);
LAB_00409cd1:
  return uVar10 & 0xffffff00;
}


