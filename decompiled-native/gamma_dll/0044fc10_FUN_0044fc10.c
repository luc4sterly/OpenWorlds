// 0044fc10 FUN_0044fc10 [Global]
// program: gamma.dll

uint __fastcall FUN_0044fc10(int *param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  bool bVar5;
  short sVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uStack_30;
  short sStack_2c;
  
  if (param_1[9] == 0) {
    return 0xffffffff;
  }
  if ((*(char *)((int)param_1 + 0x52) != '\0') && (param_1[2] == 0)) {
    bVar5 = false;
    if (((uint)param_1[4] < (uint)param_1[5]) &&
       (sVar6 = (**(code **)(*param_1 + 0x30))(0xffff), sVar6 == -1)) {
      bVar5 = true;
    }
    if (bVar5) {
      return 0xffffffff;
    }
    param_1[5] = 0;
    param_1[4] = param_1[5];
    param_1[6] = 0;
    param_1[1] = (int)(param_1 + 0xc);
    param_1[2] = (int)(param_1 + 0xc);
    param_1[3] = (int)(param_1 + 0xc);
  }
  *(undefined1 *)(param_1 + 0x14) = 0;
  puVar2 = (undefined2 *)param_1[2];
  if (puVar2 < (undefined2 *)param_1[3]) {
    return CONCAT22((short)((uint)puVar2 >> 0x10),*puVar2);
  }
  if (*(char *)((int)param_1 + 0x51) == '\0') {
    uStack_30 = (**(code **)(*(int *)param_1[0xb] + 0x10))();
    if ((int)uStack_30 < 1) {
      uVar8 = FUN_004503a0(param_1,param_1[2] == 0);
    }
    else {
      uVar8 = FUN_004504f0(param_1,uStack_30,param_1[2] == 0);
    }
  }
  else {
    uVar8 = FUN_00450030(param_1,puVar2 == (undefined2 *)0x0);
  }
  sStack_2c = (short)uVar8;
  if (sStack_2c != -1) {
    if (param_1[2] != 0) {
      iVar9 = (int)(((param_1[3] - param_1[1]) + 1U) -
                   (uint)((uint)(param_1[3] - param_1[1]) < 0x80000000)) >> 1;
      if (iVar9 == 0x10) {
        param_1[0xc] = param_1[0x13];
        iVar9 = 2;
      }
      uVar12 = iVar9 + 1;
      param_1[1] = (int)(param_1 + 0xc);
      param_1[2] = (int)param_1 + uVar12 * 2 + 0x2e;
      param_1[3] = (int)param_1 + uVar12 * 2 + 0x30;
      *(short *)param_1[2] = sStack_2c;
      if (*(char *)((int)param_1 + 0x51) == '\0') {
        if (0 < (int)uStack_30) {
          while ((uStack_30 <= *(uint *)(param_1[9] + 0x2c) && (uVar12 < 0x10))) {
            uVar11 = FUN_004504f0(param_1,uStack_30,'\0');
            if ((short)uVar11 == -1) {
              return uVar8;
            }
            *(short *)param_1[3] = (short)uVar11;
            uVar12 = uVar12 + 1;
            iVar9 = param_1[1];
            param_1[1] = iVar9;
            param_1[2] = param_1[2];
            param_1[3] = uVar12 * 2 + iVar9;
          }
        }
      }
      else {
        while ((puVar4 = (undefined4 *)param_1[9], puVar4[0xb] != 0 && (uVar12 < 0x10))) {
          iVar9 = FUN_004553d0((int)puVar4,-1);
          if (iVar9 < 0) {
            piVar1 = puVar4 + 0xb;
            iVar9 = *piVar1;
            *piVar1 = *piVar1 + -1;
            if (iVar9 == 0) {
              uVar10 = FUN_00455440(puVar4);
              uVar7 = (ushort)uVar10;
            }
            else {
              pbVar3 = (byte *)puVar4[10];
              puVar4[10] = puVar4[10] + 1;
              uVar7 = (ushort)*pbVar3;
            }
          }
          else {
            uVar7 = 0xffff;
          }
          *(ushort *)param_1[3] = uVar7;
          uVar12 = uVar12 + 1;
          iVar9 = param_1[1];
          param_1[1] = iVar9;
          param_1[2] = param_1[2];
          param_1[3] = uVar12 * 2 + iVar9;
        }
      }
    }
    return uVar8;
  }
  return 0xffffffff;
}


