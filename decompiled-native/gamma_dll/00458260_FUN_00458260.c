// 00458260 FUN_00458260 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00458260(void)

{
  uint in_EAX;
  uint uVar1;
  float10 in_ST0;
  float10 fVar2;
  
  if ((int)in_EAX < 0) {
    DAT_0049eb70 = DAT_0049eb70 ^ 1;
    in_EAX = -in_EAX;
  }
  uVar1 = in_EAX;
  fVar2 = (float10)1;
  if ((0x1f < (int)in_EAX) &&
     (uVar1 = in_EAX & 0x1f, fVar2 = _DAT_00482ff6, (int)(in_EAX & 0xffffffe0) < 400)) {
    fVar2 = *(float10 *)(PTR_DAT_00483008 + ((in_EAX >> 5) - 1) * 10);
  }
  if (DAT_0049eb70 == 0) {
    fVar2 = *(float10 *)(PTR_DAT_00483004 + uVar1 * 10) * fVar2 * in_ST0;
  }
  else {
    fVar2 = in_ST0 / (*(float10 *)(PTR_DAT_00483004 + uVar1 * 10) * fVar2);
  }
  return fVar2;
}


