// 00423d60 FUN_00423d60 [Global]
// programa: gamma.dll

uint * __thiscall FUN_00423d60(int param_1,uint *param_2,int param_3,char param_4,byte param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  if ((((param_5 & 0x18) == 0x18) && (param_4 == '\x02')) || ((param_5 & 0x18) == 0)) {
    *param_2 = 0xffffffff;
    param_2[1] = 0;
    return param_2;
  }
  if ((((param_5 & 8) == 0) || ((*(byte *)(param_1 + 0x24) & 8) != 0)) &&
     ((bVar1 = param_5 & 0x10, bVar1 == 0 || ((*(byte *)(param_1 + 0x24) & 0x10) != 0)))) {
    switch(param_4) {
    case '\x01':
      iVar2 = 0;
      break;
    case '\x02':
      if (bVar1 == 0) {
        iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
      }
      else {
        iVar2 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10);
      }
      break;
    default:
      *param_2 = 0xffffffff;
      param_2[1] = 0;
      return param_2;
    case '\x04':
      if ((*(byte *)(param_1 + 0x24) & 0x10) == 0) {
        iVar2 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4);
      }
      else {
        iVar2 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x10);
      }
    }
    uVar3 = iVar2 + param_3;
    if ((-1 < (int)uVar3) && (uVar3 <= *(uint *)(param_1 + 0x2c))) {
      if ((((*(byte *)(param_1 + 0x24) & 1) != 0) && (bVar1 != 0)) &&
         (uVar3 != *(uint *)(param_1 + 0x2c))) {
        *param_2 = 0xffffffff;
        param_2[1] = 0;
        return param_2;
      }
      if ((param_5 & 8) != 0) {
        iVar2 = *(int *)(param_1 + 4);
        *(int *)(param_1 + 4) = iVar2;
        *(uint *)(param_1 + 8) = uVar3 + iVar2;
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      }
      if (bVar1 != 0) {
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x14);
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x18);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar3;
      }
      *param_2 = uVar3;
      param_2[1] = 0;
      return param_2;
    }
    *param_2 = 0xffffffff;
    param_2[1] = 0;
    return param_2;
  }
  *param_2 = 0xffffffff;
  param_2[1] = 0;
  return param_2;
}


