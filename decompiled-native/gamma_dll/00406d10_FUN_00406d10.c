// 00406d10 FUN_00406d10 [Global]
// programa: gamma.dll

int FUN_00406d10(void *param_1,ulonglong param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  int *piVar3;
  int *this;
  char *pcVar4;
  uint uVar5;
  undefined1 *puVar6;
  char cVar7;
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined1 *puVar11;
  bool bVar12;
  char local_90;
  uint local_88;
  bool local_84;
  uint local_80;
  uint *local_70;
  int local_6c [2];
  int local_64 [2];
  undefined4 *local_5c;
  undefined1 local_55;
  undefined1 local_39;
  uint local_20;
  uint local_1c;
  ulonglong local_18;
  
  FUN_004049b0(param_1,local_6c);
  local_55 = DAT_004890b4;
  piVar3 = (int *)FUN_00404a00(local_6c);
  FUN_00404dc0(local_6c);
  if (param_2 != 0) {
    FUN_004049b0(param_1,local_64);
    local_39 = DAT_004890b6;
    this = (int *)FUN_00406190(local_64);
    FUN_00404dc0(local_64);
    local_80 = 10;
    uVar2 = *(ushort *)((int)param_1 + 0x30) & 0x4a;
    if (uVar2 == 8) {
      local_80 = 0x10;
    }
    else if (uVar2 == 0x40) {
      local_80 = 8;
    }
    FUN_004060e0(this,&local_5c);
    FUN_00406490(&local_70,&local_5c);
    lpCriticalSection = (LPCRITICAL_SECTION)(local_5c + 4);
    EnterCriticalSection(lpCriticalSection);
    if (local_5c[2] == 0) {
      local_5c[2] = 1;
    }
    local_5c[2] = local_5c[2] + -1;
    puVar10 = local_5c;
    if (local_5c[2] != 0) {
      puVar10 = (undefined4 *)0x0;
    }
    LeaveCriticalSection(lpCriticalSection);
    local_5c = puVar10;
    if (puVar10 != (undefined4 *)0x0) {
      FUN_0044e100((undefined4 *)puVar10[3]);
      DeleteCriticalSection((LPCRITICAL_SECTION)(local_5c + 4));
      FUN_0044e100(local_5c);
    }
    local_88 = 0;
    local_84 = *local_70 != 0;
    local_90 = '\0';
    cVar7 = '\0';
    if (local_84) {
      pcVar4 = (char *)FUN_00406260(&local_70,0);
      local_90 = *pcVar4;
      if (local_90 == '\0') {
        local_84 = false;
      }
    }
    uVar2 = *(ushort *)((int)param_1 + 0x30);
    puVar9 = param_3;
    if (param_2 != 0) {
      local_1c = 0;
      local_20 = local_80;
      puVar6 = param_3;
      do {
        local_18 = FUN_00453d00((uint)param_2,param_2._4_4_,local_20,local_1c);
        uVar5 = (uint)local_18;
        if (uVar5 < 10) {
          uVar1 = (**(code **)(*piVar3 + 0x14))(uVar5 + 0x30);
        }
        else if ((uVar2 & 0x4000) == 0) {
          uVar1 = (**(code **)(*piVar3 + 0x14))(uVar5 + 0x57);
        }
        else {
          uVar1 = (**(code **)(*piVar3 + 0x14))(uVar5 + 0x37);
        }
        *puVar6 = uVar1;
        puVar9 = puVar6 + 1;
        param_2 = FUN_00453bc0((uint)param_2,param_2._4_4_,local_20,local_1c);
        if (((param_2 != 0) && (local_84)) && (cVar7 = cVar7 + '\x01', cVar7 == local_90)) {
          uVar1 = (**(code **)(*this + 8))();
          *puVar9 = uVar1;
          local_88 = local_88 + 1;
          puVar9 = puVar6 + 2;
          if (local_88 < *local_70) {
            pcVar4 = (char *)FUN_00406260(&local_70,local_88);
            local_90 = *pcVar4;
            if (local_90 == '\0') {
              local_84 = false;
            }
          }
          cVar7 = '\0';
        }
        bVar12 = false;
        if ((int)(param_2 >> 0x20) == 0) {
          bVar12 = (uint)param_2 == 0;
        }
        puVar6 = puVar9;
      } while (!bVar12);
    }
    if ((param_3 != puVar9) && (puVar11 = puVar9 + -1, puVar6 = param_3, param_3 < puVar11)) {
      do {
        uVar1 = *puVar6;
        *puVar6 = *puVar11;
        *puVar11 = uVar1;
        puVar11 = puVar11 + -1;
        puVar6 = puVar6 + 1;
      } while (puVar6 < puVar11);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(local_70 + 4));
    if (local_70[2] == 0) {
      local_70[2] = 1;
    }
    local_70[2] = local_70[2] - 1;
    puVar8 = local_70;
    if (local_70[2] != 0) {
      puVar8 = (uint *)0x0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(local_70 + 4));
    if (puVar8 != (uint *)0x0) {
      local_70 = puVar8;
      FUN_0044e100((undefined4 *)puVar8[3]);
      DeleteCriticalSection((LPCRITICAL_SECTION)(puVar8 + 4));
      FUN_0044e100(local_70);
    }
    return (int)puVar9 - (int)param_3;
  }
  uVar1 = (**(code **)(*piVar3 + 0x14))(0x30);
  *param_3 = uVar1;
  return 1;
}


