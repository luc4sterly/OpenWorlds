// 0042ebd0 FUN_0042ebd0 [Global]
// program: gamma.dll

void __thiscall FUN_0042ebd0(void *this,int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint *local_48;
  uint local_44 [6];
  undefined1 *local_2c;
  undefined1 *local_14;
  
  local_44[0] = (param_2 - param_1) / 0x104;
  local_48 = this;
  if (*(uint *)this < local_44[0]) {
    puVar4 = *(undefined4 **)((int)this + 8);
    puVar5 = puVar4 + *(int *)((int)this + 4) * 0x41;
    while (puVar4 < puVar5) {
      puVar5 = puVar5 + -0x41;
      (**(code **)*puVar5)(0);
    }
    local_48[1] = 0;
    if ((undefined4 *)local_48[2] != (undefined4 *)0x0) {
      FUN_0044e100((undefined4 *)local_48[2]);
      local_48[2] = 0;
      *local_48 = 0;
    }
    puVar3 = FUN_0044e010(local_44[0] * 0x104);
    local_48[2] = (uint)puVar3;
    *local_48 = local_44[0];
    puVar4 = (undefined4 *)local_48[2];
    for (; param_1 != param_2; param_1 = param_1 + 0x104) {
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = &PTR_LAB_00471ff8;
        local_14 = (undefined1 *)&local_48;
        FUN_0044d6d0((char *)(puVar4 + 1),(char *)(param_1 + 4),0xff);
        *(undefined1 *)((int)puVar4 + 0x103) = 0;
      }
      local_48[1] = local_48[1] + 1;
      puVar4 = puVar4 + 0x41;
    }
  }
  else {
    if (*(uint *)((int)this + 4) < local_44[0]) {
      puVar3 = (uint *)((int)this + 4);
    }
    else {
      puVar3 = local_44;
    }
    puVar4 = *(undefined4 **)((int)this + 8);
    puVar5 = puVar4 + *puVar3 * 0x41;
    for (; puVar4 < puVar5; puVar4 = puVar4 + 0x41) {
      FUN_0044d6d0((char *)(puVar4 + 1),(char *)(param_1 + 4),0xff);
      *(undefined1 *)((int)puVar4 + 0x103) = 0;
      param_1 = param_1 + 0x104;
    }
    uVar1 = local_48[1];
    if (local_44[0] < uVar1) {
      uVar2 = local_48[2];
      for (; puVar4 < (undefined4 *)(uVar1 * 0x104 + uVar2); puVar4 = puVar4 + 0x41) {
        (**(code **)*puVar4)(0);
      }
      local_48[1] = local_44[0];
    }
    else if (uVar1 < local_44[0]) {
      for (; param_1 != param_2; param_1 = param_1 + 0x104) {
        if (puVar4 != (undefined4 *)0x0) {
          *puVar4 = &PTR_LAB_00471ff8;
          local_2c = (undefined1 *)&local_48;
          FUN_0044d6d0((char *)(puVar4 + 1),(char *)(param_1 + 4),0xff);
          *(undefined1 *)((int)puVar4 + 0x103) = 0;
        }
        local_48[1] = local_48[1] + 1;
        puVar4 = puVar4 + 0x41;
      }
    }
  }
  return;
}


