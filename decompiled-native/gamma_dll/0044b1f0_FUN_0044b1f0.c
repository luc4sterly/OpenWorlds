// 0044b1f0 FUN_0044b1f0 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_0044b1f0(void *this,int *param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar1 = *param_1;
  do {
    if (iVar1 == 0) {
      return 1;
    }
    if (iVar1 == 0) {
      uVar2 = 0;
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar1 + 4);
      uVar2 = *(uint *)(iVar1 + 8);
    }
    puVar3 = FUN_0044b180(this,uVar2);
    iVar1 = iVar4;
  } while (puVar3 != (uint *)0x0);
  return 0;
}


