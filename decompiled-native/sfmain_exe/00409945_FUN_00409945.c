// 00409945 FUN_00409945 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00409945(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = in_EAX;
  do {
    if ((float)_DAT_00435814 < ABS(*(float *)(iVar1 + 8))) break;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0xc;
  } while (iVar2 < 10);
  if ((iVar2 < 10) && ((float)_DAT_00435814 < ABS(*(float *)(in_EAX + 8 + iVar2 * 0xc)))) {
    iVar1 = in_EAX;
    do {
      iVar2 = iVar1 + 0xc;
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 4);
      iVar1 = iVar2;
    } while (iVar2 != in_EAX + 0x78);
  }
  return;
}


