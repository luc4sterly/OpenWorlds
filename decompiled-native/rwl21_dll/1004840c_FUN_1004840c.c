// 1004840c FUN_1004840c [Global]
// program: RWL21.DLL

undefined1  [10] FUN_1004840c(void)

{
  float10 fVar1;
  int unaff_EBP;
  float10 in_ST0;
  undefined1 auVar2 [10];
  float10 fVar3;
  
  fVar3 = ((float10)1 + ABS(in_ST0)) * ((float10)1 - ABS(in_ST0));
  fVar1 = (float10)0;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)(fVar3 < fVar1) << 8 | (ushort)(NAN(fVar3) || NAN(fVar1)) << 10 |
       (ushort)(fVar3 == fVar1) << 0xe;
  if ((*(byte *)(unaff_EBP + -0x9f) & 1) == 0) {
    return (undefined1  [10])SQRT(fVar3);
  }
  auVar2 = FUN_1004c8b6();
  return auVar2;
}


