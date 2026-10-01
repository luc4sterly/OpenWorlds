// 004112a0 FUN_004112a0 [Global]
// program: gamma.dll

uint __thiscall FUN_004112a0(int *param_1,uint param_2)

{
  int *piVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  bool bVar8;
  byte *pbStack_3c;
  uint uStack_34;
  int aiStack_30 [8];
  
  if (param_1[9] == 0) {
    return 0xffffffff;
  }
  if ((*(char *)((int)param_1 + 0x42) != '\0') && (param_1[5] == 0)) {
    if (((uint)param_1[2] < (uint)param_1[3]) &&
       ((**(code **)(*param_1 + 0xc))(aiStack_30,0,2,8), aiStack_30[0] == -1)) {
      return 0xffffffff;
    }
    param_1[5] = (int)(param_1 + 0xc);
    param_1[4] = param_1[5];
    param_1[6] = (int)(param_1 + 0x10);
  }
  *(undefined1 *)(param_1 + 0x10) = 1;
  if (*(char *)((int)param_1 + 0x41) == '\0') {
    uVar5 = (**(code **)(*(int *)param_1[0xb] + 0x10))();
    for (pbVar7 = (byte *)param_1[4]; pbVar7 < (byte *)param_1[5]; pbVar7 = pbVar7 + 1) {
      uVar6 = FUN_00411fe0(param_1,uVar5,*pbVar7);
      if (uVar6 == 0xffffffff) {
        if ((byte *)param_1[4] < pbVar7) {
          FUN_0044df50((undefined4 *)param_1[4],(undefined4 *)pbVar7,param_1[5] - (int)pbVar7);
          param_1[5] = param_1[5] + (param_1[4] - (int)pbVar7);
        }
        return 0xffffffff;
      }
    }
    bVar8 = false;
    param_1[5] = param_1[5] + (param_1[4] - param_1[5]);
    if ((param_2 != 0xffffffff) &&
       (uVar5 = FUN_00411fe0(param_1,uVar5,(byte)param_2), uVar5 == 0xffffffff)) {
      bVar8 = true;
    }
    if (bVar8) {
      return 0xffffffff;
    }
  }
  else {
    for (pbStack_3c = (byte *)param_1[4]; pbStack_3c < (byte *)param_1[5];
        pbStack_3c = pbStack_3c + 1) {
      puVar3 = (undefined4 *)param_1[9];
      bVar2 = *pbStack_3c;
      iVar4 = FUN_004553d0((int)puVar3,-1);
      if (iVar4 < 0) {
        piVar1 = puVar3 + 0xb;
        iVar4 = *piVar1;
        *piVar1 = *piVar1 + -1;
        if (iVar4 == 0) {
          uVar5 = FUN_00455650((int)(char)bVar2,puVar3);
        }
        else {
          pbVar7 = (byte *)puVar3[10];
          puVar3[10] = puVar3[10] + 1;
          *pbVar7 = bVar2;
          uVar5 = (uint)*pbVar7;
        }
      }
      else {
        uVar5 = 0xffffffff;
      }
      if (uVar5 == 0xffffffff) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = (uint)bVar2;
      }
      if (uVar5 == 0xffffffff) {
        if ((byte *)param_1[4] < pbStack_3c) {
          FUN_0044df50((undefined4 *)param_1[4],(undefined4 *)pbStack_3c,
                       param_1[5] - (int)pbStack_3c);
          param_1[5] = param_1[5] + (param_1[4] - (int)pbStack_3c);
        }
        return 0xffffffff;
      }
    }
    param_1[5] = param_1[5] + (param_1[4] - param_1[5]);
    bVar8 = false;
    if (param_2 != 0xffffffff) {
      puVar3 = (undefined4 *)param_1[9];
      iVar4 = FUN_004553d0((int)puVar3,-1);
      if (iVar4 < 0) {
        piVar1 = puVar3 + 0xb;
        iVar4 = *piVar1;
        *piVar1 = *piVar1 + -1;
        if (iVar4 == 0) {
          uVar5 = FUN_00455650((int)(char)(byte)param_2,puVar3);
        }
        else {
          pbVar7 = (byte *)puVar3[10];
          puVar3[10] = puVar3[10] + 1;
          *pbVar7 = (byte)param_2;
          uVar5 = (uint)*pbVar7;
        }
      }
      else {
        uVar5 = 0xffffffff;
      }
      if (uVar5 == 0xffffffff) {
        uStack_34 = 0xffffffff;
      }
      else {
        uStack_34 = param_2 & 0xff;
      }
      bVar8 = uStack_34 == 0xffffffff;
    }
    if (bVar8) {
      return 0xffffffff;
    }
  }
  if (param_2 == 0xffffffff) {
    param_2 = 0;
  }
  return param_2;
}


