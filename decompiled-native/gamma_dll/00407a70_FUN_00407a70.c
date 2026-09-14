// 00407a70 FUN_00407a70 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00407a70(void *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  undefined1 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  LPCRITICAL_SECTION p_Var8;
  undefined4 *puVar9;
  undefined4 *local_6c [2];
  int local_64;
  int local_60 [2];
  int local_58 [2];
  undefined4 *local_50;
  undefined4 *local_4c;
  undefined1 local_45;
  undefined1 local_29;
  
  FUN_004049b0(param_1,local_60);
  local_45 = DAT_004890b4;
  piVar2 = (int *)FUN_00404a00(local_60);
  FUN_00404dc0(local_60);
  FUN_004049b0(param_1,local_58);
  local_29 = DAT_004890b6;
  piVar3 = (int *)FUN_00406190(local_58);
  FUN_00404dc0(local_58);
  if ((byte)((byte)((ushort)((ushort)(NAN(_DAT_0046d920) || NAN((double)CONCAT44(param_3,param_2)))
                            << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_0046d920 == (double)CONCAT44(param_3,param_2)) << 0xe) >>
                  8)) != 0x40) {
    FUN_00451f90(local_6c,param_2,param_3,*(int *)((int)param_1 + 0x28) + 1);
    FUN_00452380(local_6c,&local_50,*(int *)((int)param_1 + 0x28) + 1,&local_64);
    FUN_00407f50(&local_4c,&local_50);
    FUN_004093a0(param_4,(int *)&local_4c,0,0xffffffff);
    p_Var8 = (LPCRITICAL_SECTION)(local_4c + 4);
    EnterCriticalSection(p_Var8);
    if (local_4c[2] == 0) {
      local_4c[2] = 1;
    }
    local_4c[2] = local_4c[2] + -1;
    puVar9 = local_4c;
    if (local_4c[2] != 0) {
      puVar9 = (undefined4 *)0x0;
    }
    LeaveCriticalSection(p_Var8);
    local_4c = puVar9;
    if (puVar9 != (undefined4 *)0x0) {
      FUN_0044e100((undefined4 *)puVar9[3]);
      DeleteCriticalSection((LPCRITICAL_SECTION)(local_4c + 4));
      FUN_0044e100(local_4c);
    }
    p_Var8 = (LPCRITICAL_SECTION)(local_50 + 4);
    EnterCriticalSection(p_Var8);
    if (local_50[2] == 0) {
      local_50[2] = 1;
    }
    local_50[2] = local_50[2] + -1;
    puVar9 = local_50;
    if (local_50[2] != 0) {
      puVar9 = (undefined4 *)0x0;
    }
    LeaveCriticalSection(p_Var8);
    local_50 = puVar9;
    if (puVar9 != (undefined4 *)0x0) {
      FUN_0044e100((undefined4 *)puVar9[3]);
      DeleteCriticalSection((LPCRITICAL_SECTION)(local_50 + 4));
      FUN_0044e100(local_50);
    }
    iVar4 = 0;
    if (((*(ushort *)((int)param_1 + 0x30) & 0x400) != 0) || (0 < *(int *)((int)param_1 + 0x28))) {
      uVar1 = FUN_004088d0(piVar3);
      iVar4 = FUN_004088e0(param_4);
      iVar5 = FUN_004088e0(param_4);
      FUN_00408f50(param_4,(iVar4 + 1) - iVar5,0,1,uVar1);
      FUN_004088e0(param_4);
      iVar4 = 1;
    }
    if (*(uint *)*param_4 < (uint)(*(int *)((int)param_1 + 0x28) + 1 + iVar4)) {
      uVar1 = (**(code **)(*piVar2 + 0x14))(0x30);
      FUN_004095f0(param_4,(*(int *)((int)param_1 + 0x28) + 1 + iVar4) - *(int *)*param_4,uVar1);
    }
    if ((*(ushort *)((int)param_1 + 0x30) & 0x4000) == 0) {
      uVar1 = (**(code **)(*piVar2 + 0x14))(0x65);
      FUN_004095f0(param_4,1,uVar1);
    }
    else {
      uVar1 = (**(code **)(*piVar2 + 0x14))(0x45);
      FUN_004095f0(param_4,1,uVar1);
    }
    if (local_64 < 0) {
      uVar1 = (**(code **)(*piVar2 + 0x14))(0x2d);
      FUN_004095f0(param_4,1,uVar1);
      local_64 = -local_64;
    }
    else {
      uVar1 = (**(code **)(*piVar2 + 0x14))(0x2b);
      FUN_004095f0(param_4,1,uVar1);
    }
    if (local_64 < 10) {
      uVar1 = (**(code **)(*piVar2 + 0x14))(0x30);
      FUN_004095f0(param_4,1,uVar1);
      uVar1 = (**(code **)(*piVar2 + 0x14))(local_64 + 0x30);
      FUN_004095f0(param_4,1,uVar1);
    }
    else {
      iVar4 = *(int *)*param_4;
      for (; 0 < local_64; local_64 = local_64 / 10) {
        uVar1 = (**(code **)(*piVar2 + 0x14))(local_64 % 10 + 0x30);
        FUN_004095f0(param_4,1,uVar1);
      }
      puVar6 = (undefined1 *)FUN_004089f0(param_4);
      iVar5 = FUN_004088e0(param_4);
      puVar7 = (undefined1 *)(iVar5 + iVar4);
      if ((puVar7 != puVar6) && (puVar6 = puVar6 + -1, puVar7 < puVar6)) {
        do {
          uVar1 = *puVar7;
          *puVar7 = *puVar6;
          *puVar6 = uVar1;
          puVar6 = puVar6 + -1;
          puVar7 = puVar7 + 1;
        } while (puVar7 < puVar6);
      }
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(local_6c[0] + 4));
    if (local_6c[0][2] == 0) {
      local_6c[0][2] = 1;
    }
    local_6c[0][2] = local_6c[0][2] + -1;
    puVar9 = local_6c[0];
    if (local_6c[0][2] != 0) {
      puVar9 = (undefined4 *)0x0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(local_6c[0] + 4));
    if (puVar9 != (undefined4 *)0x0) {
      local_6c[0] = puVar9;
      FUN_0044e100((undefined4 *)puVar9[3]);
      DeleteCriticalSection((LPCRITICAL_SECTION)(puVar9 + 4));
      FUN_0044e100(local_6c[0]);
    }
    return;
  }
  uVar1 = (**(code **)(*piVar2 + 0x14))(0x30);
  FUN_00408b00(param_4,1,uVar1);
  iVar4 = *(int *)((int)param_1 + 0x28);
  if (((*(ushort *)((int)param_1 + 0x30) & 0x400) != 0) || (0 < iVar4)) {
    uVar1 = FUN_004088d0(piVar3);
    FUN_004095f0(param_4,1,uVar1);
  }
  if (0 < iVar4) {
    uVar1 = (**(code **)(*piVar2 + 0x14))(0x30);
    FUN_004095f0(param_4,iVar4,uVar1);
  }
  if ((*(ushort *)((int)param_1 + 0x30) & 0x4000) == 0) {
    uVar1 = (**(code **)(*piVar2 + 0x14))(0x65);
  }
  else {
    uVar1 = (**(code **)(*piVar2 + 0x14))(0x45);
  }
  FUN_004095f0(param_4,1,uVar1);
  uVar1 = (**(code **)(*piVar2 + 0x14))(0x2b);
  FUN_004095f0(param_4,1,uVar1);
  uVar1 = (**(code **)(*piVar2 + 0x14))(0x30);
  FUN_004095f0(param_4,2,uVar1);
  return;
}


