// 00435ec0 FUN_00435ec0 [Global]
// programa: gamma.dll

void __thiscall FUN_00435ec0(void *this,undefined4 *param_1,undefined4 *param_2)

{
  uint *puVar1;
  undefined4 **ppuVar2;
  undefined4 *puVar3;
  undefined4 *local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  undefined4 *local_44 [6];
  undefined1 *local_2c;
  undefined1 *local_14;
  
  local_44[0] = (undefined4 *)(((int)param_2 - (int)param_1) / 0x18);
  if (*(undefined4 **)this < local_44[0]) {
    FUN_004360b0((int)this);
    if (*(undefined4 **)((int)this + 8) != (undefined4 *)0x0) {
      FUN_0044e100(*(undefined4 **)((int)this + 8));
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)this = 0;
    }
    puVar1 = FUN_0044e010((int)local_44[0] * 0x18);
    *(uint **)((int)this + 8) = puVar1;
    *(undefined4 **)this = local_44[0];
    puVar3 = *(undefined4 **)((int)this + 8);
    for (; param_1 != param_2; param_1 = param_1 + 6) {
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = *param_1;
        local_14 = (undefined1 *)&local_50;
        FUN_00428df0(puVar3 + 1,(int)(param_1 + 1));
      }
      puVar3 = puVar3 + 6;
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
    }
  }
  else {
    if (*(undefined4 **)((int)this + 4) < local_44[0]) {
      ppuVar2 = (undefined4 **)((int)this + 4);
    }
    else {
      ppuVar2 = local_44;
    }
    puVar3 = *(undefined4 **)((int)this + 8);
    local_48 = puVar3 + (int)*ppuVar2 * 6;
    local_4c = puVar3;
    if (puVar3 < local_48) {
      do {
        *puVar3 = *param_1;
        FUN_00428e20(puVar3 + 1,(int)(param_1 + 1));
        puVar3 = puVar3 + 6;
        param_1 = param_1 + 6;
      } while (puVar3 < local_48);
    }
    local_50 = *(undefined4 **)((int)this + 4);
    if (local_44[0] < local_50) {
      local_50 = (undefined4 *)((int)local_50 * 0x18 + *(int *)((int)this + 8));
      if (puVar3 < local_50) {
        do {
          FUN_00428e50(puVar3 + 1);
          puVar3 = puVar3 + 6;
        } while (puVar3 < local_50);
      }
      *(undefined4 **)((int)this + 4) = local_44[0];
    }
    else if (local_50 < local_44[0]) {
      for (; param_1 != param_2; param_1 = param_1 + 6) {
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = *param_1;
          local_2c = (undefined1 *)&local_50;
          FUN_00428df0(puVar3 + 1,(int)(param_1 + 1));
        }
        puVar3 = puVar3 + 6;
        *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
      }
    }
  }
  return;
}


