// 00416940 FUN_00416940 [Global]
// program: gamma.dll

void __thiscall
FUN_00416940(void *this,undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_14;
  
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((int)this + 0x14));
  iVar4 = *(int *)((int)this + 0xc);
  if (iVar4 == 0) {
    iVar4 = *(int *)this;
  }
  iVar4 = (iVar4 + -1) * 0x14 + *(int *)((int)this + 4);
  if (((*(int *)((int)this + 0x10) < 1) || (*(int *)(iVar4 + 4) != param_2)) || (1 < param_2 - 6U))
  {
    if (*(int *)((int)this + 0x10) == *(int *)this) {
      iVar1 = FUN_00450b60(*(int *)this * 0x28);
      iVar2 = 0;
      iVar4 = *(int *)((int)this + 8);
      for (local_14 = 0; local_14 < *(int *)((int)this + 0x10); local_14 = local_14 + 1) {
        iVar3 = iVar4 + 1;
        puVar5 = (undefined4 *)(iVar4 * 0x14 + *(int *)((int)this + 4));
        *(undefined4 *)(iVar1 + iVar2) = *puVar5;
        *(undefined4 *)(iVar1 + 4 + iVar2) = puVar5[1];
        *(undefined4 *)(iVar1 + 8 + iVar2) = puVar5[2];
        *(undefined4 *)(iVar1 + 0xc + iVar2) = puVar5[3];
        *(undefined4 *)(iVar1 + 0x10 + iVar2) = puVar5[4];
        if (iVar3 == *(int *)this) {
          iVar3 = 0;
        }
        iVar2 = iVar2 + 0x14;
        iVar4 = iVar3;
      }
      *(int *)this = *(int *)this * 2;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)((int)this + 0xc) = *(undefined4 *)((int)this + 0x10);
      FUN_00451780(*(undefined4 **)((int)this + 4));
      *(int *)((int)this + 4) = iVar1;
    }
    puVar5 = (undefined4 *)(*(int *)((int)this + 0xc) * 0x14 + *(int *)((int)this + 4));
    *puVar5 = param_1;
    puVar5[1] = param_2;
    puVar5[2] = param_3;
    puVar5[3] = param_4;
    puVar5[4] = param_5;
    *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
    if (*(int *)((int)this + 0xc) == *(int *)this) {
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
  }
  else if (param_2 == 6) {
    *(int *)(iVar4 + 0xc) = param_4;
    *(int *)(iVar4 + 0x10) = param_5;
  }
  else {
    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + param_4;
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + param_5;
  }
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)this + 0x14));
  return;
}


