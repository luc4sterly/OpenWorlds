// 00404e23 FUN_00404e23 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00404e23(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_0040b474 < DAT_00408ec8) {
LAB_00404e39:
    uVar1 = 0;
  }
  else {
    for (iVar2 = 0; iVar2 < (int)(DAT_0040b474 * 4); iVar2 = iVar2 + 4) {
      if (*(int *)(DAT_0040b478 + iVar2) == 0) goto LAB_00404e39;
    }
    uVar1 = 1;
  }
  return CONCAT44(param_2,uVar1);
}


