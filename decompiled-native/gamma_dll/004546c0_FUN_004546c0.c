// 004546c0 FUN_004546c0 [Global]
// program: gamma.dll

int * __cdecl FUN_004546c0(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x1017U & 0xfffff000;
  if (uVar2 < 0x10000) {
    uVar2 = 0x10000;
  }
  piVar1 = FUN_00459080(uVar2);
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  FUN_00454290((uint)piVar1,uVar2);
  FUN_00454630(piVar1);
  return piVar1;
}


