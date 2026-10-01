// 10001430 FUN_10001430 [Global]
// program: RWDL6D21.DLL

undefined4 FUN_10001430(int param_1,int param_2,int param_3)

{
  RGBQUAD *pRVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  BITMAPINFO *lpbmi;
  DWORD *pDVar5;
  HGDIOBJ pvVar6;
  DWORD DVar7;
  int iVar8;
  int iVar9;
  HDC hdc;
  bool bVar10;
  undefined4 uVar11;
  void *local_10;
  HBITMAP pHStack_c;
  uint uStack_8;
  int iStack_4;
  
  local_10 = (void *)0xdead;
  hdc = (HDC)0x0;
  if ((DAT_10079084 != 0) &&
     (((param_2 * 2 - DAT_1007beb0 != 0 && DAT_1007beb0 <= param_2 * 2 || (DAT_1007bda0 < param_3))
      && (iVar3 = FUN_10008860(param_2,param_3), iVar3 == 0)))) {
    return 0;
  }
  *(uint *)(*(int *)(param_1 + 0x104) + 0x40) = *(uint *)(*(int *)(param_1 + 0x104) + 0x40) | 2;
  *(int *)(*(int *)(param_1 + 0x104) + 0x1c) = param_2;
  *(int *)(*(int *)(param_1 + 0x104) + 0x20) = param_3;
  *(int *)(*(int *)(param_1 + 0x104) + 0x28) = DAT_1007beb0;
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x24) = DAT_100790ec;
  **(undefined4 **)(param_1 + 0x104) = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 4) = DAT_100790ec;
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0xc) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x14) = 0;
  iVar3 = (**(code **)(DAT_1007bda8 + 0x34c))(param_3 << 2);
  if (iVar3 == 0) {
    return 0;
  }
  *(int *)(param_1 + 0x220) = iVar3;
  if (*(int *)(param_1 + 0x10c) == 0) {
    *(uint *)(param_1 + 0x228) = *(uint *)(param_1 + 0x228) | 2;
    return 1;
  }
  uStack_8 = param_2 + 3U & 0xfffffffc;
  puVar4 = (undefined4 *)(**(code **)(DAT_1007bda8 + 0x34c))(0x28);
  if (puVar4 == (undefined4 *)0x0) {
    return 0;
  }
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = 0;
  puVar4[5] = 0xffffffff;
  puVar4[6] = 0xffffffff;
  puVar4[7] = 0;
  puVar4[8] = 0;
  iStack_4 = (int)(uStack_8 * DAT_10079064 + ((int)(uStack_8 * DAT_10079064) >> 0x1f & 7U)) >> 3;
  if (*(int *)(param_1 + 0x10c) == 0) goto LAB_100018a9;
  hdc = CreateCompatibleDC((HDC)0x0);
  if (hdc == (HDC)0x0) {
    (**(code **)(DAT_1007bda8 + 0x358))(iVar3);
    (**(code **)(DAT_1007bda8 + 0x358))(puVar4);
    return 0;
  }
  if (DAT_10079058 != 0) {
    SelectPalette(hdc,DAT_10079030,1);
    RealizePalette(hdc);
  }
  if (DAT_1007905c == 0) {
    if (DAT_10079064 == 0x10) {
      uVar11 = 0x34;
    }
    else {
      uVar11 = 0x28;
    }
  }
  else {
    uVar11 = 0x428;
  }
  lpbmi = (BITMAPINFO *)(**(code **)(DAT_1007bda8 + 0x34c))(uVar11);
  if (lpbmi == (BITMAPINFO *)0x0) {
    DeleteDC(hdc);
    (**(code **)(DAT_1007bda8 + 0x358))(iVar3);
    (**(code **)(DAT_1007bda8 + 0x358))(puVar4);
    return 0;
  }
  pRVar1 = lpbmi->bmiColors;
  (lpbmi->bmiHeader).biSize = 0x28;
  (lpbmi->bmiHeader).biWidth = uStack_8;
  (lpbmi->bmiHeader).biHeight = param_3;
  (lpbmi->bmiHeader).biPlanes = 1;
  (lpbmi->bmiHeader).biBitCount = (WORD)DAT_10079064;
  (lpbmi->bmiHeader).biCompression = (DAT_10079064 == 8) - 1 & 3;
  (lpbmi->bmiHeader).biSizeImage = 0;
  (lpbmi->bmiHeader).biXPelsPerMeter = 1;
  (lpbmi->bmiHeader).biYPelsPerMeter = 1;
  if (DAT_1007905c == 0) {
    DVar7 = 0;
  }
  else {
    DVar7 = 0x100;
  }
  (lpbmi->bmiHeader).biClrUsed = DVar7;
  (lpbmi->bmiHeader).biClrImportant = DVar7;
  if (DAT_10079064 == 0x10) {
    pRVar1->rgbBlue = '\0';
    pRVar1->rgbGreen = 0xf8;
    pRVar1->rgbRed = '\0';
    pRVar1->rgbReserved = '\0';
    lpbmi[1].bmiHeader.biSize = 0x7e0;
    lpbmi[1].bmiHeader.biWidth = 0x1f;
  }
  else if (DAT_1007905c != 0) {
    if (DAT_10079058 == 0) {
      pDVar5 = &lpbmi[1].bmiHeader.biClrImportant;
      iVar8 = 10;
      do {
        iVar9 = iVar8 + 1;
        *(undefined1 *)pDVar5 = *(undefined1 *)((int)&DAT_1007bdb0 + iVar8);
        *(undefined1 *)((int)pDVar5 + 1) = *(undefined1 *)((int)&DAT_1007bfc0 + iVar8);
        *(undefined1 *)((int)pDVar5 + 2) = *(undefined1 *)((int)&DAT_1007bec0 + iVar8);
        *(undefined1 *)((int)pDVar5 + 3) = 0;
        pDVar5 = pDVar5 + 1;
        iVar8 = iVar9;
      } while (iVar9 < 0xf6);
    }
    else {
      iVar8 = 0;
      do {
        *(short *)(&pRVar1->rgbBlue + iVar8 * 2) = (short)iVar8;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0x100);
    }
  }
  local_10 = (void *)0x0;
  pHStack_c = CreateDIBSection(hdc,lpbmi,(uint)(DAT_10079058 != 0),&local_10,(HANDLE)0x0,0);
  if (pHStack_c == (HBITMAP)0x0) {
    (**(code **)(DAT_1007bda8 + 0x358))(lpbmi);
    DeleteDC(hdc);
    (**(code **)(DAT_1007bda8 + 0x358))(iVar3);
    (**(code **)(DAT_1007bda8 + 0x358))(puVar4);
    return 0;
  }
  pvVar6 = SelectObject(hdc,pHStack_c);
  *puVar4 = hdc;
  puVar4[1] = local_10;
  puVar4[2] = lpbmi;
  puVar4[3] = pHStack_c;
  puVar4[4] = pvVar6;
  puVar2 = *(undefined4 **)(param_1 + 0x100);
  puVar2[6] = (void *)((param_3 + -1) * iStack_4 + (int)local_10);
  puVar2[7] = uStack_8;
  puVar2[10] = -iStack_4;
  puVar2[8] = param_3;
  puVar2[9] = DAT_10079064;
  puVar2[0x10] = puVar2[0x10] | 2;
  iVar3 = DAT_10079064;
  bVar10 = DAT_10079064 == 0xf;
  puVar2[1] = DAT_10079064;
  if (bVar10) {
    *puVar2 = 2;
    puVar2[2] = 0x7c00;
    puVar2[3] = 0x3e0;
LAB_10001898:
    puVar2[4] = 0x1f;
    puVar2[5] = 0;
  }
  else if (iVar3 == 0x10) {
    *puVar2 = 2;
    puVar2[2] = 0xf800;
    puVar2[3] = 0x7e0;
    goto LAB_10001898;
  }
  puVar2[0xb] = puVar4;
LAB_100018a9:
  *(HDC *)(param_1 + 0x108) = hdc;
  return 1;
}


