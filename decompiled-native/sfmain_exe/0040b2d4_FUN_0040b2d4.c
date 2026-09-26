// 0040b2d4 FUN_0040b2d4 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040b2d4(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  
  pfVar1 = in_EAX + 0xb4;
  fVar2 = (float)_DAT_004358b0;
  do {
    fVar6 = _DAT_004386f0;
    fVar5 = _DAT_004386e8;
    fVar3 = (_DAT_004386e8 * (float)_DAT_004358a0 + *in_EAX) - _DAT_004386ec * (float)_DAT_004358a8;
    fVar4 = (_DAT_004386f0 * (float)_DAT_004358b8 + (fVar3 - _DAT_004386e8 * fVar2) + _DAT_004386ec)
            - _DAT_004386f4 * (float)_DAT_004358c0;
    _DAT_004386e8 = fVar3;
    *in_EAX = ((fVar4 - _DAT_004386f0 * fVar2) + _DAT_004386f4) * (float)_DAT_004358c8;
    in_EAX = in_EAX + 1;
    _DAT_004386f0 = fVar4;
    _DAT_004386f4 = fVar6;
    _DAT_004386ec = fVar5;
  } while (in_EAX != pfVar1);
  return;
}


