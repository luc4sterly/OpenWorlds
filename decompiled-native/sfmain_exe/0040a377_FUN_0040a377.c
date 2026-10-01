// 0040a377 FUN_0040a377 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040a377(undefined4 param_1,int param_2)

{
  float fVar1;
  int in_EAX;
  int *unaff_EBX;
  float *pfVar2;
  int iVar3;
  uint uStack_24;
  int local_14;
  
  if (DAT_004385a0 != 0) {
    DAT_004401b0 = DAT_004401b0 + -0xb4;
  }
  pfVar2 = (float *)(in_EAX + 0x874);
  iVar3 = 0x21d;
  local_14 = 0x214;
  do {
    _DAT_00438588 =
         (_DAT_00438588 * (float)_DAT_00435858 + *pfVar2 * pfVar2[-1]) * (float)_DAT_00435860;
    _DAT_0043858c =
         (float)_DAT_00435860 * (pfVar2[-1] * pfVar2[-1] + _DAT_0043858c * (float)_DAT_00435858);
    if (ABS(_DAT_0043858c) != 0.0) {
      if (ABS(_DAT_00438588) <= _DAT_0043858c) {
        _DAT_004401f4 = _DAT_00438588 / _DAT_0043858c;
      }
      else {
        if (0.0 <= _DAT_00438588) {
          uStack_24 = 0x3ff00000;
        }
        else {
          uStack_24 = 0xbff00000;
        }
        _DAT_004401f4 = (float)(double)((ulonglong)uStack_24 << 0x20);
      }
    }
    fVar1 = _DAT_004401f4;
    _DAT_00438594 = (float)(&DAT_004401b0)[DAT_00438598];
    _DAT_00438590 = (_DAT_00438590 - (float)(&DAT_004401b0)[DAT_0043859c]) + _DAT_004401f4;
    (&DAT_004401b0)[DAT_0043859c] = (int)_DAT_00438590;
    (&DAT_004401b0)[DAT_00438598] = (int)fVar1;
    DAT_00438598 = DAT_00438598 % 0x10 + 1;
    DAT_0043859c = DAT_0043859c % 0x10 + 1;
    if (ABS(_DAT_00438590 - _DAT_00438594) <= 1.7) {
      if ((DAT_004385a0 != 0) && (9 < iVar3 - DAT_004401b0)) {
        DAT_004385a0 = 0;
      }
    }
    else {
      DAT_004401b0 = iVar3;
      if (DAT_004385a0 == 0) {
        if (*unaff_EBX < 0xb) {
          *(int *)(*unaff_EBX * 4 + param_2) = local_14;
          *unaff_EBX = *unaff_EBX + 1;
        }
        DAT_004385a0 = 1;
      }
    }
    pfVar2 = pfVar2 + 1;
    local_14 = local_14 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x2d1);
  return;
}


