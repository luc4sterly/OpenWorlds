// 100483ec FUN_100483ec [Global]
// program: RWL21.DLL

float10 __fastcall FUN_100483ec(undefined4 param_1)

{
  int unaff_EBP;
  float10 in_ST0;
  float10 in_ST1;
  float10 fVar1;
  
  *(undefined1 *)(unaff_EBP + -0x90) = 0xfe;
  fVar1 = (float10)fpatan(ABS(in_ST1),ABS(in_ST0));
  if ((char)param_1 != '\0') {
    fVar1 = (float10)3.141592653589793 - fVar1;
  }
  if ((char)((uint)param_1 >> 8) != '\0') {
    fVar1 = -fVar1;
  }
  return fVar1;
}


