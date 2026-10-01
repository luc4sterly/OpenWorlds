// 0040d7a0 FUN_0040d7a0 [Global]
// program: gamma.dll

HPALETTE FUN_0040d7a0(void)

{
  BYTE *pBVar1;
  HDC hdc;
  int iVar2;
  uint uVar3;
  LOGPALETTE *plpal;
  PALETTEENTRY *pPVar4;
  BYTE *pBVar5;
  int iVar6;
  int iVar7;
  BYTE local_410 [1024];
  
  if (DAT_004892c8 == '\0') {
    DAT_004892c8 = '\x01';
    DAT_004892c4 = 0;
  }
  if (DAT_004892c4 == 0) {
    DAT_004892c4 = 1;
    FUN_004197a0(0,0x100,local_410);
    hdc = GetDC((HWND)0x0);
    iVar2 = GetDeviceCaps(hdc,0xe);
    if ((iVar2 == 1) && (uVar3 = GetDeviceCaps(hdc,0x26), (uVar3 & 0x100) != 0)) {
      iVar2 = GetDeviceCaps(hdc,0x68);
      uVar3 = GetDeviceCaps(hdc,0x6a);
      plpal = (LOGPALETTE *)FUN_00450b60(iVar2 * 4 + 4);
      plpal->palVersion = 0x300;
      plpal->palNumEntries = (WORD)iVar2;
      GetSystemPaletteEntries(hdc,0,(int)(short)(WORD)iVar2,plpal->palPalEntry);
      iVar6 = 0;
      iVar7 = (int)((uVar3 + 1) - (uint)(uVar3 < 0x80000000)) >> 1;
      pBVar5 = local_410 + iVar7 * 4;
      pPVar4 = plpal->palPalEntry + iVar7 + -1;
      if (0 < (int)(iVar2 - uVar3)) {
        do {
          iVar6 = iVar6 + 1;
          pPVar4[1].peRed = *pBVar5;
          *(BYTE *)((int)(pPVar4 + 1) + 1) = pBVar5[1];
          pBVar1 = pBVar5 + 2;
          pBVar5 = pBVar5 + 4;
          *(BYTE *)((int)(pPVar4 + 1) + 2) = *pBVar1;
          *(undefined1 *)((int)(pPVar4 + 1) + 3) = 4;
          pPVar4 = pPVar4 + 1;
        } while (iVar6 < (int)(iVar2 - uVar3));
      }
      DAT_004891c4 = CreatePalette(plpal);
      FUN_00451780((undefined4 *)plpal);
    }
    else {
      iVar2 = GetDeviceCaps(hdc,0xc);
      if (iVar2 < 8) {
        MessageBoxA((HWND)0x0,s_Your_display_driver_must_support_0046e978,s_Error_0046e970,0);
                    /* WARNING: Subroutine does not return */
        ExitProcess(1);
      }
    }
    ReleaseDC((HWND)0x0,hdc);
    return DAT_004891c4;
  }
  return DAT_004891c4;
}


