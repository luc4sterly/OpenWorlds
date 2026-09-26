// 1000a5c0 FUN_1000a5c0 [Global]
// programa: RWDL8D21.DLL

void FUN_1000a5c0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = -0x10000;
  iVar1 = *param_1;
  iVar4 = param_1[1];
  if (param_1[1] <= param_1[2]) {
    iVar4 = param_1[2];
  }
  if (iVar4 <= iVar1) {
    iVar4 = iVar1;
  }
  iVar3 = param_1[1];
  if (param_1[2] <= param_1[1]) {
    iVar3 = param_1[2];
  }
  if (iVar1 <= iVar3) {
    iVar3 = iVar1;
  }
  iVar3 = iVar4 - iVar3;
  if (0xccb < iVar3) {
    if (iVar4 == iVar1) {
      iVar2 = ((param_1[1] - param_1[2]) * 0x100) / (iVar3 + 0x80 >> 8);
    }
    else if (iVar4 == param_1[1]) {
      iVar2 = ((param_1[2] - iVar1) * 0x100) / (iVar3 + 0x80 >> 8) + 0x20000;
    }
    else if (iVar4 == param_1[2]) {
      iVar2 = ((iVar1 - param_1[1]) * 0x100) / (iVar3 + 0x80 >> 8) + 0x40000;
    }
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0x60000;
    }
    else if (0x5ffff < iVar2) {
      iVar2 = iVar2 + -0x60000;
    }
    param_2[1] = (iVar3 * 0x100) / (iVar4 + 0x80 >> 8);
    *param_2 = iVar2;
    param_2[2] = iVar4;
    return;
  }
  *param_2 = -1;
  param_2[2] = iVar4;
  param_2[1] = 0;
  return;
}


