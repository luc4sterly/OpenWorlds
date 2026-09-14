// 00454710 FUN_00454710 [Global]
// programa: gamma.dll

uint * __cdecl FUN_00454710(int param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0xfU & 0xfffffff8;
  if (uVar3 < 0x50) {
    uVar3 = 0x50;
  }
  piVar2 = DAT_0049e768;
  if (DAT_0049e768 == (int *)0x0) {
    piVar2 = FUN_004546c0(uVar3);
  }
  if (piVar2 == (int *)0x0) {
    return (uint *)0x0;
  }
  do {
    if ((uVar3 <= (uint)piVar2[2]) &&
       (puVar1 = FUN_004542f0((int)piVar2,uVar3), puVar1 != (uint *)0x0)) goto LAB_00454789;
    piVar2 = (int *)piVar2[1];
  } while (piVar2 != DAT_0049e768);
  piVar2 = FUN_004546c0(uVar3);
  if (piVar2 == (int *)0x0) {
    return (uint *)0x0;
  }
  puVar1 = FUN_004542f0((int)piVar2,uVar3);
  piVar2 = DAT_0049e768;
LAB_00454789:
  DAT_0049e768 = piVar2;
  return puVar1 + 2;
}


