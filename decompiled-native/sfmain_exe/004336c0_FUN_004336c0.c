// 004336c0 FUN_004336c0 [Global]
// program: sfmain.exe

void __fastcall FUN_004336c0(undefined4 param_1,undefined8 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte *in_EAX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  undefined8 uVar9;
  
  uVar6 = 0;
  uVar5 = 0;
  while( true ) {
    if (*in_EAX == 0) break;
    bVar7 = CARRY4(uVar5,uVar5);
    uVar1 = uVar5 * 2;
    bVar8 = CARRY4(uVar5 * 4,uVar5);
    uVar3 = uVar5 * 5;
    uVar2 = uVar5 * 10;
    uVar4 = *in_EAX & 0xffffff0f;
    uVar5 = uVar2 + uVar4;
    uVar6 = (uVar6 * 5 + (uint)bVar7 * 2 + (uint)CARRY4(uVar1,uVar1) + (uint)bVar8) * 2 +
            (uint)CARRY4(uVar3,uVar3) + (uint)CARRY4(uVar2,uVar4);
    in_EAX = in_EAX + 1;
  }
  uVar9 = FUN_0043370b(uVar5,uVar6);
  *param_2 = uVar9;
  return;
}


