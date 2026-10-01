// 0042d0b4 FUN_0042d0b4 [Global]
// program: sfmain.exe

byte * __fastcall FUN_0042d0b4(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  byte *in_EAX;
  int iVar2;
  undefined4 extraout_ECX;
  byte *pbVar3;
  undefined8 uVar4;
  byte abStack_28 [32];
  undefined4 uStack_8;
  
  uStack_8 = param_1;
  if (in_EAX == (byte *)0x0) {
    uVar4 = (*(code *)PTR_FUN_0043e7ec)();
    param_2 = (undefined4)((ulonglong)uVar4 >> 0x20);
    in_EAX = *(byte **)((int)uVar4 + 0x10);
    param_1 = extraout_ECX;
    if (in_EAX == (byte *)0x0) {
      return (byte *)0x0;
    }
  }
  FUN_00430e90(param_1,param_2);
  while ((bVar1 = *in_EAX, bVar1 != 0 &&
         ((abStack_28[bVar1 >> 3] & (&DAT_00437d18)[bVar1 & 7]) != 0))) {
    in_EAX = in_EAX + 1;
  }
  pbVar3 = in_EAX;
  if (bVar1 == 0) {
    return (byte *)0x0;
  }
  while( true ) {
    bVar1 = *pbVar3;
    if (bVar1 == 0) {
      iVar2 = (*(code *)PTR_FUN_0043e7ec)();
      *(undefined4 *)(iVar2 + 0x10) = 0;
      return in_EAX;
    }
    if ((abStack_28[bVar1 >> 3] & (&DAT_00437d18)[bVar1 & 7]) != 0) break;
    pbVar3 = pbVar3 + 1;
  }
  *pbVar3 = 0;
  uVar4 = (*(code *)PTR_FUN_0043e7ec)();
  *(int *)((int)uVar4 + 0x10) = (int)((ulonglong)uVar4 >> 0x20);
  return in_EAX;
}


