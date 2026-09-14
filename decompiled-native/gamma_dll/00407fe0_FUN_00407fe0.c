// 00407fe0 FUN_00407fe0 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00407fe0(void *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  float10 fVar1;
  float fVar2;
  undefined1 uVar3;
  char cVar4;
  int *piVar5;
  int *this;
  LPVOID pvVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  uint *puVar10;
  uint uVar11;
  LPCRITICAL_SECTION p_Var12;
  int iVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  byte local_ac;
  uint local_84;
  undefined4 *local_80;
  short local_7c;
  uint *local_78;
  int local_74 [2];
  int local_6c [2];
  uint local_64;
  undefined4 *local_60;
  undefined4 *local_5c;
  uint local_58;
  undefined4 *local_54;
  undefined4 *local_50;
  undefined4 *local_4c;
  undefined1 local_45;
  undefined1 local_29;
  
  FUN_004049b0(param_1,local_74);
  local_45 = DAT_004890b4;
  piVar5 = (int *)FUN_00404a00(local_74);
  FUN_00404dc0(local_74);
  FUN_004049b0(param_1,local_6c);
  local_29 = DAT_004890b6;
  this = (int *)FUN_00406190(local_6c);
  FUN_00404dc0(local_6c);
  if ((byte)((byte)((ushort)((ushort)(NAN(_DAT_0046d920) || NAN((double)CONCAT44(param_3,param_2)))
                            << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_0046d920 == (double)CONCAT44(param_3,param_2)) << 0xe) >>
                  8)) == 0x40) {
    uVar3 = (**(code **)(*piVar5 + 0x14))(0x30);
    FUN_00408b00(param_4,1,uVar3);
    if (((*(ushort *)((int)param_1 + 0x30) & 0x400) != 0) || (0 < *(int *)((int)param_1 + 0x28))) {
      uVar3 = FUN_004088d0(this);
      FUN_004095f0(param_4,1,uVar3);
    }
    uVar3 = (**(code **)(*piVar5 + 0x14))(0x30);
    FUN_004095f0(param_4,*(int *)((int)param_1 + 0x28),uVar3);
    return;
  }
  if ((float10)(double)CONCAT44(param_3,param_2) < (float10)_DAT_0046d920) {
    pvVar6 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar6 + 4) = 0x21;
    fVar2 = _DAT_004823b0;
  }
  else {
    fVar1 = (float10)log2((float10)(double)CONCAT44(param_3,param_2));
    fVar2 = (float)((float10)0.3010299956639812 * (float10)1 * fVar1);
  }
  local_84 = (uint)ROUND(ROUND(fVar2));
  FUN_00451f90(&local_80,param_2,param_3,local_84 + *(int *)((int)param_1 + 0x28) + 1);
  local_84 = (uint)local_7c;
  local_64 = local_84 + *(int *)((int)param_1 + 0x28) + 1;
  if ((int)local_64 < DAT_0046d928) {
    puVar10 = (uint *)&DAT_0046d928;
  }
  else {
    puVar10 = &local_64;
  }
  FUN_00452380(&local_80,&local_60,*puVar10,(int *)&local_84);
  FUN_00407f50(&local_5c,&local_60);
  FUN_004093a0(param_4,(int *)&local_5c,0,0xffffffff);
  p_Var12 = (LPCRITICAL_SECTION)(local_5c + 4);
  EnterCriticalSection(p_Var12);
  if (local_5c[2] == 0) {
    local_5c[2] = 1;
  }
  local_5c[2] = local_5c[2] + -1;
  puVar14 = local_5c;
  if (local_5c[2] != 0) {
    puVar14 = (undefined4 *)0x0;
  }
  LeaveCriticalSection(p_Var12);
  local_5c = puVar14;
  if (puVar14 != (undefined4 *)0x0) {
    FUN_0044e100((undefined4 *)puVar14[3]);
    DeleteCriticalSection((LPCRITICAL_SECTION)(local_5c + 4));
    FUN_0044e100(local_5c);
  }
  p_Var12 = (LPCRITICAL_SECTION)(local_60 + 4);
  EnterCriticalSection(p_Var12);
  if (local_60[2] == 0) {
    local_60[2] = 1;
  }
  local_60[2] = local_60[2] + -1;
  puVar14 = local_60;
  if (local_60[2] != 0) {
    puVar14 = (undefined4 *)0x0;
  }
  LeaveCriticalSection(p_Var12);
  local_60 = puVar14;
  if (puVar14 != (undefined4 *)0x0) {
    FUN_0044e100((undefined4 *)puVar14[3]);
    DeleteCriticalSection((LPCRITICAL_SECTION)(local_60 + 4));
    FUN_0044e100(local_60);
  }
  if (local_84 != (int)local_7c) {
    local_58 = local_84 + *(int *)((int)param_1 + 0x28) + 1;
    if ((int)local_58 < DAT_0046d92c) {
      puVar10 = (uint *)&DAT_0046d92c;
    }
    else {
      puVar10 = &local_58;
    }
    FUN_00452380(&local_80,&local_54,*puVar10,(int *)&local_84);
    FUN_00407f50(&local_50,&local_54);
    FUN_004093a0(param_4,(int *)&local_50,0,0xffffffff);
    p_Var12 = (LPCRITICAL_SECTION)(local_50 + 4);
    EnterCriticalSection(p_Var12);
    if (local_50[2] == 0) {
      local_50[2] = 1;
    }
    local_50[2] = local_50[2] + -1;
    puVar14 = local_50;
    if (local_50[2] != 0) {
      puVar14 = (undefined4 *)0x0;
    }
    LeaveCriticalSection(p_Var12);
    local_50 = puVar14;
    if (puVar14 != (undefined4 *)0x0) {
      FUN_0044e100((undefined4 *)puVar14[3]);
      DeleteCriticalSection((LPCRITICAL_SECTION)(local_50 + 4));
      FUN_0044e100(local_50);
    }
    p_Var12 = (LPCRITICAL_SECTION)(local_54 + 4);
    EnterCriticalSection(p_Var12);
    if (local_54[2] == 0) {
      local_54[2] = 1;
    }
    local_54[2] = local_54[2] + -1;
    puVar14 = local_54;
    if (local_54[2] != 0) {
      puVar14 = (undefined4 *)0x0;
    }
    LeaveCriticalSection(p_Var12);
    local_54 = puVar14;
    if (puVar14 != (undefined4 *)0x0) {
      FUN_0044e100((undefined4 *)puVar14[3]);
      DeleteCriticalSection((LPCRITICAL_SECTION)(local_54 + 4));
      FUN_0044e100(local_54);
    }
  }
  if (((int)local_84 < 0) || (*(int *)*param_4 - 1U <= local_84)) {
    if ((int)local_84 < 0) {
      iVar13 = -1 - local_84;
      if (*(int *)((int)param_1 + 0x28) < iVar13) {
        uVar3 = (**(code **)(*piVar5 + 0x14))(0x30);
        FUN_00408b00(param_4,1,uVar3);
        if (((*(ushort *)((int)param_1 + 0x30) & 0x400) != 0) || (0 < *(int *)((int)param_1 + 0x28))
           ) {
          uVar3 = FUN_004088d0(this);
          FUN_004095f0(param_4,1,uVar3);
        }
        uVar3 = (**(code **)(*piVar5 + 0x14))(0x30);
        FUN_004095f0(param_4,*(int *)((int)param_1 + 0x28),uVar3);
      }
      else if (iVar13 < *(int *)((int)param_1 + 0x28)) {
        uVar3 = (**(code **)(*piVar5 + 0x14))(0x30);
        iVar7 = FUN_004088e0(param_4);
        uVar16 = 0;
        iVar8 = FUN_004088e0(param_4);
        FUN_00408f50(param_4,iVar7 - iVar8,uVar16,iVar13,uVar3);
        if (*(uint *)*param_4 < *(uint *)((int)param_1 + 0x28)) {
          uVar3 = (**(code **)(*piVar5 + 0x14))(0x30);
          FUN_004095f0(param_4,*(int *)((int)param_1 + 0x28) - *(int *)*param_4,uVar3);
        }
        uVar3 = FUN_004088d0(this);
        iVar13 = FUN_004088e0(param_4);
        iVar7 = FUN_004088e0(param_4);
        FUN_00408f50(param_4,iVar13 - iVar7,0,1,uVar3);
        FUN_004088e0(param_4);
        uVar3 = (**(code **)(*piVar5 + 0x14))(0x30);
        iVar13 = FUN_004088e0(param_4);
        iVar7 = FUN_004088e0(param_4);
        FUN_00408f50(param_4,iVar13 - iVar7,0,1,uVar3);
        FUN_004088e0(param_4);
      }
      else {
        uVar3 = (**(code **)(*piVar5 + 0x14))(0x30);
        FUN_00408b00(param_4,1,uVar3);
        uVar3 = (**(code **)(*piVar5 + 0x14))(0x30);
        FUN_004095f0(param_4,*(int *)((int)param_1 + 0x28),uVar3);
        if ('\x04' < *(char *)local_80[3]) {
          iVar13 = FUN_004089f0(param_4);
          *(char *)(iVar13 + -1) = *(char *)(iVar13 + -1) + '\x01';
        }
        if (((*(ushort *)((int)param_1 + 0x30) & 0x400) != 0) || (0 < *(int *)((int)param_1 + 0x28))
           ) {
          uVar3 = FUN_004088d0(this);
          iVar13 = FUN_004088e0(param_4);
          iVar7 = FUN_004088e0(param_4);
          FUN_00408f50(param_4,(iVar13 + 1) - iVar7,0,1,uVar3);
          FUN_004088e0(param_4);
        }
      }
    }
    else {
      uVar3 = (**(code **)(*piVar5 + 0x14))(0x30);
      FUN_004095f0(param_4,(local_84 + 1) - *(int *)*param_4,uVar3);
      if (((*(ushort *)((int)param_1 + 0x30) & 0x400) != 0) || (0 < *(int *)((int)param_1 + 0x28)))
      {
        uVar3 = FUN_004088d0(this);
        FUN_004095f0(param_4,1,uVar3);
      }
      uVar3 = (**(code **)(*piVar5 + 0x14))(0x30);
      FUN_004095f0(param_4,*(int *)((int)param_1 + 0x28),uVar3);
    }
  }
  else {
    if (((*(ushort *)((int)param_1 + 0x30) & 0x400) != 0) || (0 < *(int *)((int)param_1 + 0x28))) {
      uVar3 = FUN_004088d0(this);
      FUN_00408f50(param_4,local_84 + 1,0,1,uVar3);
    }
    uVar3 = (**(code **)(*piVar5 + 0x14))(0x30);
    FUN_004095f0(param_4,(local_84 + *(int *)((int)param_1 + 0x28) + 2) - *(int *)*param_4,uVar3);
  }
  FUN_004060e0(this,&local_4c);
  FUN_00406490(&local_78,&local_4c);
  p_Var12 = (LPCRITICAL_SECTION)(local_4c + 4);
  EnterCriticalSection(p_Var12);
  if (local_4c[2] == 0) {
    local_4c[2] = 1;
  }
  local_4c[2] = local_4c[2] + -1;
  puVar14 = local_4c;
  if (local_4c[2] != 0) {
    puVar14 = (undefined4 *)0x0;
  }
  LeaveCriticalSection(p_Var12);
  local_4c = puVar14;
  if (puVar14 != (undefined4 *)0x0) {
    FUN_0044e100((undefined4 *)puVar14[3]);
    DeleteCriticalSection((LPCRITICAL_SECTION)(local_4c + 4));
    FUN_0044e100(local_4c);
  }
  if ((*local_78 != 0) && (1 < *(uint *)*param_4)) {
    uVar16 = 0;
    cVar4 = FUN_004088d0(this);
    uVar16 = FUN_00408ef0(param_4,cVar4,uVar16);
    if (uVar16 == 0xffffffff) {
      uVar16 = *(uint *)*param_4;
    }
    uVar11 = 0;
    pbVar9 = (byte *)FUN_00406260(&local_78,0);
    local_ac = *pbVar9;
    uVar15 = 0;
    while (uVar16 = uVar16 - 1, uVar16 != 0) {
      uVar15 = uVar15 + 1;
      if (uVar15 == local_ac) {
        uVar3 = (**(code **)(*this + 8))();
        FUN_00408f50(param_4,uVar16,0,1,uVar3);
        uVar11 = uVar11 + 1;
        if (uVar11 < *local_78) {
          pbVar9 = (byte *)FUN_00406260(&local_78,uVar11);
          local_ac = *pbVar9;
        }
        uVar15 = 0;
      }
    }
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(local_78 + 4));
  if (local_78[2] == 0) {
    local_78[2] = 1;
  }
  local_78[2] = local_78[2] - 1;
  puVar10 = local_78;
  if (local_78[2] != 0) {
    puVar10 = (uint *)0x0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(local_78 + 4));
  local_78 = puVar10;
  if (puVar10 != (uint *)0x0) {
    FUN_0044e100((undefined4 *)puVar10[3]);
    DeleteCriticalSection((LPCRITICAL_SECTION)(puVar10 + 4));
    FUN_0044e100(local_78);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(local_80 + 4));
  if (local_80[2] == 0) {
    local_80[2] = 1;
  }
  local_80[2] = local_80[2] + -1;
  puVar14 = local_80;
  if (local_80[2] != 0) {
    puVar14 = (undefined4 *)0x0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(local_80 + 4));
  if (puVar14 != (undefined4 *)0x0) {
    local_80 = puVar14;
    FUN_0044e100((undefined4 *)puVar14[3]);
    DeleteCriticalSection((LPCRITICAL_SECTION)(puVar14 + 4));
    FUN_0044e100(local_80);
  }
  return;
}


