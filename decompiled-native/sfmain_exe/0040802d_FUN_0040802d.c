// 0040802d FUN_0040802d [Global]
// programa: sfmain.exe

int __fastcall FUN_0040802d(undefined4 param_1,short param_2)

{
  short in_AX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = (int)in_AX;
  iVar1 = 0xf;
  if ((in_AX < 0) || (param_2 < in_AX)) {
    FUN_0042b978();
  }
  if (in_AX == 0) {
    iVar3 = 0;
  }
  else {
    while (iVar1 = iVar1 + -1, iVar1 != -1) {
      iVar2 = iVar2 * 2;
      iVar3 = iVar3 * 2;
      if (param_2 <= iVar2) {
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 - param_2;
      }
    }
  }
  return iVar3;
}


