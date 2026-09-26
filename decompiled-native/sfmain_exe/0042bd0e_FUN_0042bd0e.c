// 0042bd0e FUN_0042bd0e [Global]
// programa: sfmain.exe

/* WARNING: Removing unreachable block (ram,0x0042bd41) */
/* WARNING: Removing unreachable block (ram,0x0042bd39) */

bool FUN_0042bd0e(void)

{
  float10 fVar1;
  ushort uVar2;
  undefined4 in_EAX;
  undefined4 in_ECX;
  undefined4 in_EDX;
  bool bVar3;
  bool bVar4;
  float10 in_ST0;
  
  fVar1 = (float10)0;
  uVar2 = CONCAT11(in_ST0 < fVar1 | (byte)((ushort)((ushort)(NAN(in_ST0) || NAN(fVar1)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(in_ST0 == fVar1) << 0xe) >> 8),10);
  bVar4 = (uVar2 & 0x4000) == 0;
  bVar3 = (uVar2 & 0x100) == 0;
  if (bVar3 && bVar4) {
    log2(in_ST0);
  }
  else {
    FUN_0042e160(in_ECX,in_EDX,SUB84((double)in_ST0,0),(int)((ulonglong)(double)in_ST0 >> 0x20),
                 CONCAT22((short)((uint)in_EAX >> 0x10),uVar2));
  }
  return !bVar3 || !bVar4;
}


