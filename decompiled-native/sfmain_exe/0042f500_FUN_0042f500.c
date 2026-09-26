// 0042f500 FUN_0042f500 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0042f500(undefined4 param_1,undefined4 param_2)

{
  int *in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar1;
  undefined4 extraout_EDX;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  
  iVar1 = (int)(CONCAT44(in_EAX[4] >> 0x1f,in_EAX[4]) % 0xc);
  puVar2 = &DAT_00437ce4;
  if (-0xb048160 < in_EAX[5]) {
    iVar3 = in_EAX[5] + in_EAX[4] / 0xc;
    for (; iVar1 < 0; iVar1 = iVar1 + 0xc) {
      iVar3 = iVar3 + -1;
    }
    if (-1 < iVar3) {
      lVar6 = FUN_0042fd0e(0xc,in_EAX[4] % 0xc);
      if ((int)lVar6 != 0) {
        puVar2 = &DAT_00437cfe;
      }
      iVar1 = in_EAX[3] + (int)*(short *)(puVar2 + iVar1 * 2) + iVar3 * 0x16d + (iVar3 + 3 >> 2);
      iVar5 = iVar1 + -1;
      if (iVar3 != 0) {
        iVar5 = iVar1 + -2;
      }
      for (uVar4 = *in_EAX + (in_EAX[1] + in_EAX[2] * 0x3c) * 0x3c; (int)uVar4 < 0;
          uVar4 = uVar4 + 0x15180) {
        iVar5 = iVar5 + -1;
      }
      FUN_0042fbc4(in_EAX,uVar4);
      FUN_0042f85c(extraout_ECX,extraout_EDX);
      iVar1 = uVar4 + DAT_0043e90c;
      if (in_EAX[8] < 0) {
        FUN_0042fe62(extraout_ECX_00,DAT_0043e90c);
      }
      if (0 < in_EAX[8]) {
        iVar1 = iVar1 - DAT_0043e910;
      }
      for (; iVar1 < 0; iVar1 = iVar1 + 0x15180) {
        iVar5 = iVar5 + -1;
      }
      if (0x63dd < iVar5) {
        if (iVar5 != 0x63de) {
          iVar1 = iVar1 + (iVar5 + -0x63df) * 0x15180;
          goto LAB_0042f64d;
        }
        iVar1 = iVar1 + -0x15180;
        if ((0 < DAT_0043e90c) && (-1 < iVar1)) goto LAB_0042f64d;
      }
    }
  }
  iVar1 = -1;
LAB_0042f64d:
  return CONCAT44(param_2,iVar1);
}


