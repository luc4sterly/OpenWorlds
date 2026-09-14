// 00424350 FUN_00424350 [Global]
// programa: gamma.dll

void __thiscall FUN_00424350(void *this,undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint *puVar3;
  uint uVar4;
  undefined1 auStack_40 [20];
  undefined1 *local_2c;
  undefined1 *local_14;
  
  puVar3 = FUN_0044e010(0x28);
  *(uint **)this = puVar3;
  uVar4 = param_2 - (int)param_1;
  local_2c = auStack_40;
  iVar1 = *(int *)this;
  puVar2 = auStack_40;
  if (iVar1 != 0) {
    *(uint *)(iVar1 + 4) = (uVar4 + 3) - (uVar4 & 3);
    *(undefined4 *)(iVar1 + 8) = 1;
    local_14 = auStack_40;
    puVar3 = FUN_0044e010(*(int *)(iVar1 + 4) + 1);
    *(uint **)(iVar1 + 0xc) = puVar3;
    InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x10));
    puVar2 = local_2c;
  }
  local_2c = puVar2;
  FUN_0044df50(*(undefined4 **)(*(int *)this + 0xc),param_1,uVar4);
  **(uint **)this = uVar4;
  *(undefined1 *)(*(int *)(*(int *)this + 0xc) + uVar4) = DAT_0047179c;
  return;
}


