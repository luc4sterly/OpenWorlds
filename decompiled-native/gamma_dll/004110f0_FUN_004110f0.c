// 004110f0 FUN_004110f0 [Global]
// programa: gamma.dll

undefined4 * __thiscall
FUN_004110f0(int *param_1,undefined4 *param_2,int param_3,char param_4,byte param_5)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iStack_34;
  
  iStack_34 = (**(code **)(*(int *)param_1[0xb] + 0x10))();
  if ((param_1[9] == 0) || ((param_3 != 0 && (iStack_34 < 1)))) {
    *param_2 = 0xffffffff;
    param_2[1] = 0;
    return param_2;
  }
  bVar1 = false;
  if (((uint)param_1[4] < (uint)param_1[5]) &&
     (iVar2 = (**(code **)(*param_1 + 0x30))(0xffffffff), iVar2 == -1)) {
    bVar1 = true;
  }
  if (bVar1) {
    *param_2 = 0xffffffff;
    param_2[1] = 0;
    return param_2;
  }
  if ((((param_4 != '\x02') || (param_3 != 0)) && ((char)param_1[0x10] != '\0')) &&
     ((iStack_34 < 0 && (uVar3 = FUN_00412340((int)param_1), (char)uVar3 == '\0')))) {
    *param_2 = 0xffffffff;
    param_2[1] = 0;
    return param_2;
  }
  switch(param_4) {
  case '\x01':
    iVar2 = 0;
    break;
  case '\x02':
    iVar2 = 1;
    if ((param_5 & 8) != 0) {
      param_3 = param_3 - (param_1[3] - param_1[2]);
    }
    break;
  default:
    *param_2 = 0xffffffff;
    param_2[1] = 0;
    return param_2;
  case '\x04':
    iVar2 = 2;
  }
  if (iStack_34 < 0) {
    iStack_34 = 0;
  }
  iVar2 = FUN_004553b0((undefined4 *)param_1[9],iStack_34 * param_3,iVar2);
  if (iVar2 != 0) {
    *param_2 = 0xffffffff;
    param_2[1] = 0;
    return param_2;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[4] = param_1[5];
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  uVar3 = FUN_004552c0(param_1[9]);
  *param_2 = uVar3;
  param_2[1] = 0;
  return param_2;
}


