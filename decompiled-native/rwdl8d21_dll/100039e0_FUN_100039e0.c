// 100039e0 FUN_100039e0 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __fastcall
FUN_100039e0(undefined4 param_1,uint param_2,undefined4 *param_3,undefined4 param_4,int param_5,
            uint *param_6)

{
  char cVar1;
  DWORD DVar2;
  undefined3 extraout_var;
  uint uVar3;
  HDC pHVar4;
  UINT UVar5;
  tagPALETTEENTRY *ptVar6;
  tagPALETTEENTRY *ptVar7;
  int iVar8;
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
  longlong lVar18;
  tagPALETTEENTRY atStack_700 [256];
  tagPALETTEENTRY atStack_300 [192];
  
  lVar18 = FUN_1000b330(param_1,param_2);
  if ((int)lVar18 == 0) {
    return false;
  }
  DVar2 = GetVersion();
  uVar3 = DVar2 >> 8 & 0xff;
  if (DVar2 < 0x80000000) {
    if (((DVar2 & 0xff) == 3) && (uVar3 < 5)) {
      DAT_10075034 = 0;
    }
    else {
      DAT_10075034 = 1;
    }
  }
  else if (((DVar2 & 0xff) == 3) && (uVar3 < 0x5f)) {
    DAT_10075034 = 3;
  }
  else {
    DAT_10075034 = 2;
  }
  if (DAT_10075034 == 0) {
    return false;
  }
  if (0 < param_5) {
    FUN_10003e90(param_5,param_6);
  }
  pcVar15 = GetDC_exref;
  iVar10 = DAT_10075054;
  if (DAT_10075054 == 0) {
    pHVar4 = GetDC((HWND)0x0);
    if (pHVar4 == (HDC)0x0) {
      return false;
    }
    DAT_10075060 = GetDeviceCaps(pHVar4,0xc);
    if ((DAT_10075060 == 0x10) && (DAT_1007506c == 0)) {
      cVar1 = FUN_10003fa0(pHVar4);
      DAT_10075060 = CONCAT31(extraout_var,cVar1);
    }
    uVar3 = GetDeviceCaps(pHVar4,0x26);
    pcVar14 = ReleaseDC_exref;
    if ((uVar3 & 0x100) == 0) {
      DAT_10075058 = 0;
    }
    ReleaseDC((HWND)0x0,pHVar4);
    iVar10 = FUN_100040a0();
    if (iVar10 == 0) {
      return false;
    }
  }
  else {
    if (DAT_10075054 == 8) {
      DAT_10075060 = DAT_10075054;
      iVar8 = FUN_100040a0();
      if (iVar8 == 0) {
        bVar17 = false;
      }
      else {
LAB_10003abd:
        bVar17 = DAT_10075060 == iVar10;
      }
    }
    else if (DAT_10075054 == 0x10) {
      DAT_10075060 = DAT_10075054;
      iVar8 = FUN_100040a0();
      bVar17 = false;
      if (iVar8 != 0) goto LAB_10003abd;
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
  DAT_1007505c = (uint)(DAT_10075064 < 9);
  atStack_700[0] = _DAT_10074004;
  if (DAT_10075068 != 0) {
    atStack_700[0] = _DAT_10074000;
  }
  FUN_10008770((int)atStack_700[0]);
  if (DAT_1007505c == 0) goto LAB_10003c63;
  if (DAT_10075058 == 0) {
    puVar16 = &DAT_10077db0;
    for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar16 = 0;
      puVar16 = puVar16 + 1;
    }
    puVar16 = &DAT_10077fc0;
    for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar16 = 0;
      puVar16 = puVar16 + 1;
    }
    puVar16 = &DAT_10077ec0;
    for (iVar10 = 0x40; this = (void *)0x0, iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar16 = 0;
      puVar16 = puVar16 + 1;
    }
  }
  else {
    pHVar4 = (HDC)(*pcVar15)(0);
    if (pHVar4 == (HDC)0x0) goto LAB_10003c63;
    UVar5 = GetSystemPaletteEntries(pHVar4,0,0x100,atStack_700);
    if (UVar5 == 0) {
      (*pcVar14)(0,pHVar4);
      goto LAB_10003c63;
    }
    (*pcVar14)(0,pHVar4);
    ptVar6 = atStack_700;
    pvVar12 = (void *)0x0;
    do {
      ptVar7 = ptVar6 + 1;
      *(BYTE *)((int)pvVar12 + 0x10077ec0) = ptVar6->peRed;
      this = (void *)((int)pvVar12 + 1);
      *(BYTE *)((int)pvVar12 + 0x10077fc0) = ptVar6->peGreen;
      *(BYTE *)((int)pvVar12 + 0x10077db0) = ptVar6->peBlue;
      ptVar6 = ptVar7;
      pvVar12 = this;
    } while (ptVar7 < atStack_300);
  }
  iVar10 = FUN_10008810(this,(int)atStack_300);
  if (0 < iVar10) {
    iVar8 = 0;
    ptVar6 = atStack_300;
    do {
      (&DAT_10077eca)[iVar8] = ptVar6->peRed;
      iVar9 = iVar8 + 1;
      (&DAT_10077fca)[iVar8] = ptVar6->peGreen;
      (&DAT_10077dba)[iVar8] = ptVar6->peBlue;
      iVar8 = iVar9;
      ptVar6 = (tagPALETTEENTRY *)&ptVar6->peFlags;
    } while (iVar9 < iVar10);
  }
LAB_10003c63:
  iVar10 = DAT_10075064;
  iVar8 = GetSystemMetrics(0x11);
  iVar9 = GetSystemMetrics(0x10);
  iVar10 = FUN_10009e30(param_3,iVar9,iVar8,iVar10);
  if (iVar10 == 0) {
    cVar1 = '\0';
  }
  else {
    DAT_10077b20 = param_3[0xa7];
    param_3[0xa7] = &LAB_10003d70;
    FUN_10008c50();
    if (DAT_10075058 != 0) {
      plpal = (LOGPALETTE *)(**(code **)(DAT_10077da8 + 0x34c))(0x408);
      if (plpal == (LOGPALETTE *)0x0) {
        DAT_10075030 = (HPALETTE)0x0;
      }
      else {
        plpal->palVersion = 0x300;
        iVar10 = 0;
        plpal->palNumEntries = 0x100;
        pBVar13 = &plpal->palPalEntry[0].peFlags;
        do {
          ((PALETTEENTRY *)(pBVar13 + -3))->peRed = *(BYTE *)((int)&DAT_10077ec0 + iVar10);
          pBVar13[-2] = *(BYTE *)((int)&DAT_10077fc0 + iVar10);
          pBVar13[-1] = *(BYTE *)((int)&DAT_10077db0 + iVar10);
          if ((iVar10 < 10) || (0xf5 < iVar10)) {
            *pBVar13 = '\0';
          }
          else {
            *pBVar13 = '\x04';
          }
          pBVar13 = pBVar13 + 4;
          iVar10 = iVar10 + 1;
        } while (iVar10 < 0x100);
        pHVar11 = CreatePalette(plpal);
        (**(code **)(DAT_10077da8 + 0x358))(plpal);
        DAT_10075030 = pHVar11;
      }
      if (DAT_10075030 == (HPALETTE)0x0) {
        return false;
      }
    }
    iVar10 = FUN_10003da0();
    cVar1 = '\x01' - (iVar10 == 0);
  }
  return (bool)cVar1;
}


