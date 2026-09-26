// 1004c84d FUN_1004c84d [Global]
// programa: RWL21.DLL

float10 FUN_1004c84d(void)

{
  int unaff_EBP;
  float10 in_ST0;
  unkbyte10 in_ST1;
  
  *(unkbyte10 *)(unaff_EBP + -0x9e) = in_ST1;
  if ((*(byte *)(unaff_EBP + -0x97) & 0x40) == 0) {
    *(undefined1 *)(unaff_EBP + -0x90) = 1;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x90) = 7;
  }
  return *(float10 *)(unaff_EBP + -0x9e) + in_ST0;
}


