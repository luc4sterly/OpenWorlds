// 0044faf0 FUN_0044faf0 [Global]
// program: gamma.dll

uint __fastcall FUN_0044faf0(int *param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  bool bVar3;
  short sVar4;
  uint uVar5;
  
  if ((*(char *)((int)param_1 + 0x52) != '\0') && (param_1[2] == 0)) {
    bVar3 = false;
    if ((uint)param_1[4] < (uint)param_1[5]) {
      sVar4 = (**(code **)(*param_1 + 0x30))(0xffff);
      if (sVar4 == -1) {
        bVar3 = true;
      }
    }
    if (bVar3) {
      return 0xffffffff;
    }
    param_1[5] = 0;
    param_1[4] = param_1[5];
    param_1[6] = 0;
    param_1[1] = (int)(param_1 + 0xc);
    param_1[2] = (int)(param_1 + 0xc);
    param_1[3] = (int)(param_1 + 0xc);
  }
  if (param_1[2] != 0) {
    sVar4 = (**(code **)(*param_1 + 0x20))();
    if (sVar4 == -1) {
      return 0xffffffff;
    }
    puVar2 = (undefined2 *)param_1[2];
    uVar1 = *puVar2;
    param_1[2] = param_1[2] + 2;
    return CONCAT22((short)((uint)puVar2 >> 0x10),uVar1);
  }
  *(undefined1 *)(param_1 + 0x14) = 0;
  if (param_1[9] == 0) {
    return 0xffffffff;
  }
  if (*(char *)((int)param_1 + 0x51) == '\0') {
    uVar5 = (**(code **)(*(int *)param_1[0xb] + 0x10))();
    if ((int)uVar5 < 1) {
      uVar5 = FUN_004503a0(param_1,'\0');
    }
    else {
      uVar5 = FUN_004504f0(param_1,uVar5,'\0');
    }
  }
  else {
    uVar5 = FUN_00450030(param_1,'\0');
  }
  if ((short)uVar5 == -1) {
    return 0xffffffff;
  }
  return uVar5;
}


