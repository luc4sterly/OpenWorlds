// 0044f790 FUN_0044f790 [Global]
// program: gamma.dll

uint __thiscall FUN_0044f790(int *param_1,uint param_2)

{
  int *piVar1;
  ushort uVar2;
  byte *pbVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  bool bVar10;
  ushort *puStack_38;
  int aiStack_30 [8];
  
  if (param_1[9] == 0) {
    return 0xffffffff;
  }
  if ((*(char *)((int)param_1 + 0x52) != '\0') && (param_1[5] == 0)) {
    if (((uint)param_1[2] < (uint)param_1[3]) &&
       ((**(code **)(*param_1 + 0xc))(aiStack_30,0,2,8), aiStack_30[0] == -1)) {
      return 0xffffffff;
    }
    param_1[5] = (int)(param_1 + 0xc);
    param_1[4] = param_1[5];
    param_1[6] = (int)(param_1 + 0x14);
  }
  *(undefined1 *)(param_1 + 0x14) = 1;
  if (*(char *)((int)param_1 + 0x51) == '\0') {
    uVar7 = (**(code **)(*(int *)param_1[0xb] + 0x10))();
    uVar5 = uVar7;
    for (puVar9 = (undefined4 *)param_1[4]; puVar9 < (undefined4 *)param_1[5];
        puVar9 = (undefined4 *)((int)puVar9 + 2)) {
      uVar5 = FUN_004502a0(param_1,uVar7,CONCAT22((short)(uVar5 >> 0x10),*(undefined2 *)puVar9));
      if ((short)uVar5 == -1) {
        if ((undefined4 *)param_1[4] < puVar9) {
          FUN_0044df50((undefined4 *)param_1[4],puVar9,
                       ((int)(((param_1[5] - (int)puVar9) + 1U) -
                             (uint)((uint)(param_1[5] - (int)puVar9) < 0x80000000)) >> 1) * 2);
          param_1[5] = param_1[5] +
                       ((int)(((param_1[4] - (int)puVar9) + 1U) -
                             (uint)((uint)(param_1[4] - (int)puVar9) < 0x80000000)) >> 1) * 2;
        }
        return 0xffffffff;
      }
    }
    uVar5 = param_1[4] - param_1[5];
    param_1[5] = param_1[5] + ((int)((uVar5 + 1) - (uint)(uVar5 < 0x80000000)) >> 1) * 2;
    bVar10 = false;
    if (((short)param_2 != -1) && (uVar8 = FUN_004502a0(param_1,uVar7,param_2), (short)uVar8 == -1))
    {
      bVar10 = true;
    }
    if (bVar10) {
      return 0xffffffff;
    }
  }
  else {
    for (puStack_38 = (ushort *)param_1[4]; puStack_38 < (ushort *)param_1[5];
        puStack_38 = puStack_38 + 1) {
      uVar2 = *puStack_38;
      puVar9 = (undefined4 *)param_1[9];
      iVar6 = FUN_004553d0((int)puVar9,-1);
      if (iVar6 < 0) {
        piVar1 = puVar9 + 0xb;
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + -1;
        if (iVar6 == 0) {
          uVar5 = FUN_00455650((uint)uVar2,puVar9);
        }
        else {
          pbVar3 = (byte *)puVar9[10];
          puVar9[10] = puVar9[10] + 1;
          *pbVar3 = (byte)uVar2;
          uVar5 = (uint)*pbVar3;
        }
      }
      else {
        uVar5 = 0xffffffff;
      }
      if (uVar5 == 0xffffffff) {
        uVar2 = 0xffff;
      }
      if (uVar2 == 0xffff) {
        if ((ushort *)param_1[4] < puStack_38) {
          FUN_0044df50((undefined4 *)param_1[4],(undefined4 *)puStack_38,
                       ((int)(((param_1[5] - (int)puStack_38) + 1U) -
                             (uint)((uint)(param_1[5] - (int)puStack_38) < 0x80000000)) >> 1) * 2);
          param_1[5] = param_1[5] +
                       ((int)(((param_1[4] - (int)puStack_38) + 1U) -
                             (uint)((uint)(param_1[4] - (int)puStack_38) < 0x80000000)) >> 1) * 2;
        }
        return 0xffffffff;
      }
    }
    uVar5 = param_1[4] - param_1[5];
    param_1[5] = param_1[5] + ((int)((uVar5 + 1) - (uint)(uVar5 < 0x80000000)) >> 1) * 2;
    bVar10 = false;
    if ((short)param_2 != -1) {
      puVar9 = (undefined4 *)param_1[9];
      iVar6 = FUN_004553d0((int)puVar9,-1);
      if (iVar6 < 0) {
        piVar1 = puVar9 + 0xb;
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + -1;
        if (iVar6 == 0) {
          uVar5 = FUN_00455650(param_2 & 0xffff,puVar9);
        }
        else {
          pbVar3 = (byte *)puVar9[10];
          puVar9[10] = puVar9[10] + 1;
          *pbVar3 = (byte)param_2;
          uVar5 = (uint)*pbVar3;
        }
      }
      else {
        uVar5 = 0xffffffff;
      }
      sVar4 = (short)param_2;
      if (uVar5 == 0xffffffff) {
        sVar4 = -1;
      }
      bVar10 = sVar4 == -1;
    }
    if (bVar10) {
      return 0xffffffff;
    }
  }
  if ((short)param_2 == -1) {
    param_2 = 0xffff0000;
  }
  else {
    param_2 = param_2 & 0xffff;
  }
  return param_2;
}


