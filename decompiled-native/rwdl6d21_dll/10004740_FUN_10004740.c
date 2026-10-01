// 10004740 FUN_10004740 [Global]
// program: RWDL6D21.DLL

bool FUN_10004740(undefined4 param_1,undefined4 param_2,int param_3,uint *param_4)

{
  DWORD DVar1;
  int iVar2;
  HDC hdc;
  HDC hdc_00;
  HBITMAP hbit;
  HGDIOBJ h;
  COLORREF CVar3;
  LONG LVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  short local_2;
  
  DVar1 = GetVersion();
  uVar5 = DVar1 >> 8 & 0xff;
  if (DVar1 < 0x80000000) {
    if (((DVar1 & 0xff) == 3) && (uVar5 < 5)) {
      DAT_10079034 = 0;
    }
    else {
      DAT_10079034 = 1;
    }
  }
  else if (((DVar1 & 0xff) != 3) || (DAT_10079034 = 3, 0x5e < uVar5)) {
    DAT_10079034 = 2;
  }
  if (DAT_10079034 == 0) {
    return false;
  }
  if (0 < param_3) {
    FUN_10003f00(param_3,param_4);
  }
  iVar6 = DAT_10079054;
  if (DAT_10079054 == 0) {
    hdc = GetDC((HWND)0x0);
    if (hdc == (HDC)0x0) {
      return false;
    }
    DAT_10079060 = GetDeviceCaps(hdc,0xc);
    if ((DAT_10079060 == 0x10) && (DAT_1007906c == 0)) {
      hdc_00 = CreateCompatibleDC(hdc);
      if (hdc_00 == (HDC)0x0) {
        DAT_10079060 = 0x10;
      }
      else {
        hbit = CreateBitmap(1,1,1,0x10,(void *)0x0);
        if (hbit == (HBITMAP)0x0) {
          DeleteDC(hdc_00);
          DAT_10079060 = 0x10;
        }
        else {
          h = SelectObject(hdc_00,hbit);
          CVar3 = SetPixel(hdc_00,0,0,0xffffff);
          if (CVar3 == 0xffffffff) {
            SelectObject(hdc_00,h);
            DeleteObject(hbit);
            DeleteDC(hdc_00);
            DAT_10079060 = 0x10;
          }
          else {
            LVar4 = GetBitmapBits(hbit,2,&local_2);
            if (LVar4 == 0) {
              SelectObject(hdc_00,h);
              DeleteObject(hbit);
              DeleteDC(hdc_00);
              DAT_10079060 = 0x10;
            }
            else {
              SelectObject(hdc_00,h);
              DeleteObject(hbit);
              DeleteDC(hdc_00);
              DAT_10079060 = (local_2 == -1) + 0xf;
            }
          }
        }
      }
    }
    uVar5 = GetDeviceCaps(hdc,0x26);
    if ((uVar5 & 0x100) == 0) {
      DAT_10079058 = 0;
    }
    ReleaseDC((HWND)0x0,hdc);
    iVar6 = FUN_10004110();
    if (iVar6 == 0) {
      return false;
    }
    goto LAB_1000496d;
  }
  if (DAT_10079054 == 8) {
    DAT_10079060 = DAT_10079054;
    iVar2 = FUN_10004110();
    if (iVar2 == 0) {
      bVar7 = false;
    }
    else {
LAB_100047ee:
      bVar7 = DAT_10079060 == iVar6;
    }
  }
  else if (DAT_10079054 == 0x10) {
    DAT_10079060 = DAT_10079054;
    iVar2 = FUN_10004110();
    bVar7 = false;
    if (iVar2 != 0) goto LAB_100047ee;
  }
  else {
    bVar7 = false;
  }
  if (!bVar7) {
    return false;
  }
LAB_1000496d:
  return DAT_100790e8 == DAT_10079064;
}


