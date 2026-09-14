// 0041e630 _Java_NET_worlds_scape_ShapeLoader_finishLoadingBinaryFile@16 [Global]
// programa: gamma.dll

int _Java_NET_worlds_scape_ShapeLoader_finishLoadingBinaryFile_16
              (int *param_1,undefined4 param_2,undefined4 *param_3,char param_4)

{
  undefined4 uVar1;
  int iVar2;
  
                    /* 0x1e630  284  _Java_NET_worlds_scape_ShapeLoader_finishLoadingBinaryFile@16
                        */
  iVar2 = 0;
  if (param_4 == '\0') {
    if (param_3[3] == 0) {
      iVar2 = 0;
    }
    else {
      param_3[3] = 0;
      iVar2 = FUN_00419a60(param_3[2]);
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    if (param_3[2] != 0) {
      FUN_00418210(param_3[2]);
    }
    if (param_3[1] != 0) {
      GlobalUnlock((HGLOBAL)*param_3);
    }
    if ((HGLOBAL)*param_3 != (HGLOBAL)0x0) {
      GlobalFree((HGLOBAL)*param_3);
    }
    FUN_0044e100(param_3);
  }
  if (iVar2 == 0) {
    return -1;
  }
  uVar1 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489660);
  (**(code **)(*param_1 + 0x1b4))(param_1,uVar1,DAT_00489664,iVar2);
  return iVar2;
}


