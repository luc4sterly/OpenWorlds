// 0042b891 FUN_0042b891 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0042b891(void)

{
  int unaff_EBP;
  float10 in_ST0;
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)_DAT_0043e518;
  *(ushort *)(unaff_EBP + -0x10) =
       (ushort)(in_ST0 < fVar1) << 8 | (ushort)(NAN(in_ST0) || NAN(fVar1)) << 10 |
       (ushort)(in_ST0 == fVar1) << 0xe;
  if ((*(byte *)(unaff_EBP + -0xf) & 1) == 0 && (*(byte *)(unaff_EBP + -0xf) & 0x40) == 0) {
    fVar1 = ROUND((float10)1.4426950408889634 * in_ST0);
    fVar2 = (float10)f2xm1((float10)1.4426950408889634 * in_ST0 - fVar1);
    fscale((float10)1 + fVar2,fVar1);
  }
  return 0;
}


