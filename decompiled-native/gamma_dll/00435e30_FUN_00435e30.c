// 00435e30 FUN_00435e30 [Global]
// program: gamma.dll

uint * __thiscall FUN_00435e30(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined1 auStack_28 [20];
  undefined1 *local_14;
  
  puVar2 = (uint *)(((int)param_2 - (int)param_1) * 0x2aaaaaab);
  iVar1 = ((int)param_2 - (int)param_1) / 0x18;
  if (iVar1 != 0) {
    puVar2 = FUN_0044e010(iVar1 * 0x18);
    *(uint **)((int)this + 8) = puVar2;
    *(int *)this = iVar1;
    puVar3 = *(undefined4 **)((int)this + 8);
    for (; param_1 != param_2; param_1 = param_1 + 6) {
      puVar2 = (uint *)0x0;
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = *param_1;
        local_14 = auStack_28;
        puVar2 = (uint *)FUN_00428df0(puVar3 + 1,(int)(param_1 + 1));
      }
      puVar3 = puVar3 + 6;
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
    }
  }
  return puVar2;
}


