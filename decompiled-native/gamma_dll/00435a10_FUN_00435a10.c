// 00435a10 FUN_00435a10 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00435a10(void *this,undefined4 *param_1,short param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00435ab0(this,*(int *)((int)this + 0x118),param_2);
  *(int *)((int)this + 0x118) = iVar1;
  iVar1 = *(int *)((int)this + 0x118);
  if (iVar1 == *(int *)((int)this + 8)) {
    puVar2 = (undefined4 *)FUN_00428f10(param_1);
    return puVar2;
  }
  if ((iVar1 != *(int *)((int)this + 8) + -1) &&
     ((int)param_2 != *(int *)(*(int *)((int)this + 0xc) + iVar1 * 0x18))) {
    FUN_00435b20(this,param_1,param_2,iVar1,iVar1 + 1);
    return param_1;
  }
  FUN_00428df0(param_1,iVar1 * 0x18 + *(int *)((int)this + 0xc) + 4);
  return param_1;
}


