// 100096d0 FUN_100096d0 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100096d0(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  longlong lVar7;
  byte local_b;
  byte local_a;
  byte local_9;
  
  iVar4 = 0;
  do {
    if (DAT_10075234 == 0) {
      fVar6 = (float10)iVar4 * (float10)_DAT_10074098;
    }
    else {
      fVar6 = (float10)fsin((float10)iVar4 * (float10)_DAT_10074080 * (float10)_DAT_10074088 *
                            (float10)_DAT_10074090);
    }
    if (DAT_10075238 <= (float)fVar6) {
      FUN_100089f0();
    }
    else {
      FUN_100089f0();
      lVar7 = __ftol();
      iVar5 = (int)lVar7 + 0x80 >> 8;
      iVar3 = 0x10080 - (int)lVar7 >> 8;
      iVar1 = ((int)((uint)local_9 * 0x100 + 0x80) >> 8) * iVar5 +
              (*DAT_10077da8 + 0x80 >> 8) * iVar3;
      if (0xffff < iVar1) {
        iVar1 = 0xffff;
      }
      iVar2 = ((int)((uint)local_b * 0x100 + 0x80) >> 8) * iVar5 +
              (DAT_10077da8[1] + 0x80 >> 8) * iVar3;
      if (0xffff < iVar2) {
        iVar2 = 0xffff;
      }
      iVar3 = ((int)((uint)local_a * 0x100 + 0x80) >> 8) * iVar5 +
              (DAT_10077da8[2] + 0x80 >> 8) * iVar3;
      if (0xffff < iVar3) {
        iVar3 = 0xffff;
      }
      *param_1 = (char)((uint)iVar1 >> 8);
      param_1[1] = (char)((uint)iVar2 >> 8);
      param_1[2] = (char)((uint)iVar3 >> 8);
    }
    param_1 = param_1 + 3;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x20);
  return;
}


