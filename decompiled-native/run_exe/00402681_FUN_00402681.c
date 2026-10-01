// 00402681 FUN_00402681 [Global]
// program: run.exe

int __cdecl FUN_00402681(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = flsall(0);
    return iVar1;
  }
  iVar1 = FUN_004026bc(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) != 0) {
    iVar1 = FUN_004054bf(param_1[4]);
    return -(uint)(iVar1 != 0);
  }
  return 0;
}


