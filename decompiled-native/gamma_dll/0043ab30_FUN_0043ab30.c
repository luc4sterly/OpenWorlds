// 0043ab30 FUN_0043ab30 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_0043ab30(int param_1)

{
  float fVar1;
  UINT UVar2;
  float10 fVar3;
  
  UVar2 = GetPrivateProfileIntA
                    (s_Runtime_004767e8,s_NoImpChange_004767dc,0,s___override_ini_004767cc);
  if (UVar2 != 1) {
    fVar3 = ((float10)*(uint *)(param_1 + 0x18) +
            (float10)*(uint *)(param_1 + 0x1c) / (float10)DAT_00472020) /
            ((float10)*(uint *)(param_1 + 0x20) +
            (float10)*(uint *)(param_1 + 0x24) / (float10)DAT_00472020);
    fVar1 = _DAT_004767b4;
    if (((byte)(fVar3 < (float10)_DAT_004767b4 |
               (byte)((ushort)((ushort)(NAN(fVar3) || NAN((float10)_DAT_004767b4)) << 10) >> 8)) ==
         1) || (fVar1 = _DAT_004767b8,
               (byte)((float10)_DAT_004767b8 < fVar3 |
                     (byte)((ushort)((ushort)(NAN((float10)_DAT_004767b8) || NAN(fVar3)) << 10) >> 8
                           )) == 1)) {
      fVar3 = (float10)fVar1;
    }
    fVar3 = (float10)_DAT_004767f0 * fVar3 * ((float10)_DAT_004767b8 - fVar3) *
            (float10)_DAT_004767f4;
    fVar1 = _DAT_004767b4;
    if (((byte)(fVar3 < (float10)_DAT_004767b4 |
               (byte)((ushort)((ushort)(NAN(fVar3) || NAN((float10)_DAT_004767b4)) << 10) >> 8)) ==
         1) || (fVar1 = _DAT_004767b8,
               (byte)((float10)_DAT_004767b8 < fVar3 |
                     (byte)((ushort)((ushort)(NAN((float10)_DAT_004767b8) || NAN(fVar3)) << 10) >> 8
                           )) == 1)) {
      fVar3 = (float10)fVar1;
    }
    return fVar3;
  }
  return (float10)_DAT_004767b8;
}


