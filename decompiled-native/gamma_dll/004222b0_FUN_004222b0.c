// 004222b0 FUN_004222b0 [Global]
// program: gamma.dll

int __fastcall
FUN_004222b0(undefined4 param_1,undefined4 param_2,HGDIOBJ param_3,int param_4,int param_5,
            int param_6,char *param_7,uint param_8)

{
  byte *pbVar1;
  byte *pbVar2;
  uint *puVar3;
  BYTE BVar4;
  BYTE BVar5;
  BYTE BVar6;
  byte bVar7;
  HDC hdc;
  HGDIOBJ h;
  undefined1 *puVar8;
  HDC hdc_00;
  int iVar9;
  HBITMAP h_00;
  HGDIOBJ h_01;
  uint *puVar10;
  int iVar11;
  DWORD DVar12;
  HDC pHVar13;
  uint uVar14;
  HBITMAP hbmMask;
  HGDIOBJ h_02;
  int iVar15;
  undefined4 *puVar16;
  RGBQUAD local_1120;
  BYTE aBStackY_111c [1020];
  undefined4 local_d20;
  undefined4 local_d1c;
  undefined4 local_d18;
  undefined1 auStackY_d14 [1020];
  byte *local_918;
  byte local_914 [256];
  RGBQUAD local_814 [256];
  undefined1 local_414 [976];
  undefined4 uStackY_44;
  undefined4 uVar17;
  uint uVar18;
  
  FUN_004574c0(param_1,param_2);
  hdc = CreateCompatibleDC((HDC)0x0);
  h = SelectObject(hdc,param_3);
  if (DAT_0049d1c0 == 0) {
    param_6 = -1;
  }
  if (param_6 != -1) {
    iVar15 = 0;
    local_d20 = DAT_004714d0;
    uVar17 = local_d20;
    local_d1c = DAT_0049d1dd;
    local_d20._2_1_ = (BYTE)((uint)DAT_004714d0 >> 0x10);
    BVar5 = local_d20._2_1_;
    local_d20._3_1_ = (BYTE)((uint)DAT_004714d0 >> 0x18);
    BVar6 = local_d20._3_1_;
    local_d20._1_1_ = (BYTE)((uint)DAT_004714d0 >> 8);
    BVar4 = local_d20._1_1_;
    local_d20 = uVar17;
    do {
      (&local_1120)[iVar15].rgbBlue = (BYTE)local_d20;
      (&local_1120)[iVar15].rgbGreen = BVar4;
      (&local_1120)[iVar15].rgbRed = BVar5;
      (&local_1120)[iVar15].rgbReserved = BVar6;
      aBStackY_111c[iVar15 * 4] = (BYTE)local_d20;
      aBStackY_111c[iVar15 * 4 + 1] = BVar4;
      aBStackY_111c[iVar15 * 4 + 2] = BVar5;
      aBStackY_111c[iVar15 * 4 + 3] = BVar6;
      aBStackY_111c[iVar15 * 4 + 4] = (BYTE)local_d20;
      aBStackY_111c[iVar15 * 4 + 5] = BVar4;
      aBStackY_111c[iVar15 * 4 + 6] = BVar5;
      aBStackY_111c[iVar15 * 4 + 7] = BVar6;
      aBStackY_111c[iVar15 * 4 + 8] = (BYTE)local_d20;
      aBStackY_111c[iVar15 * 4 + 9] = BVar4;
      aBStackY_111c[iVar15 * 4 + 10] = BVar5;
      aBStackY_111c[iVar15 * 4 + 0xb] = BVar6;
      aBStackY_111c[iVar15 * 4 + 0xc] = (BYTE)local_d20;
      aBStackY_111c[iVar15 * 4 + 0xd] = BVar4;
      aBStackY_111c[iVar15 * 4 + 0xe] = BVar5;
      aBStackY_111c[iVar15 * 4 + 0xf] = BVar6;
      aBStackY_111c[iVar15 * 4 + 0x10] = (BYTE)local_d20;
      aBStackY_111c[iVar15 * 4 + 0x11] = BVar4;
      aBStackY_111c[iVar15 * 4 + 0x12] = BVar5;
      aBStackY_111c[iVar15 * 4 + 0x13] = BVar6;
      aBStackY_111c[iVar15 * 4 + 0x14] = (BYTE)local_d20;
      aBStackY_111c[iVar15 * 4 + 0x15] = BVar4;
      aBStackY_111c[iVar15 * 4 + 0x16] = BVar5;
      aBStackY_111c[iVar15 * 4 + 0x17] = BVar6;
      aBStackY_111c[iVar15 * 4 + 0x18] = (BYTE)local_d20;
      aBStackY_111c[iVar15 * 4 + 0x19] = BVar4;
      aBStackY_111c[iVar15 * 4 + 0x1a] = BVar5;
      aBStackY_111c[iVar15 * 4 + 0x1b] = BVar6;
      iVar15 = iVar15 + 8;
    } while (iVar15 < 0x100);
    (&local_1120)[param_6].rgbBlue = (BYTE)local_d1c;
    (&local_1120)[param_6].rgbGreen = local_d1c._1_1_;
    (&local_1120)[param_6].rgbRed = local_d1c._2_1_;
    (&local_1120)[param_6].rgbReserved = local_d1c._3_1_;
  }
  iVar15 = FUN_00417900();
  if (iVar15 == 1) {
    FUN_004197a0(0,0x100,local_414);
    puVar8 = local_414;
    iVar15 = 0;
    do {
      *(undefined1 *)((int)&local_d18 + iVar15 * 4 + 2) = *puVar8;
      *(undefined1 *)((int)&local_d18 + iVar15 * 4 + 1) = puVar8[1];
      *(undefined1 *)(&local_d18 + iVar15) = puVar8[2];
      *(undefined1 *)((int)&local_d18 + iVar15 * 4 + 3) = 0;
      auStackY_d14[iVar15 * 4 + 2] = puVar8[4];
      auStackY_d14[iVar15 * 4 + 1] = puVar8[5];
      auStackY_d14[iVar15 * 4] = puVar8[6];
      auStackY_d14[iVar15 * 4 + 3] = 0;
      auStackY_d14[iVar15 * 4 + 6] = puVar8[8];
      auStackY_d14[iVar15 * 4 + 5] = puVar8[9];
      auStackY_d14[iVar15 * 4 + 4] = puVar8[10];
      auStackY_d14[iVar15 * 4 + 7] = 0;
      auStackY_d14[iVar15 * 4 + 10] = puVar8[0xc];
      auStackY_d14[iVar15 * 4 + 9] = puVar8[0xd];
      auStackY_d14[iVar15 * 4 + 8] = puVar8[0xe];
      auStackY_d14[iVar15 * 4 + 0xb] = 0;
      auStackY_d14[iVar15 * 4 + 0xe] = puVar8[0x10];
      auStackY_d14[iVar15 * 4 + 0xd] = puVar8[0x11];
      auStackY_d14[iVar15 * 4 + 0xc] = puVar8[0x12];
      auStackY_d14[iVar15 * 4 + 0xf] = 0;
      auStackY_d14[iVar15 * 4 + 0x12] = puVar8[0x14];
      auStackY_d14[iVar15 * 4 + 0x11] = puVar8[0x15];
      auStackY_d14[iVar15 * 4 + 0x10] = puVar8[0x16];
      auStackY_d14[iVar15 * 4 + 0x13] = 0;
      auStackY_d14[iVar15 * 4 + 0x16] = puVar8[0x18];
      auStackY_d14[iVar15 * 4 + 0x15] = puVar8[0x19];
      auStackY_d14[iVar15 * 4 + 0x14] = puVar8[0x1a];
      auStackY_d14[iVar15 * 4 + 0x17] = 0;
      auStackY_d14[iVar15 * 4 + 0x1a] = puVar8[0x1c];
      auStackY_d14[iVar15 * 4 + 0x19] = puVar8[0x1d];
      auStackY_d14[iVar15 * 4 + 0x18] = puVar8[0x1e];
      auStackY_d14[iVar15 * 4 + 0x1b] = 0;
      iVar15 = iVar15 + 8;
      puVar8 = puVar8 + 0x20;
    } while (iVar15 < 0x100);
    if (iVar15 < 0x100) {
      puVar16 = &local_d18 + iVar15;
      uVar17 = DAT_004714a8;
      do {
        iVar15 = iVar15 + 1;
        *(char *)puVar16 = (char)uVar17;
        *(char *)((int)puVar16 + 1) = (char)((uint)DAT_004714a8 >> 8);
        *(char *)((int)puVar16 + 2) = (char)((uint)DAT_004714a8 >> 0x10);
        *(char *)((int)puVar16 + 3) = (char)((uint)DAT_004714a8 >> 0x18);
        puVar16 = puVar16 + 1;
      } while (iVar15 < 0x100);
    }
  }
  hdc_00 = CreateCompatibleDC((HDC)0x0);
  SetStretchBltMode(hdc_00,3);
  iVar15 = FUN_00417910();
  uVar18 = 0;
  iVar9 = FUN_00417900();
  h_00 = FUN_00422150(hdc_00,iVar15,iVar15,&local_d18,&local_918,iVar9,uVar18);
  h_01 = SelectObject(hdc_00,h_00);
  StretchBlt(hdc_00,0,0,iVar15,iVar15,hdc,0,0,param_4,param_5,0xcc0020);
  GdiFlush();
  uVar18 = FUN_00417920();
  puVar10 = FUN_00454a10(uVar18);
  if (puVar10 == (uint *)0x0) {
    FUN_004028c0((byte *)s_Out_of_virtual_memory_004714b0,(byte *)s_DIBToTexture1_004714d4);
  }
  iVar9 = FUN_00417900();
  if (iVar9 == 1) {
    local_914[0] = 10;
    iVar9 = 1;
    do {
      iVar11 = iVar9;
      bVar7 = (byte)iVar11;
      local_914[iVar11] = bVar7;
      local_914[iVar11 + 1] = bVar7 + 1;
      local_914[iVar11 + 2] = bVar7 + 2;
      local_914[iVar11 + 3] = bVar7 + 3;
      local_914[iVar11 + 4] = bVar7 + 4;
      local_914[iVar11 + 5] = bVar7 + 5;
      local_914[iVar11 + 6] = bVar7 + 6;
      iVar9 = iVar11 + 8;
      local_914[iVar11 + 7] = bVar7 + 7;
    } while (iVar9 < 0xf8);
    bVar7 = (byte)iVar9;
    local_914[iVar11 + 8] = bVar7;
    local_914[iVar11 + 9] = bVar7 + 1;
    local_914[iVar11 + 10] = bVar7 + 2;
    local_914[iVar11 + 0xb] = bVar7 + 3;
    local_914[iVar11 + 0xc] = bVar7 + 4;
    local_914[iVar11 + 0xd] = bVar7 + 5;
    local_914[iVar11 + 0xe] = bVar7 + 6;
    uVar14 = uVar18;
    pbVar1 = local_918;
    pbVar2 = local_918;
    puVar3 = puVar10;
    if (param_6 != -1) {
      for (; uVar14 != 0; uVar14 = uVar14 - 1) {
        *pbVar2 = local_914[*pbVar1];
        pbVar1 = pbVar1 + 1;
        pbVar2 = pbVar2 + 1;
      }
      GetDIBColorTable(hdc,0,0x100,(RGBQUAD *)(local_914 + 0x100));
      SetDIBColorTable(hdc,0,0x100,&local_1120);
      if (DAT_0049d1d4 == '\0') {
        DAT_0049d1d4 = '\x01';
        DAT_0049d1d0 = 0;
      }
      if (DAT_0049d1dc == '\0') {
        DAT_0049d1dc = '\x01';
        DAT_0049d1d8 = 0;
      }
      if (DAT_0049d1d0 == 0) {
        DVar12 = GetVersion();
        if (DVar12 < 0x80000000) {
          pHVar13 = GetDC((HWND)0x0);
          uVar14 = GetDeviceCaps(pHVar13,0x26);
          DAT_0049d1d8 = (uint)((uVar14 & 0x100) == 0);
          ReleaseDC((HWND)0x0,pHVar13);
        }
        DAT_0049d1d0 = 1;
      }
      if (DAT_0049d1d8 == 0) {
        StretchBlt(hdc_00,0,0,iVar15,iVar15,hdc,0,0,param_4,param_5,0x8800c6);
      }
      else {
        hbmMask = CreateBitmap(iVar15,iVar15,1,1,(void *)0x0);
        if (hbmMask == (HBITMAP)0x0) {
          FUN_004028c0((byte *)s_Out_of_virtual_memory_004714b0,(byte *)s_DIBToTexture2_004714e4);
        }
        pHVar13 = CreateCompatibleDC((HDC)0x0);
        h_02 = SelectObject(pHVar13,hbmMask);
        SetBkColor(hdc,0);
        StretchBlt(pHVar13,0,0,iVar15,iVar15,hdc,0,0,param_4,param_5,0x330008);
        SelectObject(pHVar13,h_02);
        DeleteDC(pHVar13);
        uStackY_44 = 0x422a5c;
        MaskBlt(hdc_00,0,0,iVar15,iVar15,hdc_00,0,0,hbmMask,0,0,0xcc0020);
        DeleteObject(hbmMask);
      }
      GdiFlush();
      FUN_0044df50(puVar10,(undefined4 *)local_918,uVar18);
      SetDIBColorTable(hdc,0,0x100,(RGBQUAD *)(local_914 + 0x100));
    }
    else {
      for (; uVar18 != 0; uVar18 = uVar18 - 1) {
        bVar7 = *local_918;
        local_918 = local_918 + 1;
        *(byte *)puVar3 = local_914[bVar7];
        puVar3 = (uint *)((int)puVar3 + 1);
      }
    }
  }
  else {
    FUN_0044df50(puVar10,(undefined4 *)local_918,uVar18);
  }
  iVar15 = FUN_00421560(param_7,param_8,puVar10);
  SelectObject(hdc,h);
  DeleteDC(hdc);
  SelectObject(hdc_00,h_01);
  DeleteDC(hdc_00);
  DeleteObject(h_00);
  return iVar15;
}


