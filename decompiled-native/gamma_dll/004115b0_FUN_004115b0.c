// 004115b0 FUN_004115b0 [Global]
// program: gamma.dll

uint __fastcall FUN_004115b0(int *param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  if ((*(char *)((int)param_1 + 0x42) != '\0') && (param_1[2] == 0)) {
    bVar2 = false;
    if ((uint)param_1[4] < (uint)param_1[5]) {
      iVar3 = (**(code **)(*param_1 + 0x30))(0xffffffff);
      if (iVar3 == -1) {
        bVar2 = true;
      }
    }
    if (bVar2) {
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
    iVar3 = (**(code **)(*param_1 + 0x20))();
    if (iVar3 == -1) {
      return 0xffffffff;
    }
    bVar1 = *(byte *)param_1[2];
    param_1[2] = param_1[2] + 1;
    return (uint)bVar1;
  }
  *(undefined1 *)(param_1 + 0x10) = 0;
  if (param_1[9] == 0) {
    return 0xffffffff;
  }
  if (*(char *)((int)param_1 + 0x41) == '\0') {
    uVar4 = (**(code **)(*(int *)param_1[0xb] + 0x10))();
    if ((int)uVar4 < 1) {
      uVar4 = FUN_004120e0(param_1,'\0');
    }
    else {
      uVar4 = FUN_00412230(param_1,uVar4,'\0');
    }
  }
  else {
    uVar4 = FUN_00411d60(param_1,'\0');
  }
  if (uVar4 == 0xffffffff) {
    return 0xffffffff;
  }
  return uVar4;
}


