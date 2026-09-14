// 0044fe50 FUN_0044fe50 [Global]
// programa: gamma.dll

int * __fastcall FUN_0044fe50(int *param_1)

{
  bool bVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  if (param_1[9] == 0) {
    return (int *)0x0;
  }
  bVar1 = false;
  if ((uint)param_1[4] < (uint)param_1[5]) {
    sVar2 = (**(code **)(*param_1 + 0x30))(0xffff);
    if (sVar2 == -1) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    return (int *)0x0;
  }
  if ((char)param_1[0x14] != '\0') {
    uVar3 = FUN_00450600((int)param_1);
    if ((char)uVar3 == '\0') {
      return (int *)0x0;
    }
    *(undefined1 *)(param_1 + 0x14) = 0;
  }
  iVar4 = FUN_00454eb0((undefined4 *)param_1[9]);
  piVar5 = param_1;
  if (iVar4 != 0) {
    piVar5 = (int *)0x0;
  }
  param_1[9] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[4] = param_1[5];
  param_1[6] = 0;
  return piVar5;
}


