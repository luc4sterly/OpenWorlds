// 004118d0 FUN_004118d0 [Global]
// programa: gamma.dll

int * __fastcall FUN_004118d0(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if (param_1[9] == 0) {
    return (int *)0x0;
  }
  bVar1 = false;
  if ((uint)param_1[4] < (uint)param_1[5]) {
    iVar2 = (**(code **)(*param_1 + 0x30))(0xffffffff);
    if (iVar2 == -1) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    return (int *)0x0;
  }
  if ((char)param_1[0x10] != '\0') {
    uVar3 = FUN_00412340((int)param_1);
    if ((char)uVar3 == '\0') {
      return (int *)0x0;
    }
    *(undefined1 *)(param_1 + 0x10) = 0;
  }
  iVar2 = FUN_00454eb0((undefined4 *)param_1[9]);
  piVar4 = param_1;
  if (iVar2 != 0) {
    piVar4 = (int *)0x0;
  }
  param_1[9] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[4] = param_1[5];
  param_1[6] = 0;
  return piVar4;
}


