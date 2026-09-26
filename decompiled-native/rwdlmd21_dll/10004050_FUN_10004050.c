// 10004050 FUN_10004050 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_10004050(undefined4 *param_1,undefined4 param_2,int param_3,uint *param_4)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  undefined3 extraout_var;
  uint uVar4;
  HDC pHVar5;
  UINT UVar6;
  tagPALETTEENTRY *ptVar7;
  tagPALETTEENTRY *ptVar8;
  int iVar9;
  int iVar10;
  LOGPALETTE *plpal;
  HPALETTE pHVar11;
  void *pvVar12;
  void *this;
  BYTE *pBVar13;
  code *pcVar14;
  code *pcVar15;
  undefined4 *puVar16;
  bool bVar17;
  tagPALETTEENTRY atStack_700 [256];
  tagPALETTEENTRY atStack_300 [192];
  
  iVar2 = FUN_1000bc10();
  if (iVar2 == 0) {
    return false;
  }
  iVar2 = FUN_1000c7e0();
  if (iVar2 == 0) {
    return false;
  }
  DVar3 = GetVersion();
  uVar4 = DVar3 >> 8 & 0xff;
  if (DVar3 < 0x80000000) {
    if (((DVar3 & 0xff) == 3) && (uVar4 < 5)) {
      DAT_10087034 = 0;
    }
    else {
      DAT_10087034 = 1;
    }
  }
  else if (((DVar3 & 0xff) == 3) && (uVar4 < 0x5f)) {
    DAT_10087034 = 3;
  }
  else {
    DAT_10087034 = 2;
  }
  if (DAT_10087034 == 0) {
    return false;
  }
  if (0 < param_3) {
    FUN_10004510(param_3,param_4);
  }
  pcVar15 = GetDC_exref;
  iVar2 = DAT_10087054;
  if (DAT_10087054 == 0) {
    pHVar5 = GetDC((HWND)0x0);
    if (pHVar5 == (HDC)0x0) {
      return false;
    }
    DAT_10087060 = GetDeviceCaps(pHVar5,0xc);
    if ((DAT_10087060 == 0x10) && (DAT_1008706c == 0)) {
      cVar1 = FUN_10004620(pHVar5);
      DAT_10087060 = CONCAT31(extraout_var,cVar1);
    }
    uVar4 = GetDeviceCaps(pHVar5,0x26);
    pcVar14 = ReleaseDC_exref;
    if ((uVar4 & 0x100) == 0) {
      DAT_10087058 = 0;
    }
    ReleaseDC((HWND)0x0,pHVar5);
    iVar2 = FUN_10004720();
    if (iVar2 == 0) {
      return false;
    }
  }
  else {
    if (DAT_10087054 == 8) {
      DAT_10087060 = DAT_10087054;
      iVar9 = FUN_10004720();
      if (iVar9 == 0) {
        bVar17 = false;
      }
      else {
LAB_1000413d:
        bVar17 = iVar2 == DAT_10087060;
      }
    }
    else if (DAT_10087054 == 0x10) {
      DAT_10087060 = DAT_10087054;
      iVar9 = FUN_10004720();
      bVar17 = false;
      if (iVar9 != 0) goto LAB_1000413d;
    }
    else {
      bVar17 = false;
    }
    pcVar14 = ReleaseDC_exref;
    pcVar15 = GetDC_exref;
    if (!bVar17) {
      return false;
    }
  }
  DAT_1008705c = (uint)(DAT_10087064 < 9);
  atStack_700[0] = _DAT_10086004;
  if (DAT_10087068 != 0) {
    atStack_700[0] = _DAT_10086000;
  }
  FUN_10008f50((int)atStack_700[0]);
  if (DAT_1008705c == 0) goto LAB_100042e3;
  if (DAT_10087058 == 0) {
    puVar16 = &DAT_10089df0;
    for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar16 = 0;
      puVar16 = puVar16 + 1;
    }
    puVar16 = &DAT_1008a000;
    for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar16 = 0;
      puVar16 = puVar16 + 1;
    }
    puVar16 = &DAT_10089f00;
    for (iVar2 = 0x40; this = (void *)0x0, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar16 = 0;
      puVar16 = puVar16 + 1;
    }
  }
  else {
    pHVar5 = (HDC)(*pcVar15)(0);
    if (pHVar5 == (HDC)0x0) goto LAB_100042e3;
    UVar6 = GetSystemPaletteEntries(pHVar5,0,0x100,atStack_700);
    if (UVar6 == 0) {
      (*pcVar14)(0,pHVar5);
      goto LAB_100042e3;
    }
    (*pcVar14)(0,pHVar5);
    ptVar7 = atStack_700;
    pvVar12 = (void *)0x0;
    do {
      ptVar8 = ptVar7 + 1;
      *(BYTE *)((int)pvVar12 + 0x10089f00) = ptVar7->peRed;
      this = (void *)((int)pvVar12 + 1);
      *(BYTE *)((int)pvVar12 + 0x1008a000) = ptVar7->peGreen;
      *(BYTE *)((int)pvVar12 + 0x10089df0) = ptVar7->peBlue;
      ptVar7 = ptVar8;
      pvVar12 = this;
    } while (ptVar8 < atStack_300);
  }
  iVar2 = FUN_10008ff0(this,(int)atStack_300);
  if (0 < iVar2) {
    iVar9 = 0;
    ptVar7 = atStack_300;
    do {
      (&DAT_10089f0a)[iVar9] = ptVar7->peRed;
      iVar10 = iVar9 + 1;
      (&DAT_1008a00a)[iVar9] = ptVar7->peGreen;
      (&DAT_10089dfa)[iVar9] = ptVar7->peBlue;
      iVar9 = iVar10;
      ptVar7 = (tagPALETTEENTRY *)&ptVar7->peFlags;
    } while (iVar10 < iVar2);
  }
