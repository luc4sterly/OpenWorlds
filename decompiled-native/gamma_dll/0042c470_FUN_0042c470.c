// 0042c470 FUN_0042c470 [Global]
// program: gamma.dll

uint * FUN_0042c470(int *param_1)

{
  undefined ***pppuVar1;
  uint *puVar2;
  uint *puVar3;
  undefined **local_48 [6];
  undefined1 *local_30;
  undefined1 *local_18;
  uint *local_14;
  
  puVar2 = FUN_0044e010(0x214);
  local_30 = (undefined1 *)local_48;
  puVar2[1] = 0;
  *puVar2 = puVar2[1];
  pppuVar1 = local_48;
  if ((int *)*param_1 != (int *)0x0) {
    puVar3 = FUN_0042c470((int *)*param_1);
    *puVar2 = (uint)puVar3;
    *(uint *)(*puVar2 + 8) = *(uint *)(*puVar2 + 8) & 1 | (uint)puVar2;
    pppuVar1 = (undefined ***)local_30;
  }
  local_30 = (undefined1 *)pppuVar1;
  if ((int *)param_1[1] != (int *)0x0) {
    puVar3 = FUN_0042c470((int *)param_1[1]);
    puVar2[1] = (uint)puVar3;
    *(uint *)(puVar2[1] + 8) = *(uint *)(puVar2[1] + 8) & 1 | (uint)puVar2;
  }
  local_18 = (undefined1 *)local_48;
  local_14 = puVar2 + 3;
  if (local_14 != (uint *)0x0) {
    local_48[0] = &PTR_LAB_00471ff8;
    *local_14 = (uint)&PTR_LAB_00471ff8;
    FUN_0044d6d0((char *)(puVar2 + 4),(char *)(param_1 + 4),0xff);
    *(undefined1 *)((int)local_14 + 0x103) = 0;
    local_14[0x41] = (uint)local_48[0];
    FUN_0044d6d0((char *)(local_14 + 0x42),(char *)(param_1 + 0x45),0xff);
    *(undefined1 *)((int)local_14 + 0x207) = 0;
  }
  if ((param_1[2] & 1U) == 0) {
    puVar2[2] = puVar2[2] & 0xfffffffe;
  }
  else {
    puVar2[2] = puVar2[2] | 1;
  }
  return puVar2;
}


