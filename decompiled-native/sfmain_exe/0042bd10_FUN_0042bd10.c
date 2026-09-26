// 0042bd10 FUN_0042bd10 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0042bd10(undefined4 param_1,undefined4 param_2)

{
  float10 fVar1;
  byte bVar2;
  undefined4 in_EAX;
  uint uVar3;
  float10 in_ST0;
  undefined8 uVar4;
  
  fVar1 = (float10)0;
  bVar2 = (byte)((ushort)((ushort)(in_ST0 == fVar1) << 0xe) >> 8);
  uVar3 = CONCAT22((short)((uint)in_EAX >> 0x10),
                   CONCAT11(in_ST0 < fVar1 |
                            (byte)((ushort)((ushort)(NAN(in_ST0) || NAN(fVar1)) << 10) >> 8) | bVar2
                            ,(char)in_EAX));
  if (in_ST0 < fVar1 || bVar2 != 0) {
    uVar4 = FUN_0042e160(param_1,param_2,SUB84((double)in_ST0,0),
                         (int)((ulonglong)(double)in_ST0 >> 0x20),uVar3);
    param_2 = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar3 = CONCAT31((int3)((ulonglong)uVar4 >> 8),1);
  }
  else {
    log2(in_ST0);
    uVar3 = uVar3 & 0xffffff00;
  }
  return CONCAT44(param_2,uVar3);
}


