// 0044b180 FUN_0044b180 [Global]
// programa: gamma.dll

uint * __thiscall FUN_0044b180(void *this,uint param_1)

{
  uint *puVar1;
  
  puVar1 = *(uint **)((int)this + 0x14);
  if (puVar1 == (uint *)0x0) {
    puVar1 = FUN_0044e010(0xc);
  }
  else {
    *(uint *)((int)this + 0x14) = puVar1[1];
    *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + -1;
  }
  if (puVar1 != (uint *)0x0) {
    puVar1[2] = param_1;
    puVar1[1] = 0;
    *puVar1 = *(uint *)((int)this + 4);
    if (*(int *)((int)this + 4) == 0) {
      *(uint **)this = puVar1;
    }
    else {
      *(uint **)(*(int *)((int)this + 4) + 4) = puVar1;
    }
    *(uint **)((int)this + 4) = puVar1;
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
    return puVar1;
  }
  return (uint *)0x0;
}


