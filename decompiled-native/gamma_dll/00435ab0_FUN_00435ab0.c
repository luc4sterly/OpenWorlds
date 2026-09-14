// 00435ab0 FUN_00435ab0 [Global]
// programa: gamma.dll

int __thiscall FUN_00435ab0(void *this,int param_1,short param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)((int)this + 8);
  if ((param_1 == iVar1) || ((int)param_2 < *(int *)(*(int *)((int)this + 0xc) + param_1 * 0x18))) {
    param_1 = 0;
  }
  if (iVar1 != 0) {
    iVar3 = param_1 * 0x18;
    do {
      iVar2 = param_1;
      iVar3 = iVar3 + 0x18;
      if (iVar2 + 1 == iVar1) {
        return iVar2;
      }
      param_1 = iVar2 + 1;
    } while (*(int *)(*(int *)((int)this + 0xc) + iVar3) <= (int)param_2);
    return iVar2;
  }
  return 0;
}


