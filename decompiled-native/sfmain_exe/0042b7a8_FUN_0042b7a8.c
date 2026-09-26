// 0042b7a8 FUN_0042b7a8 [Global]
// programa: sfmain.exe

/* WARNING: Removing unreachable block (ram,0x0042b7c8) */

undefined8 __fastcall FUN_0042b7a8(undefined4 param_1,undefined4 param_2)

{
  float10 fVar1;
  undefined4 in_EAX;
  undefined4 uVar2;
  float10 in_ST0;
  undefined8 uVar3;
  
  fVar1 = (float10)0;
  LOCK();
  uVar2 = CONCAT22((short)((uint)in_EAX >> 0x10),
                   (ushort)(in_ST0 < fVar1) << 8 | (ushort)(NAN(in_ST0) || NAN(fVar1)) << 10 |
                   (ushort)(in_ST0 == fVar1) << 0xe);
  UNLOCK();
  if (in_ST0 < fVar1) {
    uVar3 = FUN_0042d158(param_1,param_2,(double)in_ST0,3);
    param_2 = (undefined4)((ulonglong)uVar3 >> 0x20);
    uVar2 = CONCAT31((int3)((ulonglong)uVar3 >> 8),1);
  }
  return CONCAT44(param_2,uVar2);
}