LAB_100042e3:
  iVar2 = DAT_10087064;
  iVar9 = GetSystemMetrics(0x11);
  iVar10 = GetSystemMetrics(0x10);
  iVar2 = FUN_1000a600(param_1,iVar10,iVar9,iVar2);
  if (iVar2 == 0) {
    cVar1 = '\0';
  }
  else {
    DAT_10089b50 = param_1[0xa7];
    param_1[0xa7] = &LAB_100043f0;
    FUN_10009430();
    if (DAT_10087058 != 0) {
      plpal = (LOGPALETTE *)(**(code **)(DAT_10089de0 + 0x34c))(0x408);
      if (plpal == (LOGPALETTE *)0x0) {
        DAT_10087030 = (HPALETTE)0x0;
      }
      else {
        plpal->palVersion = 0x300;
        iVar2 = 0;
        plpal->palNumEntries = 0x100;
        pBVar13 = &plpal->palPalEntry[0].peFlags;
        do {
          ((PALETTEENTRY *)(pBVar13 + -3))->peRed = *(BYTE *)((int)&DAT_10089f00 + iVar2);
          pBVar13[-2] = *(BYTE *)((int)&DAT_1008a000 + iVar2);
          pBVar13[-1] = *(BYTE *)((int)&DAT_10089df0 + iVar2);
          if ((iVar2 < 10) || (0xf5 < iVar2)) {
            *pBVar13 = '\0';
          }
          else {
            *pBVar13 = '\x04';
          }
          pBVar13 = pBVar13 + 4;
          iVar2 = iVar2 + 1;
        } while (iVar2 < 0x100);
        pHVar11 = CreatePalette(plpal);
        (**(code **)(DAT_10089de0 + 0x358))(plpal);
        DAT_10087030 = pHVar11;
      }
      if (DAT_10087030 == (HPALETTE)0x0) {
        return false;
      }
    }
    iVar2 = FUN_10004420();
    cVar1 = '\x01' - (iVar2 == 0);
  }
  return (bool)cVar1;
}


