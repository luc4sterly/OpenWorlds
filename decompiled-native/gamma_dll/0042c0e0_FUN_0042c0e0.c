// 0042c0e0 FUN_0042c0e0 [Global]
// programa: gamma.dll

int * __thiscall FUN_0042c0e0(void *this,int param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined **local_38;
  int local_34;
  int *local_2c;
  undefined1 *local_14;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  iVar4 = *(int *)(param_1 + 8);
  local_34 = *(int *)(param_1 + 4) * 0x104 + iVar4;
  iVar1 = (local_34 - iVar4) / 0x104;
  local_2c = this;
  if (iVar1 != 0) {
    puVar2 = FUN_0044e010(iVar1 * 0x104);
    local_2c[2] = (int)puVar2;
    *local_2c = iVar1;
    puVar3 = (undefined4 *)local_2c[2];
    if (iVar4 != local_34) {
      local_38 = &PTR_LAB_00471ff8;
      do {
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = local_38;
          local_14 = (undefined1 *)&local_38;
          FUN_0044d6d0((char *)(puVar3 + 1),(char *)(iVar4 + 4),0xff);
          *(undefined1 *)((int)puVar3 + 0x103) = 0;
        }
        iVar4 = iVar4 + 0x104;
        local_2c[1] = local_2c[1] + 1;
        puVar3 = puVar3 + 0x41;
      } while (iVar4 != local_34);
    }
  }
  return local_2c;
}


