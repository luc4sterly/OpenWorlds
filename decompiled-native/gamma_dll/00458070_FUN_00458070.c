// 00458070 FUN_00458070 [Global]
// programa: gamma.dll

undefined4 FUN_00458070(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  HANDLE pvVar2;
  BOOL BVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  switch(param_2) {
  case 0:
    if ((0 < DAT_0049eb68) && (DAT_0049eb68 = DAT_0049eb68 + -1, DAT_0049eb68 == 0)) {
      FUN_00450860();
      uStack_10 = 0x45813f;
      FUN_00450c20(0x482e28);
      while (0 < DAT_0049ff60) {
        DAT_0049ff60 = DAT_0049ff60 + -1;
        (**(code **)(&DAT_0049f860 + DAT_0049ff60 * 4))();
      }
      FUN_004587c0();
    }
    break;
  case 1:
    uStack_10 = 0xffffffff;
    uStack_14 = 0xffffffff;
    puStack_18 = &LAB_0045a1d0;
    uStack_1c = *unaff_FS_OFFSET;
    *unaff_FS_OFFSET = &uStack_1c;
    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)&LAB_0045a250);
    FUN_00450be0(&PTR_PTR_00482e28);
    FUN_00458a40();
    iVar1 = FUN_00453e80();
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = FUN_004589f0(&LAB_00453db0);
    if (iVar1 != 0) {
      return 0;
    }
    FUN_0045a260();
    DAT_0049eb68 = DAT_0049eb68 + 1;
    break;
  case 2:
    pvVar2 = GetCurrentThread();
    uStack_10 = 0x458109;
    BVar3 = FUN_00453de0((uint)pvVar2);
    if (BVar3 == 0) {
      return 0;
    }
    break;
  case 3:
    FUN_00453eb0();
  }
  return 1;
}


