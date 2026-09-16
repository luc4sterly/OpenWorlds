// 004116c0 FUN_004116c0 [Global]
// programa: gamma.dll

uint __fastcall FUN_004116c0(int *param_1)

{
  int *piVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  bool bVar5;
  undefined1 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uStack_30;
  undefined1 uStack_2c;
  
  if (param_1[9] == 0) {
    return 0xffffffff;
  }
  if ((*(char *)((int)param_1 + 0x42) != '\0') && (param_1[2] == 0)) {
    bVar5 = false;
    if (((uint)param_1[4] < (uint)param_1[5]) &&
       (iVar7 = (**(code **)(*param_1 + 0x30))(0xffffffff), iVar7 == -1)) {
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
  *(undefined1 *)(param_1 + 0x10) = 0;
  pbVar2 = (byte *)param_1[2];
  if (pbVar2 < (byte *)param_1[3]) {
    return (uint)*pbVar2;
  }
  if (*(char *)((int)param_1 + 0x41) == '\0') {
    uStack_30 = (**(code **)(*(int *)param_1[0xb] + 0x10))();
    if ((int)uStack_30 < 1) {
      uVar8 = FUN_004120e0(param_1,param_1[2] == 0);
    }
    else {
      uVar8 = FUN_00412230(param_1,uStack_30,param_1[2] == 0);
    }
  }
  else {
    uVar8 = FUN_00411d60(param_1,pbVar2 == (byte *)0x0);
  }
  if (uVar8 != 0xffffffff) {
    uStack_2c = (undefined1)uVar8;
    if (param_1[2] != 0) {
      iVar7 = param_1[3] - param_1[1];
      if (iVar7 == 0x10) {
        param_1[0xc] = param_1[0xf];
        iVar7 = 4;
      }
      uVar10 = iVar7 + 1;
      param_1[1] = (int)(param_1 + 0xc);
      param_1[2] = (int)param_1 + iVar7 + 0x30;
      param_1[3] = (int)param_1 + iVar7 + 0x31;
      *(undefined1 *)param_1[2] = uStack_2c;
      if (*(char *)((int)param_1 + 0x41) == '\0') {
        if (0 < (int)uStack_30) {
          while (((uStack_30 <= *(uint *)(param_1[9] + 0x2c) && (uVar10 < 0x10)) &&
                 (uVar9 = FUN_00412230(param_1,uStack_30,'\0'), uVar9 != 0xffffffff))) {
            uVar10 = uVar10 + 1;
            *(char *)param_1[3] = (char)uVar9;
            iVar7 = param_1[1];
            param_1[1] = iVar7;
            param_1[2] = param_1[2];
            param_1[3] = uVar10 + iVar7;
          }
        }
      }
      else {
        while ((puVar4 = (undefined4 *)param_1[9], puVar4[0xb] != 0 && (uVar10 < 0x10))) {
          iVar7 = FUN_004553d0((int)puVar4,-1);
          if (iVar7 < 0) {
            piVar1 = puVar4 + 0xb;
            iVar7 = *piVar1;
            *piVar1 = *piVar1 + -1;
            if (iVar7 == 0) {
              uVar9 = FUN_00455440(puVar4);
              uVar6 = (undefined1)uVar9;
            }
            else {
              puVar3 = (undefined1 *)puVar4[10];
              puVar4[10] = puVar4[10] + 1;
              uVar6 = *puVar3;
            }
          }
          else {
            uVar6 = 0xff;
          }
          uVar10 = uVar10 + 1;
          *(undefined1 *)param_1[3] = uVar6;
          iVar7 = param_1[1];
          param_1[1] = iVar7;
          param_1[2] = param_1[2];
          param_1[3] = uVar10 + iVar7;
        }
      }
    }
    return uVar8;
  }
  return 0xffffffff;
}


