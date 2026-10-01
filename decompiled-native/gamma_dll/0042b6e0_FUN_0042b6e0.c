// 0042b6e0 FUN_0042b6e0 [Global]
// program: gamma.dll

void __thiscall FUN_0042b6e0(void *this,undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  bool bVar5;
  undefined4 *puVar6;
  char local_18;
  
  puVar6 = (undefined4 *)0x0;
  bVar5 = true;
  local_18 = '\x01';
  puVar1 = (undefined4 *)((int)this + 4);
  puVar2 = *(undefined4 **)((int)this + 4);
  while (puVar2 != (undefined4 *)0x0) {
    if ((int)puVar2[3] <= (int)*param_2) {
      puVar3 = (undefined4 *)puVar2[1];
      local_18 = '\0';
      puVar6 = puVar2;
    }
    else {
      puVar3 = (undefined4 *)*puVar2;
    }
    bVar5 = (int)puVar2[3] > (int)*param_2;
    puVar1 = puVar2;
    puVar2 = puVar3;
  }
  if ((puVar6 != (undefined4 *)0x0) && ((int)*param_2 <= (int)puVar6[3])) {
    *param_1 = puVar6;
    *(undefined1 *)(param_1 + 1) = DAT_00474744;
    return;
  }
  puVar4 = FUN_0042b5f0(this,puVar1,bVar5,local_18,param_2);
  *param_1 = puVar4;
  *(undefined1 *)(param_1 + 1) = DAT_00474740;
  return;
}


