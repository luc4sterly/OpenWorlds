// 1004c822 FUN_1004c822 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_1004c822(void)

{
  int unaff_EBP;
  unkbyte10 in_ST0;
  
  *(unkbyte10 *)(unaff_EBP + -0x9e) = in_ST0;
  if ((*(byte *)(unaff_EBP + -0x97) & 0x40) != 0) {
    *(undefined1 *)(unaff_EBP + -0x90) = 7;
    return *(float10 *)(unaff_EBP + -0x9e);
  }
  *(undefined1 *)(unaff_EBP + -0x90) = 1;
  return *(float10 *)(unaff_EBP + -0x9e) + (float10)_DAT_1005ccd4;
}


