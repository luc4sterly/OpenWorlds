// 0040999a FUN_0040999a [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_0040999a(undefined4 param_1,undefined4 param_2)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = DAT_00438572;
  psVar1 = (short *)(DAT_00438572 * 2 + 0x438564);
  *psVar1 = *psVar1 + *(short *)(DAT_0043856e * 2 + 0x438564);
  DAT_00438572 = DAT_00438572 + -1;
  if (DAT_00438572 < 0) {
    DAT_00438572 = 4;
  }
  DAT_0043856e = DAT_0043856e + -1;
  if (DAT_0043856e < 0) {
    DAT_0043856e = 4;
  }
  return CONCAT44(param_2,*(int *)(iVar2 * 2 + 0x438562) >> 0x10);
}


