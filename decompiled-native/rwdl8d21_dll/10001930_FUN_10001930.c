// 10001930 FUN_10001930 [Global]
// programa: RWDL8D21.DLL

void FUN_10001930(int param_1,int *param_2,HDC param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  HPALETTE pHVar4;
  BOOL BVar5;
  
  if ((param_2[2] < 1) || (param_2[3] < 1)) {
    DAT_10075134 = 1;
    GdiFlush();
  }
  else {
    if ((DAT_10075058 != 0) && (DAT_10075134 != 0)) {
      pHVar4 = SelectPalette(param_3,DAT_10075030,DAT_10075074);
      if (pHVar4 != (HPALETTE)0x0) {
        RealizePalette(param_3);
      }
      DAT_10075134 = 1;
    }
    puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x100) + 0x2c);
    iVar2 = puVar1[5];
    if ((((iVar2 != -1) && (iVar3 = puVar1[6], iVar3 != -1)) && (iVar2 != *(int *)(param_1 + 0x5c)))
       && (iVar3 != *(int *)(param_1 + 0x60))) {
      StretchBlt(param_3,*(int *)(param_1 + 0x54) + (iVar2 * *param_2) / *(int *)(param_1 + 0x5c),
                 *(int *)(param_1 + 0x58) + (iVar3 * param_2[1]) / *(int *)(param_1 + 0x60),
                 (iVar2 * param_2[2]) / *(int *)(param_1 + 0x5c),
                 (iVar3 * param_2[3]) / *(int *)(param_1 + 0x60),(HDC)*puVar1,
                 *(int *)(param_1 + 100) + *param_2,*(int *)(param_1 + 0x68) + param_2[1],param_2[2]
                 ,param_2[3],0xcc0020);
      return;
    }
    BVar5 = BitBlt(param_3,*(int *)(param_1 + 0x54) + *param_2,*(int *)(param_1 + 0x58) + param_2[1]
                   ,param_2[2],param_2[3],(HDC)*puVar1,*(int *)(param_1 + 100) + *param_2,
                   *(int *)(param_1 + 0x68) + param_2[1],0xcc0020);
    if (BVar5 == 0) {
      GetLastError();
      return;
    }
  }
  return;
}


