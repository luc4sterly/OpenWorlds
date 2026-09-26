// 100029d0 FUN_100029d0 [Global]
// programa: RWDL8D21.DLL

void FUN_100029d0(int param_1,int *param_2,HDC param_3)

{
  int iVar1;
  DWORD h;
  int iVar2;
  UINT cLines;
  int iVar3;
  HPALETTE pHVar4;
  void *lpvBits;
  
  if ((param_2[2] < 1) || (param_2[3] < 1)) {
    DAT_1007513c = 1;
    return;
  }
  if ((DAT_10075058 != 0) && (DAT_1007513c != 0)) {
    pHVar4 = SelectPalette(param_3,DAT_10075030,DAT_10075074);
    if (pHVar4 != (HPALETTE)0x0) {
      RealizePalette(param_3);
    }
    DAT_1007513c = 1;
  }
  iVar1 = param_2[1];
  h = param_2[3];
  iVar2 = *(int *)(param_1 + 0x100);
  cLines = *(UINT *)(iVar2 + 0x20);
  iVar3 = *(int *)(iVar2 + 0x2c);
  lpvBits = (void *)(*(int *)(iVar2 + 0x28) * (cLines - 1) + *(int *)(iVar2 + 0x18));
  if ((((*(int *)(iVar3 + 0x14) != -1) && (*(int *)(iVar3 + 0x18) != -1)) &&
      (*(int *)(iVar3 + 0x14) != *(int *)(param_1 + 0x5c))) &&
     (*(int *)(iVar3 + 0x18) != *(int *)(param_1 + 0x60))) {
    StretchDIBits(param_3,*(int *)(param_1 + 0x54) +
                          (*(int *)(iVar3 + 0x14) * *param_2) / *(int *)(param_1 + 0x5c),
                  *(int *)(param_1 + 0x58) +
                  (*(int *)(iVar3 + 0x18) * iVar1) / *(int *)(param_1 + 0x60),
                  (*(int *)(iVar3 + 0x14) * param_2[2]) / *(int *)(param_1 + 0x5c),
                  (int)(*(int *)(iVar3 + 0x18) * h) / *(int *)(param_1 + 0x60),
                  *(int *)(param_1 + 100) + *param_2,*(int *)(param_1 + 0x68) + iVar1,param_2[2],h,
                  lpvBits,*(BITMAPINFO **)(iVar3 + 8),(uint)(DAT_10075058 != 0),0xcc0020);
    return;
  }
  SetDIBitsToDevice(param_3,*(int *)(param_1 + 0x54) + *param_2,*(int *)(param_1 + 0x58) + iVar1,
                    param_2[2],h,*(int *)(param_1 + 100) + *param_2,
                    ((cLines - *(int *)(param_1 + 0x68)) - iVar1) - h,0,cLines,lpvBits,
                    *(BITMAPINFO **)(iVar3 + 8),(uint)(DAT_10075058 != 0));
  return;
}


