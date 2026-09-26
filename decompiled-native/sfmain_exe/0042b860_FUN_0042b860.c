// 0042b860 FUN_0042b860 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong __fastcall FUN_0042b860(undefined4 param_1,undefined4 param_2)

{
  float10 fVar1;
  byte bVar2;
  undefined4 in_EAX;
  float10 in_ST0;
  float10 fVar3;
  float10 fVar4;
  undefined8 uVar5;
  
  if ((float10)_DAT_0043e510 < in_ST0) {
    uVar5 = FUN_0042d158(param_1,param_2,(double)in_ST0,4);
    return CONCAT44((int)((ulonglong)uVar5 >> 0x20),CONCAT31((int3)((ulonglong)uVar5 >> 8),1));
  }
  fVar1 = (float10)_DAT_0043e518;
  bVar2 = (byte)((ushort)((ushort)(in_ST0 == fVar1) << 0xe) >> 8);
  if (in_ST0 >= fVar1 && bVar2 == 0) {
    fVar3 = ROUND((float10)1.4426950408889634 * in_ST0);
    fVar4 = (float10)f2xm1((float10)1.4426950408889634 * in_ST0 - fVar3);
    fscale((float10)1 + fVar4,fVar3);
  }
  return (ulonglong)
         CONCAT43(param_2,CONCAT21((short)((uint)in_EAX >> 0x10),
                                   in_ST0 < fVar1 |
                                   (byte)((ushort)((ushort)(NAN(in_ST0) || NAN(fVar1)) << 10) >> 8)
                                   | bVar2)) << 8;
}


