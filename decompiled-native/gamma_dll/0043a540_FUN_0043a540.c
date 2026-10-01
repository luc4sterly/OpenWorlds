// 0043a540 FUN_0043a540 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_0043a540(int param_1)

{
  float10 fVar1;
  
  fVar1 = ((float10)*(uint *)(param_1 + 0x18) +
          (float10)*(uint *)(param_1 + 0x1c) / (float10)DAT_00472020) /
          ((float10)*(uint *)(param_1 + 0x20) +
          (float10)*(uint *)(param_1 + 0x24) / (float10)DAT_00472020);
  if ((byte)(fVar1 < (float10)_DAT_004767b4 |
            (byte)((ushort)((ushort)(NAN(fVar1) || NAN((float10)_DAT_004767b4)) << 10) >> 8)) == 1)
  {
    fVar1 = (float10)_DAT_004767b4;
  }
  if ((float10)_DAT_004767b8 < fVar1) {
    fVar1 = (float10)_DAT_004767b8;
  }
  return fVar1;
}


