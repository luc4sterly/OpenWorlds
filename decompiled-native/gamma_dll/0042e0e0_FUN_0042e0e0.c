// 0042e0e0 FUN_0042e0e0 [Global]
// program: gamma.dll

uint * __thiscall FUN_0042e0e0(void *this,void *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  bool bVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char local_328;
  char local_31c [256];
  undefined **local_21c;
  char acStack_218 [516];
  undefined ***local_14;
  
  puVar7 = (undefined4 *)0x0;
  bVar3 = true;
  local_328 = '\x01';
  puVar1 = (undefined4 *)((int)this + 4);
  puVar2 = *(undefined4 **)((int)this + 4);
  while (puVar2 != (undefined4 *)0x0) {
    bVar3 = FUN_004274e0(param_1,(int)(puVar2 + 3));
    bVar3 = CONCAT31(extraout_var,bVar3) == 0;
    if (bVar3) {
      puVar6 = (undefined4 *)puVar2[1];
      local_328 = '\0';
      puVar7 = puVar2;
    }
    else {
      puVar6 = (undefined4 *)*puVar2;
    }
    bVar3 = !bVar3;
    puVar1 = puVar2;
    puVar2 = puVar6;
  }
  if ((puVar7 != (undefined4 *)0x0) &&
     (bVar4 = FUN_004274e0(puVar7 + 3,(int)param_1), CONCAT31(extraout_var_00,bVar4) == 0)) {
    return puVar7 + 3;
  }
  local_14 = &local_21c;
  local_31c[0] = '\0';
  local_21c = &PTR_LAB_00471ff8;
  FUN_0044d6d0(acStack_218,(char *)((int)param_1 + 4),0xff);
  *(undefined1 *)((int)local_14 + 0x103) = 0;
  local_14[0x41] = &PTR_LAB_00471ff8;
  FUN_0044d6d0((char *)(local_14 + 0x42),local_31c,0xff);
  *(undefined1 *)((int)local_14 + 0x207) = 0;
  puVar5 = FUN_0042eff0(this,puVar1,bVar3,local_328,(int)&local_21c);
  return puVar5 + 3;
}


